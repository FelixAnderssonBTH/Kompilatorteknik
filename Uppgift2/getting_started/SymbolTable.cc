#include <string>
#include <map>
#include <vector>
#include <iostream>

class record{
    private:
    std::string id;
    std::string type;
    public:
    record(std::string id,std::string type){//con
        this->id= id;
        this->type=type;
    }
    ~record(){}//decon
    //getters and setters
    void setID(std::string new_id){
        this->id = new_id;
    }
    void setType(std::string new_type){
        this->type = new_type;
    }
    std::string getID(){
        return this->id;
    }
    std::string getType(){
      return this->type;  
    }

    //print func
    int printRecord(){
        std::cout<<"Name: "<<this->id<<"\n";
        std::cout<<"Type: "<<this->type<<"\n";
    }
};


class CLASS: public record{
std::map<std::string, Variable> variables;
std::map<std::string, Method> methods;
CLASS(std::string id, std::string type):record(id,type){};

void addVariable(Variable var){
    variables[var.getID()] = var;
};
void addMethod(Method meth){
    methods[meth.getID()] = meth;
};
std::string lookupVariable(std::string var){
    return variables[var.id];
};
void lookupMethod(std::string meth){
};
};

class Variable: public record{};

class Method: public record{
std::vector<Variable> parameters;
std::map<std::string, Variable> variables;

void addVariable(){

};
void addParameter(){

};
};




class SymbolTable{};


class Scope{};







