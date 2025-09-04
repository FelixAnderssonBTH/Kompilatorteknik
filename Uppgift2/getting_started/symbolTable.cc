#include "stdlib.h"
#include <iostream>
#include "Node.h"


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

class ClassRecord: public Record{


};


class MethodRecord: public Record{

};


class Scope{

};
class SymbolTable{

};
