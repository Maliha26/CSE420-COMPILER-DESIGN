#ifndef SCOPE_TABLE_H
#define SCOPE_TABLE_H

#include "symbol_info.h"

class scope_table
{
private:
    int bucket_count;
    int unique_id;
    scope_table *parent_scope;
    vector<list<symbol_info *> > table;

    int hash_function(const string &name) const
    {
        // djb2 string hash
        unsigned long long hash_value = 5381;
        for (unsigned char character : name)
            hash_value = ((hash_value << 5) + hash_value) + character;

        return static_cast<int>(hash_value % bucket_count);
    }

public:
    scope_table()
        : bucket_count(0), unique_id(0), parent_scope(nullptr) {}

    scope_table(int bucket_count, int unique_id, scope_table *parent_scope)
        : bucket_count(bucket_count),
          unique_id(unique_id),
          parent_scope(parent_scope),
          table(bucket_count) {}

    scope_table *get_parent_scope() const
    {
        return parent_scope;
    }

    int get_unique_id() const
    {
        return unique_id;
    }

    symbol_info *lookup_by_name(const string &name) const
    {
        if (bucket_count <= 0) return nullptr;

        int bucket_index = hash_function(name);
        for (symbol_info *symbol : table[bucket_index])
        {
            if (symbol->get_name() == name)
                return symbol;
        }

        return nullptr;
    }

    symbol_info *lookup_in_scope(symbol_info *symbol) const
    {
        if (symbol == nullptr) return nullptr;
        return lookup_by_name(symbol->get_name());
    }

    bool insert_in_scope(symbol_info *symbol)
    {
        if (symbol == nullptr || bucket_count <= 0) return false;
        if (lookup_by_name(symbol->get_name()) != nullptr) return false;

        int bucket_index = hash_function(symbol->get_name());
        table[bucket_index].push_back(symbol);
        return true;
    }

    bool delete_from_scope(symbol_info *symbol)
    {
        if (symbol == nullptr || bucket_count <= 0) return false;

        int bucket_index = hash_function(symbol->get_name());
        for (auto iterator = table[bucket_index].begin();
             iterator != table[bucket_index].end(); ++iterator)
        {
            if ((*iterator)->get_name() == symbol->get_name())
            {
                delete *iterator;
                table[bucket_index].erase(iterator);
                return true;
            }
        }

        return false;
    }

    void print_scope_table(ofstream &outlog) const
    {
        outlog << "ScopeTable # " << unique_id << '\n';

        for (int i = 0; i < bucket_count; ++i)
        {
            if (table[i].empty()) continue;

            outlog << i << " -->";
            for (symbol_info *symbol : table[i])
                outlog << " " << symbol->format_for_scope_table();

            outlog << '\n';
        }

        outlog << '\n';
    }

    ~scope_table()
    {
        for (list<symbol_info *> &bucket : table)
        {
            for (symbol_info *symbol : bucket)
                delete symbol;
            bucket.clear();
        }
    }
};

#endif
