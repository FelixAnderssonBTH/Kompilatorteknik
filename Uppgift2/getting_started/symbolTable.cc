#include "stdlib.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// the most basic recored- parent
class Record {
public:
  string name;
  string type;

  Record(const string &name, const string &type) {
    this->name = name;
    this->type = type;
  };
  virtual ~Record() = default;

  virtual void print(int indent = 0) const = 0;
};

// child of record, for vars
class VariableRecord : public Record {
public:
  string scope;
  VariableRecord(const string &name, const string &type, const string &scope)
      : Record(name, type), scope(scope) {
  } // this is becuase we already have a constructor for parent
  void print(int indent) const override {
    string padding(indent, ' ');
    cout << padding << "Variable: " << name << " : " << type << "\n";
  }
};

// again this a child of record for methods in a class
class MethodRecord : public Record {
public:
  string return_type;
  map<string, VariableRecord *> parameters;
  map<string, VariableRecord *> local_variable;
  vector<VariableRecord *> param_list; // this stores parameters in exact order

  MethodRecord(const string &name, const string &return_type)
      : Record(name, "method"), return_type(return_type) {
  } // we have method hardcoded becuase this is a method record

  void addParameters(VariableRecord *parms) {
    parameters[parms->name] = parms;
    param_list.push_back(parms); // this just so that we track the order
  }
  void addLocalVariable(VariableRecord *var) { // we dont need to track order
    local_variable[var->name] = var;
  }

  void print(int indent = 0) const override {
    string padding(indent, ' ');

    cout << padding << "Method: " << name << " : " << return_type << "\n";

    for (auto &p :
         param_list) { // now we use the vector to print in the exat order
      p->print(indent + 2);
    }
    for (auto &v : local_variable) {
      v.second->print(indent + 2);
    }
  }
};

// child of record, for classes
class ClassRecord : public Record {
public:
  map<string, VariableRecord *> fields;
  map<string, MethodRecord *> methods;

  ClassRecord(string &name) : Record(name, "class") {}; // class type hardcoded
  void addField(VariableRecord *var) { fields[var->name] = var; }
  void addMethod(MethodRecord *method) { methods[method->name] = method; }
  void print(int indent = 0) const override {
    string padding(indent, ' ');
    cout << padding << "Class: " << name << "\n";

    for (auto &f : fields) {
      f.second->print(indent + 2);
    }
    for (auto &m : methods) {
      m.second->print(indent + 2);
    }
  }
};

// here we manage scope
class Scope {
public:
  string name;
  Scope *parent;
  map<string, Record *> symbols;
  map<string, Scope *> childrenScopes;

  Scope(const string &name, Scope *parent = nullptr) {
    this->name = name;
    this->parent = parent;
  }
  ~Scope() { // in the destructor we delete symbols and childrenScopes
    for (auto &s : symbols)
      delete s.second;
    for (auto &c : childrenScopes)
      delete c.second;
  }

  void addRecord(Record *record) { symbols[record->name] = record; }

  // this returns a record, if not in current scope it seraches for it in parent
  Record *getRecord(const string &name) {
    if (symbols.find(name) != symbols.end())
      return symbols[name];
    if (parent)
      return parent->getRecord(name);
    return nullptr;
  }
  void print(int indent = 0) const {
    string padding(indent, ' ');
    cout << padding << "Scope: " << name << "\n";
    for (auto &s : symbols) {
      s.second->print(indent + 2);
    }
    for (auto &c : childrenScopes) {
      c.second->print(indent + 2);
    }
  }
};

// finally the symboltable, it uses scope and record
class SymbolTable {
public:
  Scope *globalScope;
  Scope *currentScope;

  SymbolTable() {
    globalScope = new Scope("global");
    currentScope = globalScope;
  }

  ~SymbolTable() { delete globalScope; }

  // enter a scope, if we have children scope under same name, enter that or
  // create new scope
  void enterScope(const string &name) {
    if (currentScope->childrenScopes.find(name) !=
        currentScope->childrenScopes.end()) {
      currentScope = currentScope->childrenScopes[name];
    } else {
      Scope *newScope = new Scope(name, currentScope);
      currentScope->childrenScopes[name] = newScope;
      currentScope = newScope;
    }
  }

  // exit scope by going to parent or do nothing if parent
  void exitScope() {
    if (currentScope->parent)
      currentScope = currentScope->parent;
  }

  // add a record to the table at the scope
  void addRecord(Record *record) { currentScope->addRecord(record); }

  // get a record at this scope
  Record *getRecord(const string &name) {
    return currentScope->getRecord(name);
  }
  void reset() {
    delete globalScope;
    globalScope = new Scope("global");
    currentScope = globalScope;
  }
  void print() const { globalScope->print(); }
};
