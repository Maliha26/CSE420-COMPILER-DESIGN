#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "scope_table.h"


extern ofstream outlog;

class symbol_table
{
private:
  
    scope_table *current_scope;
    int bucket_count;
    int current_scope_id;

public:
    explicit symbol_table(int bucket_count)
    {
        this->current_scope = nullptr;
        this->bucket_count = bucket_count;
        this->current_scope_id = 0;
    }
    void enter_scope()
    {
        current_scope_id++;

        scope_table *new_scope = new scope_table(
            bucket_count,
            current_scope_id,
            current_scope
        );

        current_scope = new_scope;
    }
    void exit_scope()
    {
        if (current_scope == nullptr)
        {
            return;
        }

        scope_table *scope_to_delete = current_scope;

        current_scope = current_scope->get_parent_scope();

        delete scope_to_delete;
    }
    int get_current_scope_id() const
    {
        if (current_scope == nullptr)
        {
            return -1;
        }

        return current_scope->get_unique_id();
    }
    bool insert(symbol_info *symbol)
    {
        if (current_scope == nullptr || symbol == nullptr)
        {
            return false;
        }

        return current_scope->insert_in_scope(symbol);
    }
    bool remove(symbol_info *symbol)
    {
        if (current_scope == nullptr || symbol == nullptr)
        {
            return false;
        }

        return current_scope->delete_from_scope(symbol);
    }
    symbol_info *lookup(symbol_info *symbol) const
    {
        if (symbol == nullptr)
        {
            return nullptr;
        }

        return lookup(symbol->get_name());
    }
    symbol_info *lookup(const string &name) const
    {
        scope_table *temporary_scope = current_scope;

        while (temporary_scope != nullptr)
        {
            symbol_info *found_symbol =
                temporary_scope->lookup_by_name(name);

            if (found_symbol != nullptr)
            {
                return found_symbol;
            }

            temporary_scope =
                temporary_scope->get_parent_scope();
        }

        return nullptr;
    }
    void print_current_scope() const
    {
        if (current_scope != nullptr)
        {
            current_scope->print_scope_table(outlog);
        }
    }
    void print_current_scope(ofstream &output_log) const
    {
        if (current_scope != nullptr)
        {
            current_scope->print_scope_table(output_log);
        }
    }
    void print_all_scopes(ofstream &output_log) const
    {
        output_log << "################################"
                   << '\n'
                   << '\n';

        scope_table *temporary_scope = current_scope;

        while (temporary_scope != nullptr)
        {
            temporary_scope->print_scope_table(output_log);

            temporary_scope =
                temporary_scope->get_parent_scope();
        }

        output_log << "################################"
                   << '\n'
                   << '\n';
    }
    ~symbol_table()
    {
        while (current_scope != nullptr)
        {
            exit_scope();
        }
    }
};

#endif