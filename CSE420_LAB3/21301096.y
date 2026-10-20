%{
#include "symbol_table.h"

#define YYSTYPE symbol_info*

extern FILE *yyin;
int yyparse(void);
int yylex(void);

int lines = 1;
int error_count = 0;
ofstream outlog;
ofstream outerror;
symbol_table *table = nullptr;

vector<parameter_record> pending_function_parameters;
bool function_scope_pending = false;

symbol_info *make_node(const string &text, const string &type)
{
    return new symbol_info(text, type);
}

void report_error(const string &msg)
{
    outlog << "At line no: " << lines << " " << msg << '\n' << '\n';
    outerror << "At line no: " << lines << " " << msg << '\n' << '\n';
    error_count++;
}

void log_rule(const string &rule, const string &text)
{
    (void)rule;
    (void)text;
}

void log_insertion(symbol_info *symbol)
{
    if (table->insert(symbol))
    {
        outlog << "Inserted '" << symbol->get_name()
               << "' in ScopeTable # " << table->get_current_scope_id()
               << '\n' << '\n';
    }
    else
    {
        report_error("Duplicate symbol '" + symbol->get_name() +
                     "' in ScopeTable # " + to_string(table->get_current_scope_id()) +
                     ". Insertion failed.");
        delete symbol;
    }
}

void insert_function_symbol(const string &name,
                            const string &return_type,
                            const vector<parameter_record> &parameters)
{
    symbol_info *function_symbol = new symbol_info(name, "ID");
    function_symbol->set_as_function(return_type, parameters);
    log_insertion(function_symbol);
}

void begin_compound_scope()
{
    table->enter_scope();
    outlog << "New ScopeTable with id " << table->get_current_scope_id()
           << " created" << '\n' << '\n';

    if (function_scope_pending)
    {
        for (const parameter_record &parameter : pending_function_parameters)
        {
            // An unnamed parameter contributes to the function signature but
            // does not introduce an identifier in the function body.
            if (parameter.name.empty()) continue;

            symbol_info *parameter_symbol = new symbol_info(parameter.name, "ID");
            parameter_symbol->set_as_variable(parameter.data_type);
            log_insertion(parameter_symbol);
        }

        pending_function_parameters.clear();
        function_scope_pending = false;
    }
}

void finish_compound_scope()
{
    int removed_scope_id = table->get_current_scope_id();

    outlog << "Current state of the symbol table before exiting scope "
           << removed_scope_id << ':' << '\n' << '\n';
    table->print_all_scopes(outlog);

    table->exit_scope();
    outlog << "ScopeTable with id " << removed_scope_id
           << " removed from the scope stack" << '\n' << '\n';
}

void yyerror(const char *message)
{
    report_error(string(message));
    pending_function_parameters.clear();
    function_scope_pending = false;
}
%}

%token IF ELSE FOR WHILE DO BREAK INT CHAR FLOAT DOUBLE VOID RETURN SWITCH CASE DEFAULT CONTINUE PRINTLN
%token ADDOP MULOP INCOP DECOP RELOP ASSIGNOP LOGICOP NOT
%token LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON
%token CONST_INT CONST_FLOAT ID

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

start : program
    {
        outlog << "Symbol Table" << '\n' << '\n';
        table->print_all_scopes(outlog);
        $$ = make_node($1->get_name(), "start");
    }
    ;

program : program unit
    {
        string text = $1->get_name() + "\n" + $2->get_name();
        $$ = make_node(text, "program");
    }
    | unit
    {
        $$ = make_node($1->get_name(), "program");
    }
    ;

unit : variable_decl
    {
        $$ = make_node($1->get_name(), "unit");
    }
    | func_definition
    {
        $$ = make_node($1->get_name(), "unit");
    }
    ;

func_definition : type_specifier ID LPAREN param_list RPAREN
    {
        insert_function_symbol($2->get_name(),
                               $1->get_name(),
                               $4->get_parameters());
        pending_function_parameters = $4->get_parameters();
        function_scope_pending = true;
    }
    compound_statement
    {
        string text = $1->get_name() + " " + $2->get_name() + "(" +
                      $4->get_name() + ")\n" + $7->get_name();
        $$ = make_node(text, "func_def");
    }
    | type_specifier ID LPAREN RPAREN
    {
        vector<parameter_record> no_parameters;
        insert_function_symbol($2->get_name(), $1->get_name(), no_parameters);
        pending_function_parameters.clear();
        function_scope_pending = true;
    }
    compound_statement
    {
        string text = $1->get_name() + " " + $2->get_name() + "()\n" +
                      $6->get_name();
        $$ = make_node(text, "func_def");
    }
    ;

param_list : param_list COMMA type_specifier ID
    {
        string text = $1->get_name() + "," + $3->get_name() + " " + $4->get_name();
        $$ = make_node(text, "param_list");
        $$->set_parameters($1->get_parameters());
        $$->add_parameter(parameter_record($3->get_name(), $4->get_name()));
    }
    | param_list COMMA type_specifier
    {
        string text = $1->get_name() + "," + $3->get_name();
        $$ = make_node(text, "param_list");
        $$->set_parameters($1->get_parameters());
        $$->add_parameter(parameter_record($3->get_name(), ""));
    }
    | type_specifier ID
    {
        string text = $1->get_name() + " " + $2->get_name();
        $$ = make_node(text, "param_list");
        $$->add_parameter(parameter_record($1->get_name(), $2->get_name()));
    }
    | type_specifier
    {
        $$ = make_node($1->get_name(), "param_list");
        $$->add_parameter(parameter_record($1->get_name(), ""));
    }
    ;

compound_statement : LCURL
    {
        begin_compound_scope();
    }
    statements RCURL
    {
        string text = "{\n" + $3->get_name() + "\n}";
        $$ = make_node(text, "comp_stmnt");
        finish_compound_scope();
    }
    | LCURL
    {
        begin_compound_scope();
    }
    RCURL
    {
        string text = "{\n}";
        $$ = make_node(text, "comp_stmnt");
        finish_compound_scope();
    }
    ;

variable_decl : type_specifier declaration_list SEMICOLON
    {
        string text = $1->get_name() + " " + $2->get_name() + ";";
        $$ = make_node(text, "var_dec");

        if ($1->get_name() == "void") {
            report_error("variable type can not be void");
        }

        for (const declaration_record &declaration : $2->get_declarations())
        {
            symbol_info *declared_symbol = new symbol_info(declaration.name, "ID");

            if (declaration.is_array)
                declared_symbol->set_as_array($1->get_name(), declaration.array_size);
            else
                declared_symbol->set_as_variable($1->get_name());

            log_insertion(declared_symbol);
        }
    }
    ;

type_specifier : INT
    {
        $$ = make_node("int", "type");
    }
    | FLOAT
    {
        $$ = make_node("float", "type");
    }
    | VOID
    {
        $$ = make_node("void", "type");
    }
    | CHAR
    {
        $$ = make_node("char", "type");
    }
    ;

declaration_list : declaration_list COMMA ID
    {
        string text = $1->get_name() + "," + $3->get_name();
        $$ = make_node(text, "declaration_list");
        $$->set_declarations($1->get_declarations());
        $$->add_declaration(declaration_record($3->get_name(), false, 0));
    }
    | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
    {
        string text = $1->get_name() + "," + $3->get_name() + "[" +
                      $5->get_name() + "]";
        $$ = make_node(text, "declaration_list");
        $$->set_declarations($1->get_declarations());
        $$->add_declaration(declaration_record($3->get_name(), true,
                                               stoi($5->get_name())));
    }
    | ID
    {
        $$ = make_node($1->get_name(), "declaration_list");
        $$->add_declaration(declaration_record($1->get_name(), false, 0));
    }
    | ID LTHIRD CONST_INT RTHIRD
    {
        string text = $1->get_name() + "[" + $3->get_name() + "]";
        $$ = make_node(text, "declaration_list");
        $$->add_declaration(declaration_record($1->get_name(), true,
                                               stoi($3->get_name())));
    }
    ;

statements : statement
    {
        $$ = make_node($1->get_name(), "stmnts");
    }
    | statements statement
    {
        string text = $1->get_name() + "\n" + $2->get_name();
        $$ = make_node(text, "stmnts");
    }
    ;

statement : variable_decl
    {
        $$ = make_node($1->get_name(), "stmnt");
    }
    | expression_statement
    {
        $$ = make_node($1->get_name(), "stmnt");
    }
    | compound_statement
    {
        $$ = make_node($1->get_name(), "stmnt");
    }
    | FOR LPAREN expression_statement expression_statement expression RPAREN statement
    {
        string text = "for(" + $3->get_name() + $4->get_name() +
                      $5->get_name() + ")\n" + $7->get_name();
        $$ = make_node(text, "stmnt");
    }
    | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE
    {
        string text = "if(" + $3->get_name() + ")\n" + $5->get_name();
        $$ = make_node(text, "stmnt");
    }
    | IF LPAREN expression RPAREN statement ELSE statement
    {
        string text = "if(" + $3->get_name() + ")\n" + $5->get_name() +
                      "\nelse\n" + $7->get_name();
        $$ = make_node(text, "stmnt");
    }
    | WHILE LPAREN expression RPAREN statement
    {
        string text = "while(" + $3->get_name() + ")\n" + $5->get_name();
        $$ = make_node(text, "stmnt");
    }
    | PRINTLN LPAREN ID RPAREN SEMICOLON
    {
        string text = "printf(" + $3->get_name() + ");";
        $$ = make_node(text, "stmnt");
    }
    | RETURN expression SEMICOLON
    {
        string text = "return " + $2->get_name() + ";";
        $$ = make_node(text, "stmnt");
    }
    ;

expression_statement : SEMICOLON
    {
        $$ = make_node(";", "expr_stmt");
    }
    | expression SEMICOLON
    {
        string text = $1->get_name() + ";";
        $$ = make_node(text, "expr_stmt");
    }
    ;

variable : ID
    {
        $$ = make_node($1->get_name(), "varbl");
        symbol_info *info = table->lookup($1->get_name());
        if (info == nullptr) {
            report_error("Undeclared variable " + $1->get_name());
        } else if (info->get_symbol_kind() == "ARRAY") {
            report_error("variable is of array type : " + $1->get_name());
        }
    }
    | ID LTHIRD expression RTHIRD
    {
        string text = $1->get_name() + "[" + $3->get_name() + "]";
        $$ = make_node(text, "varbl");
        if ($3->get_name().empty() == false && $3->get_data_type() != "int") {
            report_error("array index is not of integer type : " + $1->get_name());
        }
        symbol_info *info = table->lookup($1->get_name());
        if (info == nullptr) {
            report_error("Undeclared variable " + $1->get_name());
        } else if (info->get_symbol_kind() != "ARRAY") {
            report_error("variable is not of array type : " + $1->get_name());
        }
    }
    ;

expression : logic_expression
    {
        $$ = make_node($1->get_name(), "expr");
    }
    | variable ASSIGNOP logic_expression
    {
        string text = $1->get_name() + "=" + $3->get_name();
        $$ = make_node(text, "expr");
        if ($1->get_data_type() != "" && $3->get_data_type() != "" && $1->get_data_type() != $3->get_data_type()) {
            report_error("type mismatch in assignment");
        }
    }
    ;

logic_expression : rel_expression
    {
        $$ = make_node($1->get_name(), "lgc_expr");
    }
    | rel_expression LOGICOP rel_expression
    {
        string text = $1->get_name() + $2->get_name() + $3->get_name();
        $$ = make_node(text, "lgc_expr");
    }
    ;

rel_expression : simple_expression
    {
        $$ = make_node($1->get_name(), "rel_expr");
    }
    | simple_expression RELOP simple_expression
    {
        string text = $1->get_name() + $2->get_name() + $3->get_name();
        $$ = make_node(text, "rel_expr");
    }
    ;

simple_expression : term
    {
        $$ = make_node($1->get_name(), "simp_expr");
    }
    | simple_expression ADDOP term
    {
        string text = $1->get_name() + $2->get_name() + $3->get_name();
        $$ = make_node(text, "simp_expr");
    }
    ;

term : unary_expression
    {
        $$ = make_node($1->get_name(), "term");
    }
    | term MULOP unary_expression
    {
        string text = $1->get_name() + $2->get_name() + $3->get_name();
        $$ = make_node(text, "term");
        if ($2->get_name() == "%") {
            if ($1->get_data_type() == "float" || $3->get_data_type() == "float") {
                report_error("modulus by non-integer value");
            }
        }
    }
    ;

unary_expression : ADDOP unary_expression
    {
        string text = $1->get_name() + $2->get_name();
        $$ = make_node(text, "un_expr");
    }
    | NOT unary_expression
    {
        string text = "!" + $2->get_name();
        $$ = make_node(text, "un_expr");
    }
    | factor_info
    {
        $$ = make_node($1->get_name(), "un_expr");
    }
    ;

factor_info : factor
    {
        $$ = make_node($1->get_name(), "fctr_info");
    }
    ;

factor : variable
    {
        $$ = make_node($1->get_name(), "fctr");
    }
    | ID LPAREN argument_list RPAREN
    {
        string text = $1->get_name() + "(" + $3->get_name() + ")";
        $$ = make_node(text, "fctr");
        symbol_info *info = table->lookup($1->get_name());
        if (info == nullptr) {
            report_error("Undeclared function: " + $1->get_name());
        } else if (info->get_symbol_kind() != "FUNCTION") {
            report_error("Undeclared function: " + $1->get_name());
        } else {
            auto params = info->get_parameters();
            auto args = $3->get_parameters();
            if (params.size() != args.size()) {
                report_error("Inconsistencies in number of arguments in function call: " + $1->get_name());
            } else {
                for (size_t i = 0; i < params.size(); ++i) {
                    if (params[i].data_type != args[i].data_type) {
                        report_error("argument " + to_string(i + 1) + " type mismatch in function call: " + $1->get_name());
                    }
                }
            }
        }
    }
    | LPAREN expression RPAREN
    {
        string text = "(" + $2->get_name() + ")";
        $$ = make_node(text, "fctr");
    }
    | CONST_INT
    {
        $$ = make_node($1->get_name(), "fctr");
    }
    | CONST_FLOAT
    {
        $$ = make_node($1->get_name(), "fctr");
    }
    | variable INCOP
    {
        string text = $1->get_name() + "++";
        $$ = make_node(text, "fctr");
    }
    | variable DECOP
    {
        string text = $1->get_name() + "--";
        $$ = make_node(text, "fctr");
    }
    ;

argument_list : arguments
    {
        $$ = make_node($1->get_name(), "arg_list");
        $$->set_parameters($1->get_parameters());
    }
    | /* empty */
    {
        $$ = make_node("", "arg_list");
    }
    ;

arguments : arguments COMMA logic_expression
    {
        string text = $1->get_name() + "," + $3->get_name();
        $$ = make_node(text, "arg");
        $$->set_parameters($1->get_parameters());
        $$->add_parameter(parameter_record($3->get_data_type(), ""));
    }
    | logic_expression
    {
        $$ = make_node($1->get_name(), "arg");
        $$->add_parameter(parameter_record($1->get_data_type(), ""));
    }
    ;

%%

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <input-file.c>" << endl;
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (yyin == nullptr)
    {
        cout << "Could not open input file: " << argv[1] << endl;
        return 1;
    }

    string log_file_name = "21301096_log.txt";
    string error_file_name = "21301096_error.txt";
    outlog.open(log_file_name, ios::trunc);
    outerror.open(error_file_name, ios::trunc);

    if (!outlog.is_open() || !outerror.is_open())
    {
        cout << "Could not create log/error file." << endl;
        fclose(yyin);
        return 1;
    }

    table = new symbol_table(11);
    table->enter_scope();
    outlog << "New ScopeTable with id " << table->get_current_scope_id()
           << " created" << '\n' << '\n';

    int parse_result = yyparse();

    outlog << '\n' << "Total lines: " << lines << '\n';
    outlog << "Total errors: " << error_count << '\n';
    outerror << "Total errors: " << error_count << '\n';

    delete table;
    table = nullptr;
    outlog.close();
    outerror.close();
    fclose(yyin);

    return parse_result;
}