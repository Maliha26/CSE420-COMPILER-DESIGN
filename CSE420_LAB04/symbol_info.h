#ifndef SYMBOL_INFO_H
#define SYMBOL_INFO_H

#include <bits/stdc++.h>
using namespace std;

struct declaration_record
{
    string name;
    bool is_array;
    int array_size;

    declaration_record(string name = "", bool is_array = false, int array_size = 0)
        : name(name), is_array(is_array), array_size(array_size) {}
};

struct parameter_record
{
    string data_type;
    string name;

    parameter_record(string data_type = "", string name = "")
        : data_type(data_type), name(name) {}
};

class symbol_info
{
private:
    string name;
    string type;          // lexer/parser category: ID, program, expr, etc.
    string symbol_kind;   // VARIABLE, ARRAY, FUNCTION, or empty for parse nodes
    string data_type;     // variable type or function return type
    int array_size;

    vector<parameter_record> parameters;
    vector<declaration_record> declarations;

public:
    symbol_info(string name = "", string type = "")
        : name(name), type(type), symbol_kind(""), data_type(""), array_size(0) {}

    string get_name() const { return name; }
    string get_type() const { return type; }

    // Compatibility aliases for older starter parsers.
    string getname() const { return name; }
    string gettype() const { return type; }

    void set_name(const string &value) { name = value; }
    void set_type(const string &value) { type = value; }

    void set_as_variable(const string &variable_type)
    {
        symbol_kind = "VARIABLE";
        data_type = variable_type;
        array_size = 0;
    }

    void set_as_array(const string &element_type, int size)
    {
        symbol_kind = "ARRAY";
        data_type = element_type;
        array_size = size;
    }

    void set_as_function(const string &return_type,
                         const vector<parameter_record> &parameter_list)
    {
        symbol_kind = "FUNCTION";
        data_type = return_type;
        parameters = parameter_list;
        array_size = 0;
    }

    string get_symbol_kind() const { return symbol_kind; }
    string get_data_type() const { return data_type; }
    int get_array_size() const { return array_size; }

    void add_parameter(const parameter_record &parameter)
    {
        parameters.push_back(parameter);
    }

    void set_parameters(const vector<parameter_record> &parameter_list)
    {
        parameters = parameter_list;
    }

    const vector<parameter_record> &get_parameters() const
    {
        return parameters;
    }

    void add_declaration(const declaration_record &declaration)
    {
        declarations.push_back(declaration);
    }

    void set_declarations(const vector<declaration_record> &declaration_list)
    {
        declarations = declaration_list;
    }

    const vector<declaration_record> &get_declarations() const
    {
        return declarations;
    }

    string format_for_scope_table() const
    {
        ostringstream output;

        if (symbol_kind == "VARIABLE")
        {
            output << "< " << name << " : VARIABLE, " << data_type << " >";
        }
        else if (symbol_kind == "ARRAY")
        {
            output << "< " << name << " : ARRAY, " << data_type
                   << ", size=" << array_size << " >";
        }
        else if (symbol_kind == "FUNCTION")
        {
            output << "< " << name << " : FUNCTION, return=" << data_type
                   << ", parameters=(";

            for (size_t i = 0; i < parameters.size(); ++i)
            {
                if (i > 0) output << ", ";
                output << parameters[i].data_type;
                if (!parameters[i].name.empty())
                    output << " " << parameters[i].name;
            }

            output << ") >";
        }
        else
        {
            output << "< " << name << " : " << type << " >";
        }

        return output.str();
    }

    ~symbol_info() = default;
};

#endif
