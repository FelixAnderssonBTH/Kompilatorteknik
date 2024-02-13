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
    return variables[var].getID();
};
std::string lookupMethod(std::string meth){
    return variables[meth].getID();
};
};

class Variable: public record{
    Variable(std::string id, std::string type):record(id,type){};
};

class Method: public record{
std::vector<Variable> parameters;
std::map<std::string, Variable> variables;

void addVariable(Variable var){
    variables[var.getID()]= var;
};
void addParameter(Variable para){
    parameters.push_back(para);
};
std::string lookupVariable(std::string var){
    return variables[var].getID();
}
std::string lookupParameter(std::string para){
    for (int i = 0; i < parameters.size(); i++)
    {
        if (parameters[i].getID()==para) return para;
    }
    
    return NULL;
}

};


class Scope{
    int next = 0;
    Scope* parentScope;
    std::vector <Scope*> childrenScopes;
    std::map<std::string,record>records;
    Scope(){
        
    };
    Scope(Scope* nano){
        if(nano == NULL){
        this->next = 0;
        this->parentScope = nullptr;
        }else{
        this->childrenScopes = (*nano).childrenScopes;
        this->next = (*nano).next;
        this->parentScope = (*nano).parentScope;
        this->records = (*nano).records;}
    };

    Scope nextChild(){
        Scope* nextChild;
        if (next==childrenScopes.size())
        {
            nextChild = new Scope(*this);
            childrenScopes.push_back(nextChild);
        }else
        {
            nextChild = childrenScopes.at(next);
        }
        next++;
        return *nextChild;
    }
    record* lookup(std::string key){
        if (records.find(key)!= records.end())
        {
            return &records[key];
        }else
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
    void resetScope(){
        next=0;
        for (int i = 0; i < childrenScopes.size(); i++)
        {
            childrenScopes[i]->resetScope();
        }
        
    }
};


class SymbolTable{
    Scope root;
    Scope current;
    SymbolTable(){root = new Scope(NULL); current = root;}
    void enterScope(){current = current.nextChild();}
    void exitScope(){current = current.parent();}
};









