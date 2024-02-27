#include <string>
#include <map>
#include <vector>
#include <iostream>
#include "Node.h"
class Record
{
private:
    std::string id;
    std::string type;
    std::string record;

public:
    Record(){};
    Record(std::string id, std::string type)
    { // con
        this->id = id;
        this->type = type;
    }
    ~Record() {} // decon
    // getters and setters
    void setID(std::string new_id)
    {
        this->id = new_id;
    }
    void setType(std::string new_type)
    {
        this->type = new_type;
    }
    void setrecord(std::string record)
    {
        this->record = record;
    }
    std::string getID()
    {
        return this->id;
    }
    std::string getType()
    {
        return this->type;
    }
    std::string getrecord()
    {
        return this->record;
    }

    // print func
    void printRecord()
    {
        std::cout << "Name: " << this->id << "\n";
        std::cout << "Type: " << this->type << "\n";
    }
};

class Variable : public Record
{
public:
    Variable(std::string id, std::string type) : Record(id, type){};
};
class Method : public Record
{
    std::vector<Variable *> parameters;
    std::map<std::string, Variable *> variables;

    void addVariable(Variable var)
    {
        variables[var.getID()] = &var;
    };
    void addParameter(Variable para)
    {
        parameters.push_back(&para);
    };
    std::string lookupVariable(std::string var)
    {
        return (*variables[var]).getID();
    }
    std::string lookupParameter(std::string para)
    {
        for (int i = 0; i < parameters.size(); i++)
        {
            if ((*parameters[i]).getID() == para)
                return para;
        }

        return NULL;
    }
};

class CLASS : public Record
{
    std::map<std::string, Variable *> variables;
    std::map<std::string, Method *> methods;
    CLASS(std::string id, std::string type) : Record(id, type){};

    void addVariable(Variable var)
    {
        variables[var.getID()] = &var;
    };
    void addMethod(Method meth)
    {
        methods[meth.getID()] = &meth;
    };
    std::string lookupVariable(std::string var)
    {
        return (*variables[var]).getID();
    };
    std::string lookupMethod(std::string meth)
    {
        return (*variables[meth]).getID();
    };
};

class Scope
{
public:
    int next = 0;
    Scope *parentScope;
    std::vector<Scope *> childrenScopes;
    std::map<std::string, Record *> records;
    Scope(){};
    Scope(Scope *nano)
    {
        if (nano == NULL)
        {
            this->next = 0;
            this->parentScope = nullptr;
        }
        else
        {
            this->childrenScopes = (*nano).childrenScopes;
            this->next = (*nano).next;
            this->parentScope = (*nano).parentScope;
            this->records = (*nano).records;
        }
    };

    Scope nextChild()
    {
        Scope *nextChild;
        if (next == childrenScopes.size())
        {
            nextChild = new Scope(*this);
            childrenScopes.push_back(nextChild);
        }
        else
        {
            nextChild = childrenScopes.at(next);
        }
        next++;
        return *nextChild;
    }
    Record *lookup(std::string key)
    {
        if (records.find(key) != records.end())
        {
            return records[key];
        }
        else
        {
            if (parentScope == NULL)
            {
                return NULL;
            }
            else
            {
                return parentScope->lookup(key);
            }
        }
    }
    void resetScope()
    {
        next = 0;
        for (int i = 0; i < childrenScopes.size(); i++)
        {
            childrenScopes[i]->resetScope();
        }
    }
    Scope parent()
    {
        return *parentScope;
    }
    void printScope()
    {
        std::cout << "Scope"
                  << "\n";
    }
};

class SymbolTable
{
    std::vector<Record *> table;

public:
    Scope root;
    Scope current;

    SymbolTable()
    {
        root = new Scope(NULL);
        current = root;
    }
    void enterScope() { current = current.nextChild(); }
    void exitScope() { current = current.parent(); }

    void put(std::string key, Record *item)
    {
        // table[key] = item;
    }
    Record *lookup(std::string key) { return current.lookup(key); }

    void printTable() { root.printScope(); }
    void resetTable() { root.resetScope(); }
};

void traverse_tree(Node *root, SymbolTable *table)
{
    Record item;
    // int depth = 0;
    // for (int i = 0; i < depth; i++)
    //     std::cout << "  ";
    // std::cout << (*root).id << ":" << (*root).value << std::endl;
    for (auto i = (*root).children.begin(); i != (*root).children.end(); i++)
    {
        if ((*i)->type == "Str")
        {
            item.setType((*i)->type);
            item.setID((*i)->value);
            //(*table).put();
        }

        // std::cout << (*i)->value << std::endl;
        traverse_tree(*i, table);
    }
}