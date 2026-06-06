#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Instruction {
public:
  string id;
  string argument;
};

class Method {
public:
  vector<string> varibale;
  vector<Instruction> instructions;
};

class Program {
public:
  map<string, Method> methods;
  string mainMethod;

  Method getMethod(string name) { return methods[name]; }

  string getMainMethod() { return mainMethod; }
};

class Activation {
public:
  int pc;
  map<string, int> local_variable_value;
  Method method;

  Activation(int pc, Method m) : pc(pc), method(m) {}

  Instruction getNextInstruction() { return method.instructions[pc++]; }

  void storeValue(string name, int value) {
    local_variable_value[name] = value;
  }

  int getValue(string name) { return local_variable_value[name]; }
};

class Interpreter {
public:
  Program program;
  Method main;
  stack<int> data_stack;

  Interpreter(Program p) {
    program = p;
    main = program.getMethod(program.getMainMethod());
  }

  void execute() {
    Method m = main;
    Activation current_activation(0, m);
    string instruction_id = "";
    stack<Activation> activations_stack;

    while (instruction_id != "stop") {
      Instruction instruction = current_activation.getNextInstruction();
      instruction_id = instruction.id;

      if (instruction_id == "iconst") {
        data_stack.push(stoi(instruction.argument));
      } else if (instruction_id == "istore") {
        current_activation.storeValue(instruction.argument, data_stack.top());
        data_stack.pop();
      } else if (instruction_id == "iload") {
        data_stack.push(current_activation.getValue(instruction.argument));

      } else if (instruction_id == "iadd") {
        int v1 = data_stack.top();
        data_stack.pop();
        int v2 = data_stack.top();
        data_stack.pop();
        data_stack.push(v2 + v1);

      } else if (instruction_id == "isub") {
        int v1 = data_stack.top();
        data_stack.pop();
        int v2 = data_stack.top();
        data_stack.pop();
        data_stack.push(v2 - v1);

      } else if (instruction_id == "imul") {
        int v1 = data_stack.top();
        data_stack.pop();
        int v2 = data_stack.top();
        data_stack.pop();
        data_stack.push(v2 * v1);

      } else if (instruction_id == "idiv") {
        int v1 = data_stack.top();
        data_stack.pop();
        int v2 = data_stack.top();
        data_stack.pop();
        data_stack.push(v2 / v1);

      } else if (instruction_id == "ilt") {
        int v1 = data_stack.top();
        data_stack.pop();
        int v2 = data_stack.top();
        data_stack.pop();
        data_stack.push(v2 < v1 ? 1 : 0);

      } else if (instruction_id == "igt") {
        int v1 = data_stack.top();
        data_stack.pop();
        int v2 = data_stack.top();
        data_stack.pop();
        data_stack.push(v2 > v1 ? 1 : 0);

      } else if (instruction_id == "ieq") {
        int v1 = data_stack.top();
        data_stack.pop();
        int v2 = data_stack.top();
        data_stack.pop();
        data_stack.push(v2 == v1 ? 1 : 0);

      } else if (instruction_id == "iand") {
        int v1 = data_stack.top();
        data_stack.pop();
        int v2 = data_stack.top();
        data_stack.pop();
        data_stack.push((v1 * v2 != 0) ? 1 : 0);

      } else if (instruction_id == "ior") {
        int v1 = data_stack.top();
        data_stack.pop();
        int v2 = data_stack.top();
        data_stack.pop();
        data_stack.push((v1 + v2 != 0) ? 1 : 0);

      } else if (instruction_id == "inot") {
        int v = data_stack.top();
        data_stack.pop();
        data_stack.push(v == 0 ? 1 : 0);

      } else if (instruction_id == "goto") {
        for (int i = 0; i < current_activation.method.instructions.size();
             i++) {
          if (current_activation.method.instructions[i].id == "label" &&
              current_activation.method.instructions[i].argument ==
                  instruction.argument) {
            current_activation.pc = i;
            break;
          }
        }

      } else if (instruction_id == "iffalse") {
        int v = data_stack.top();
        data_stack.pop();
        if (v == 0) {
          for (int i = 0; i < current_activation.method.instructions.size();
               i++) {
            if (current_activation.method.instructions[i].id == "label" &&
                current_activation.method.instructions[i].argument ==
                    instruction.argument) {
              current_activation.pc = i;
              break;
            }
          }
        }
      } else if (instruction_id == "ireturn") {
        int returnVal = data_stack.top();
        data_stack.pop();
        current_activation = activations_stack.top();
        activations_stack.pop();
        data_stack.push(returnVal);

      } else if (instruction_id == "print") {
        cout << data_stack.top() << endl;
        data_stack.pop();

      } else if (instruction_id == "label") {

      } else if (instruction_id == "stop") {
        return;
      }
    }
  }
};

int main(int arg_len, char *arg[]) {
  if (arg_len < 2) {
    return 1;
  }

  Program program;
  ifstream file(arg[1]);
  string row;
  string method = "";

  while (getline(file, row)) {
    if (row.empty()) {
      continue;
    }
    if (row.back() == ':') {
      string method_name = row.substr(0, row.size() - 1);

      if (method_name.find('.') != string::npos) {
        method = method_name;
        program.methods[method_name] = Method();
        if (method_name.find(".main") != string::npos) {
          program.mainMethod = method_name;
        }

      } else {
        Instruction instruct;
        instruct.id = "label";
        instruct.argument = method_name;
        program.methods[method].instructions.push_back(instruct);
      }

    } else {
      Instruction instruct;
      istringstream line(row);
      line >> instruct.id;
      if (instruct.id == "iffalse") {
        string throw_away_goto;
        line >> throw_away_goto >> instruct.argument;
      } else {
        line >> instruct.argument;
      }
      program.methods[method].instructions.push_back(instruct);
    }
  }
  file.close();
  Interpreter interpreter(program);
  interpreter.execute();
  return 0;
}
