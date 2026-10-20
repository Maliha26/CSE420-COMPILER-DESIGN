%{
#include<bits/stdc++.h>
#include"symbol_info.h"
using namespace std;

#define YYSTYPE symbol_info*

int yyparse(void);
int yylex(void);
void yyerror(const char *s);

extern FILE *yyin;

ofstream outlog;
int lines = 1;

void print_rule(string rule, string text)
{
    // normalize formatting: ensure 'else if' has spaces
    size_t p = 0;
    while ((p = text.find("elseif", p)) != string::npos) {
        text.replace(p, 6, " else if");
        p += 8; // move past the inserted text
    }
    outlog << "At line no: " << lines << " " << rule << endl << endl;
    outlog << text << endl << endl;
}
%}

%token IF ELSE FOR WHILE DO SWITCH BREAK DEFAULT
%token INT CHAR FLOAT DOUBLE VOID
%token RETURN CONTINUE CASE GOTO PRINTLN
%token ID CONST_INT CONST_FLOAT
%token ADDOP MULOP INCOP DECOP RELOP ASSIGNOP LOGICOP NOT
%token LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA COLON SEMICOLON

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

start : program
      {
          print_rule("start : program", $1->getnameofsymbol());
          $$ = new symbol_info($1->getnameofsymbol(), "start");
      }
      ;

program : program unit
        {
            string text = $1->getnameofsymbol() + "\n" + $2->getnameofsymbol();
            print_rule("program : program unit", text);
            $$ = new symbol_info(text, "program");
        }
        | unit
        {
            print_rule("program : unit", $1->getnameofsymbol());
            $$ = new symbol_info($1->getnameofsymbol(), "program");
        }
        ;

unit : variable_decl
     {
         print_rule("unit : variable_decl", $1->getnameofsymbol());
         $$ = new symbol_info($1->getnameofsymbol(), "unit");
     }
     | func_definition
     {
         print_rule("unit : func_definition", $1->getnameofsymbol());
         $$ = new symbol_info($1->getnameofsymbol(), "unit");
     }
     ;

func_definition : type_specifier ID LPAREN param_list RPAREN compound_statement
                {
                    string text = $1->getnameofsymbol() + " " + $2->getnameofsymbol() + "(" + $4->getnameofsymbol() + ")" + $6->getnameofsymbol();
                    print_rule("func_definition : type_specifier ID LPAREN param_list RPAREN compound_statement", text);
                    $$ = new symbol_info(text, "func_definition");
                }
                | type_specifier ID LPAREN RPAREN compound_statement
                {
                    string text = $1->getnameofsymbol() + " " + $2->getnameofsymbol() + "()" + $5->getnameofsymbol();
                    print_rule("func_definition : type_specifier ID LPAREN RPAREN compound_statement", text);
                    $$ = new symbol_info(text, "func_definition");
                }
                ;

param_list : param_list COMMA type_specifier ID
           {
               string text = $1->getnameofsymbol() + "," + $3->getnameofsymbol() + " " + $4->getnameofsymbol();
               print_rule("param_list : param_list COMMA type_specifier ID", text);
               $$ = new symbol_info(text, "param_list");
           }
           | param_list COMMA type_specifier
           {
               string text = $1->getnameofsymbol() + "," + $3->getnameofsymbol();
               print_rule("param_list : param_list COMMA type_specifier", text);
               $$ = new symbol_info(text, "param_list");
           }
           | type_specifier ID
           {
               string text = $1->getnameofsymbol() + " " + $2->getnameofsymbol();
               print_rule("param_list : type_specifier ID", text);
               $$ = new symbol_info(text, "param_list");
           }
           | type_specifier
           {
               print_rule("param_list : type_specifier", $1->getnameofsymbol());
               $$ = new symbol_info($1->getnameofsymbol(), "param_list");
           }
           ;

compound_statement : LCURL statements RCURL
                   {
                       string text = "{\n" + $2->getnameofsymbol() + "\n}";
                       print_rule("compound_statement : LCURL statements RCURL", text);
                       $$ = new symbol_info(text, "compound_statement");
                   }
                   | LCURL RCURL
                   {
                       string text = "{\n}";
                       print_rule("compound_statement : LCURL RCURL", text);
                       $$ = new symbol_info(text, "compound_statement");
                   }
                   ;

variable_decl : type_specifier declaration_list SEMICOLON
              {
                  string text = $1->getnameofsymbol() + " " + $2->getnameofsymbol() + ";";
                  print_rule("variable_decl : type_specifier declaration_list SEMICOLON", text);
                  $$ = new symbol_info(text, "variable_decl");
              }
              ;

type_specifier : INT
               {
                   print_rule("type_specifier : INT", "int");
                   $$ = new symbol_info("int", "type_specifier");
               }
               | FLOAT
               {
                   print_rule("type_specifier : FLOAT", "float");
                   $$ = new symbol_info("float", "type_specifier");
               }
               | VOID
               {
                   print_rule("type_specifier : VOID", "void");
                   $$ = new symbol_info("void", "type_specifier");
               }
               | CHAR
               {
                   print_rule("type_specifier : CHAR", "char");
                   $$ = new symbol_info("char", "type_specifier");
               }
               | DOUBLE
               {
                   print_rule("type_specifier : DOUBLE", "double");
                   $$ = new symbol_info("double", "type_specifier");
               }
               ;

declaration_list : declaration_list COMMA ID
                 {
                     string text = $1->getnameofsymbol() + "," + $3->getnameofsymbol();
                     print_rule("declaration_list : declaration_list COMMA ID", text);
                     $$ = new symbol_info(text, "declaration_list");
                 }
                 | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
                 {
                     string text = $1->getnameofsymbol() + "," + $3->getnameofsymbol() + "[" + $5->getnameofsymbol() + "]";
                     print_rule("declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD", text);
                     $$ = new symbol_info(text, "declaration_list");
                 }
                 | ID
                 {
                     print_rule("declaration_list : ID", $1->getnameofsymbol());
                     $$ = new symbol_info($1->getnameofsymbol(), "declaration_list");
                 }
                 | ID LTHIRD CONST_INT RTHIRD
                 {
                     string text = $1->getnameofsymbol() + "[" + $3->getnameofsymbol() + "]";
                     print_rule("declaration_list : ID LTHIRD CONST_INT RTHIRD", text);
                     $$ = new symbol_info(text, "declaration_list");
                 }
                 ;

statements : statement
           {
               print_rule("statements : statement", $1->getnameofsymbol());
               $$ = new symbol_info($1->getnameofsymbol(), "statements");
           }
           | statements statement
           {
               string text = $1->getnameofsymbol() + "\n" + $2->getnameofsymbol();
               print_rule("statements : statements statement", text);
               $$ = new symbol_info(text, "statements");
           }
           ;

statement : variable_decl
          {
              print_rule("statement : variable_decl", $1->getnameofsymbol());
              $$ = new symbol_info($1->getnameofsymbol(), "statement");
          }
          | expression_statement
          {
              print_rule("statement : expression_statement", $1->getnameofsymbol());
              $$ = new symbol_info($1->getnameofsymbol(), "statement");
          }
          | compound_statement
          {
              print_rule("statement : compound_statement", $1->getnameofsymbol());
              $$ = new symbol_info($1->getnameofsymbol(), "statement");
          }
          | FOR LPAREN expression_statement expression_statement expression RPAREN statement
          {
              string text = "for(" + $3->getnameofsymbol() + $4->getnameofsymbol() + $5->getnameofsymbol() + ")" + $7->getnameofsymbol();
              print_rule("statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement", text);
              $$ = new symbol_info(text, "statement");
          }
          | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE
          {
              string text = "if(" + $3->getnameofsymbol() + ")" + $5->getnameofsymbol();
              print_rule("statement : IF LPAREN expression RPAREN statement", text);
              $$ = new symbol_info(text, "statement");
          }
          | IF LPAREN expression RPAREN statement ELSE statement
          {
              string text = "if(" + $3->getnameofsymbol() + ")" + $5->getnameofsymbol() + " else " + $7->getnameofsymbol();
              print_rule("statement : IF LPAREN expression RPAREN statement ELSE statement", text);
              $$ = new symbol_info(text, "statement");
          }
          | WHILE LPAREN expression RPAREN statement
          {
              string text = "while(" + $3->getnameofsymbol() + ")" + $5->getnameofsymbol();
              print_rule("statement : WHILE LPAREN expression RPAREN statement", text);
              $$ = new symbol_info(text, "statement");
          }
          | PRINTLN LPAREN ID RPAREN SEMICOLON
          {
              string text = "printf(" + $3->getnameofsymbol() + ");";
              print_rule("statement : PRINTLN LPAREN ID RPAREN SEMICOLON", text);
              $$ = new symbol_info(text, "statement");
          }
          | RETURN expression SEMICOLON
          {
              string text = "return " + $2->getnameofsymbol() + ";";
              print_rule("statement : RETURN expression SEMICOLON", text);
              $$ = new symbol_info(text, "statement");
          }
          ;

expression_statement : SEMICOLON
                     {
                         print_rule("expression_statement : SEMICOLON", ";");
                         $$ = new symbol_info(";", "expression_statement");
                     }
                     | expression SEMICOLON
                     {
                         string text = $1->getnameofsymbol() + ";";
                         print_rule("expression_statement : expression SEMICOLON", text);
                         $$ = new symbol_info(text, "expression_statement");
                     }
                     ;

variable : ID
         {
             print_rule("variable : ID", $1->getnameofsymbol());
             $$ = new symbol_info($1->getnameofsymbol(), "variable");
         }
         | ID LTHIRD expression RTHIRD
         {
             string text = $1->getnameofsymbol() + "[" + $3->getnameofsymbol() + "]";
             print_rule("variable : ID LTHIRD expression RTHIRD", text);
             $$ = new symbol_info(text, "variable");
         }
         ;

expression : logic_expression
           {
               print_rule("expression : logic_expression", $1->getnameofsymbol());
               $$ = new symbol_info($1->getnameofsymbol(), "expression");
           }
           | variable ASSIGNOP logic_expression
           {
               string text = $1->getnameofsymbol() + "=" + $3->getnameofsymbol();
               print_rule("expression : variable ASSIGNOP logic_expression", text);
               $$ = new symbol_info(text, "expression");
           }
           ;

logic_expression : rel_expression
                 {
                     print_rule("logic_expression : rel_expression", $1->getnameofsymbol());
                     $$ = new symbol_info($1->getnameofsymbol(), "logic_expression");
                 }
                 | rel_expression LOGICOP rel_expression
                 {
                     string text = $1->getnameofsymbol() + $2->getnameofsymbol() + $3->getnameofsymbol();
                     print_rule("logic_expression : rel_expression LOGICOP rel_expression", text);
                     $$ = new symbol_info(text, "logic_expression");
                 }
                 ;

rel_expression : simple_expression
               {
                   print_rule("rel_expression : simple_expression", $1->getnameofsymbol());
                   $$ = new symbol_info($1->getnameofsymbol(), "rel_expression");
               }
               | simple_expression RELOP simple_expression
               {
                   string text = $1->getnameofsymbol() + $2->getnameofsymbol() + $3->getnameofsymbol();
                   print_rule("rel_expression : simple_expression RELOP simple_expression", text);
                   $$ = new symbol_info(text, "rel_expression");
               }
               ;

simple_expression : term
                  {
                      print_rule("simple_expression : term", $1->getnameofsymbol());
                      $$ = new symbol_info($1->getnameofsymbol(), "simple_expression");
                  }
                  | simple_expression ADDOP term
                  {
                      string text = $1->getnameofsymbol() + $2->getnameofsymbol() + $3->getnameofsymbol();
                      print_rule("simple_expression : simple_expression ADDOP term", text);
                      $$ = new symbol_info(text, "simple_expression");
                  }
                  ;

term : unary_expression
     {
         print_rule("term : unary_expression", $1->getnameofsymbol());
         $$ = new symbol_info($1->getnameofsymbol(), "term");
     }
     | term MULOP unary_expression
     {
         string text = $1->getnameofsymbol() + $2->getnameofsymbol() + $3->getnameofsymbol();
         print_rule("term : term MULOP unary_expression", text);
         $$ = new symbol_info(text, "term");
     }
     ;

unary_expression : ADDOP unary_expression
                 {
                     string text = $1->getnameofsymbol() + $2->getnameofsymbol();
                     print_rule("unary_expression : ADDOP unary_expression", text);
                     $$ = new symbol_info(text, "unary_expression");
                 }
                 | NOT unary_expression
                 {
                     string text = "!" + $2->getnameofsymbol();
                     print_rule("unary_expression : NOT unary_expression", text);
                     $$ = new symbol_info(text, "unary_expression");
                 }
                 | factor_info
                 {
                     print_rule("unary_expression : factor_info", $1->getnameofsymbol());
                     $$ = new symbol_info($1->getnameofsymbol(), "unary_expression");
                 }
                 ;

factor_info : factor
            {
                print_rule("factor_info : factor", $1->getnameofsymbol());
                $$ = new symbol_info($1->getnameofsymbol(), "factor_info");
            }
            ;

factor : variable
       {
           print_rule("factor : variable", $1->getnameofsymbol());
           $$ = new symbol_info($1->getnameofsymbol(), "factor");
       }
       | ID LPAREN argument_list RPAREN
       {
           string text = $1->getnameofsymbol() + "(" + $3->getnameofsymbol() + ")";
           print_rule("factor : ID LPAREN argument_list RPAREN", text);
           $$ = new symbol_info(text, "factor");
       }
       | LPAREN expression RPAREN
       {
           string text = "(" + $2->getnameofsymbol() + ")";
           print_rule("factor : LPAREN expression RPAREN", text);
           $$ = new symbol_info(text, "factor");
       }
       | CONST_INT
       {
           print_rule("factor : CONST_INT", $1->getnameofsymbol());
           $$ = new symbol_info($1->getnameofsymbol(), "factor");
       }
       | CONST_FLOAT
       {
           print_rule("factor : CONST_FLOAT", $1->getnameofsymbol());
           $$ = new symbol_info($1->getnameofsymbol(), "factor");
       }
       | variable INCOP
       {
           string text = $1->getnameofsymbol() + "++";
           print_rule("factor : variable INCOP", text);
           $$ = new symbol_info(text, "factor");
       }
       | variable DECOP
       {
           string text = $1->getnameofsymbol() + "--";
           print_rule("factor : variable DECOP", text);
           $$ = new symbol_info(text, "factor");
       }
       ;

argument_list : arguments
              {
                  print_rule("argument_list : arguments", $1->getnameofsymbol());
                  $$ = new symbol_info($1->getnameofsymbol(), "argument_list");
              }
              |
              {
                  print_rule("argument_list : ", "");
                  $$ = new symbol_info("", "argument_list");
              }
              ;

arguments : arguments COMMA logic_expression
          {
              string text = $1->getnameofsymbol() + "," + $3->getnameofsymbol();
              print_rule("arguments : arguments COMMA logic_expression", text);
              $$ = new symbol_info(text, "arguments");
          }
          | logic_expression
          {
              print_rule("arguments : logic_expression", $1->getnameofsymbol());
              $$ = new symbol_info($1->getnameofsymbol(), "arguments");
          }
          ;

%%

void yyerror(const char *s)
{
    outlog << "Error at line no: " << lines << " : " << s << endl << endl;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << "Please provide input file name" << endl;
        return 0;
    }

    yyin = fopen(argv[1], "r");
    outlog.open("my_log.txt", ios::trunc);

    if(yyin == NULL)
    {
        cout << "Couldn't open file" << endl;
        return 0;
    }

    yyparse();

    outlog << "Total lines: " << lines << endl;

    outlog.close();
    fclose(yyin);

    return 0;
}