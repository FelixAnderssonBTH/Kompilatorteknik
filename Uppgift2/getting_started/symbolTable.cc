#include "stdlib.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Record{
public:
  string name;
  string type;

  Record(const string& name,const string& type){
    this->name= name;
    this->type= type;
  };
  virtual ~Record() = default;

  virtual void print(int indent= 0) const = 0;

};




class VariableRecord: public Record{
public:
  string scope;
  VariableRecord(const string& name, const string& type, const string& scope){
    this->name = name;
    this->type = type;
    this->scope = scope;
  }
  void print(int indent) const override {
  string  padding(indent,' ');
  cout << padding << "Variable: " << name << " : " << type << "\n";
  }
};


class MethodRecord: public Record{
public:
  string return_type;
  map<string, VariableRecord*>parameters;
  map<string, VariableRecord*>local_variable;

  MethodRecord(const string &name, const string &return_type){
    this->return_type=return_type;
    this->name=name;
  }
    
  void addParameters(VariableRecord *parms){
    parameters[parms->name] = parms;
  }
  void addLocalVariable(VariableRecord *var){
    local_variable[var->name] = var;
  }

  void print(int indent = 0) const override {
    string padding(indent, ' ');

    cout<< padding << "Method: " << name << " : " << return_type << "\n";

    for (auto &p : parameters){
      p.second->print(indent+2);
    }
    for (auto &v : local_variable){
      v.second->print(indent+2);
    }
  }
};


class ClassRecord: public Record{
public:
  map<string, VariableRecord*>fields;
  map<string, MethodRecord*>methods;

  ClassRecord(string& name){
    this->name = name;
  };
  void addField(VariableRecord* var){
    fields[var->name]= var;
  }
  void addMethod(MethodRecord* method){
    methods[method->name]= method;
  }
  void print(int indent = 0) const override {
    string padding(indent, ' ');
    cout << padding << "Class: " << name << "\n";

    for (auto &f : fields){
      f.second->print(indent+2);
    }
    for (auto &m : methods){
      m.second->print(indent+2);
    }
  }
};


class Scope{
public:
  string name;
  Scope* parent;
  map<string, Record*> symbols;

  Scope(const string& name, Scope* parent = nullptr){
    this->name = name;
    this->parent = parent;
  }
  ~Scope(){
    for (auto&s: symbols)
      delete s.second;
  }

  void addRecord(Record* record){
    symbols[record->name] = record;
  }
  Record* getRecord(const string& name){
    if(symbols.find(name) != symbols.end())
      return symbols[name];
    if (parent)
      return parent->getRecord(name);
    return nullptr;
  }
  void print(int indent = 0) const{
    string padding(indent, ' ');
    cout << padding << "Scope: " << name << "\n";
    for (auto& s : symbols){
      s.second->print(indent+2);
    }
  }
};
class SymbolTable{
public:
  Scope* globalScope;
  Scope* currentScope;

  SymbolTable(){
    globalScope = new Scope("global");
    currentScope = globalScope;
  }
  ~SymbolTable(){
    delete globalScope;
  }
  void enterScope(const string& name){
    Scope* newScope = new Scope(name,currentScope);
    currentScope = newScope;
  }
  void exitScope(){
    if(currentScope->parent)
      currentScope = currentScope->parent;
  }
  void addRecord(Record* record){
    currentScope->addRecord(record);
  }
  Record* getRecord(const string& name){
    return currentScope->getRecord(name);
  }
  void reset(){
    delete globalScope;
    globalScope = new Scope("global");
    currentScope = globalScope;
  }
  void print() const {
    globalScope->print();
  }
};
