#include "stdlib.h"
#include <iostream>
#include "Node.h"
#include <map>

using namespace std;

class Record{
public:
  string name;
  string type;

  Record(const string& name,const string& type){
    this.name= name;
    this.type= type;
  };
  virtual ~Record() = default;

  virtual void print(int indent= 0);

};




class VariableRecord: public Record{
public:
  string scope;
  VariableRecord(const string& name, const string& type, const string& scope){
    this.name = name;
    this.type = type;
    this.scope = scope;
  }
  void print(int indent) const override {
  string  padding(indent,' ');
  printf(padding<<"Variable"<<this.name);
  }
};


class MethodRecord: public Record{
public:
  string return_type;
  map<string, VariableRecord*>parameters;
  map<string, VariableRecord*>local_variable;

  MethodRecord(const string &name, const string &return_type)
    : Record(name, "method"), return_type(return_type) {}
    
  void addParameters(VariableRecord *parms){
    parameters[parms->name] = parms;
  }

  void addLocalVariable(VariableRecord *var){
    local_variable[var->name] = var;
  }

  void print(int indent = 0) const override {
    string padding(indent, ' ');
    string second_padding(indent+2, ' ');

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
};


class Scope{

};
class SymbolTable{

};
