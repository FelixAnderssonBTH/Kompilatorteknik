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
        std::cout << "Record" << this->record << "\n";
    }
};

class Variable : public Record
{
public:
    Variable(std::string id, std::string type) : Record(id, type)
    {
        this->setrecord("Variable");
    };
};
class Method : public Record
{
    std::map<std::string, Variable *> parameters;
    std::map<std::string, Variable *> variables;

public:
    Method(std::string id, std::string type) : Record(id, type) { this->setrecord("Method"); } // con
    void addVariable(Variable *var)
    {
        variables[(*var).getID()] = var;
    };
    void addParameter(Variable *para)
    {
        parameters[(*para).getID()] = para;
    };
    int lookupVariable(std::string var)
    {
        auto it = variables.find(var);
        if (it != variables.end())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int lookupParameter(std::string para)
    {
        auto it = parameters.find(para);
        if (it != parameters.end())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

class CLASS : public Record
{
    std::map<std::string, Variable *> variables;
    std::map<std::string, Method *> methods;

public:
    CLASS(std::string id, std::string type) : Record(id, type) { this->setrecord("Class"); }; // con

    void addVariable(Variable *var)
    {
        variables[(*var).getID()] = var;
    };
    void addMethod(Method *meth)
    {
        methods[(*meth).getID()] = meth;
    };
    int lookupVariable(std::string var)
    {
        auto it = variables.find(var);
        if (it != variables.end())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    };
    int lookupMethod(std::string meth)
    {
        auto it = methods.find(meth);
        if (it != methods.end())
        {
            return 1;
        }
        else
        {
            return 0;
        };
    };
};

class Scope
{
    int next = 0;
    Scope *parentScope;
    std::vector<Scope *> childrenScopes;
    std::map<std::string, Record *> records;
    std::string Scope_ID;

public:
    Scope(){};
    Scope(Scope *parent, std::string id)
    {
        parentScope = parent;
        Scope_ID = id;
    } //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
    void put(std::string id, Record *rec)
    {
        records[id] = rec;
    }
    Scope *nextChild(std::string id)
    {
        Scope *nextChild;
        if (next == childrenScopes.size())
        {
            nextChild = new Scope(this, id);
            childrenScopes.push_back(nextChild);
        }
        else
        {
            nextChild = childrenScopes.at(next);
        }
        next++;
        return nextChild;
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
        this->next = 0;
        for (int i = 0; i < childrenScopes.size(); i++)
        {
            childrenScopes[i]->resetScope();
        }
    }
    Scope *parent()
    {
        return parentScope;
    }
    void printScope()
    {
        std::cout << "Scope"
                  << "\n";
    }
};

class SymbolTable
{
    Scope *root;
    Scope *current;

public:
    SymbolTable()
    {
        root = new Scope(NULL, "start");
        current = root;
    }
    void enterScope(std::string id = NULL) { current = (*current).nextChild(id); }
    void exitScope() { current = (*current).parent(); }

    void put(std::string id, Record *item)
    {
        current->put(id, item);
    }
    Record *lookup(std::string key) { return (*current).lookup(key); }

    void printTable() { std::cout << "print table\n"; }
    void resetTable() { (*root).resetScope(); }
};

void traverse_tree(Node *root, SymbolTable *table)
{
    if ((*root).type == "start")
    {
        for (auto i = root->children.begin(); i != root->children.end(); i++)
        {
            table->put((*i)->value, new CLASS((*i)->value, (*i)->value));
            table->enterScope("CLASS: " + (*i)->value);
            traverse_tree((*i), table);
            table->exitScope();
        }
    }
    else if (root->type == "CLASS")
    {
        table->put("this", new Variable("this", root->value));
        for (auto i = root->children.begin(); i != root->children.end(); i++)
        {
            traverse_tree(*i, table);
        }
    }
    else if (root->type == "Main Class")
    {
        table->put("this", new Variable("this", root->value));
        table->put("main", new Method("main", "void"));
        table->enterScope("Method: main");
        table->put(root->children.front()->value, new Variable(root->children.front()->value, "string[]"));
        table->exitScope();
    }
    else if (root->type == "")
    {
        /* code */
    }
}