#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "scope_table.h"

// The main log file is defined in 21301096.y.
extern ofstream outlog;

class symbol_table
{
private:
    // Points to the scope currently at the top of the scope stack.
    scope_table *current_scope;

    // Number of buckets in every scope table.
    int bucket_count;

    // Used to assign a unique ID to every newly created scope.
    int current_scope_id;

public:
    // Constructor
    explicit symbol_table(int bucket_count)
    {
        this->current_scope = nullptr;
        this->bucket_count = bucket_count;
        this->current_scope_id = 0;
    }

    /*
     * Create a new scope table.
     *
     * The old current scope becomes the parent of the new scope.
     */
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

    /*
     * Delete the current scope and move to its parent scope.
     */
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

    /*
     * Return the ID of the current scope.
     *
     * Returns -1 when no scope exists.
     */
    int get_current_scope_id() const
    {
        if (current_scope == nullptr)
        {
            return -1;
        }

        return current_scope->get_unique_id();
    }

    /*
     * Insert a symbol into the current scope only.
     */
    bool insert(symbol_info *symbol)
    {
        if (current_scope == nullptr || symbol == nullptr)
        {
            return false;
        }

        return current_scope->insert_in_scope(symbol);
    }

    /*
     * Remove a symbol from the current scope only.
     */
    bool remove(symbol_info *symbol)
    {
        if (current_scope == nullptr || symbol == nullptr)
        {
            return false;
        }

        return current_scope->delete_from_scope(symbol);
    }

    /*
     * Search by using a symbol_info pointer.
     *
     * It searches the current scope first, followed by all parent scopes.
     */
    symbol_info *lookup(symbol_info *symbol) const
    {
        if (symbol == nullptr)
        {
            return nullptr;
        }

        return lookup(symbol->get_name());
    }

    /*
     * Search by symbol name.
     *
     * Search order:
     * current scope -> parent -> grandparent -> global scope
     */
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

    /*
     * Print the current scope into the main assignment log file.
     *
     * This version keeps compatibility with the original supplied
     * print_current_scope() function signature.
     */
    void print_current_scope() const
    {
        if (current_scope != nullptr)
        {
            current_scope->print_scope_table(outlog);
        }
    }

    /*
     * Print the current scope into a specified output stream.
     */
    void print_current_scope(ofstream &output_log) const
    {
        if (current_scope != nullptr)
        {
            current_scope->print_scope_table(output_log);
        }
    }

    /*
     * Print all active scope tables.
     *
     * Printing order:
     * current scope -> parent scopes -> global scope
     */
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

    /*
     * Destructor
     *
     * Deletes every remaining scope table.
     */
    ~symbol_table()
    {
        while (current_scope != nullptr)
        {
            exit_scope();
        }
    }
};

#endif