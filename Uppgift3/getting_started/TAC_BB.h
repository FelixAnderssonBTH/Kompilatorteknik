#ifndef TAC_H
#define TAC_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tac {
public:
  string tac_output, op, lhs, rhs, result;

  string dump() {
    // for debugging
    return tac_output;
  }
};

class Expression : public Tac {
public:
  Expression(string _op, string _lhs, string _rhs, string _result) {
    op = _op;
    lhs = _lhs;
    rhs = _rhs;
    result = _result;
    tac_output = result + " := " + lhs + " " + op + " " + rhs;
  }
};

class UnaryExpression : public Tac {
public:
  UnaryExpression(string _op, string _rhs, string _result) {
    op = _op;
    rhs = _rhs;
    result = _result;
    tac_output = result + " := " + op + " " + rhs;
  }
};

class Copy : public Tac {
public:
  Copy(string _lhs, string _result) {
    lhs = _lhs;
    result = _result;
    tac_output = result + " := " + rhs;
  }
};

class ArrayAccess : public Tac {
public:
  ArrayAccess(string _lhs, string _rhs, string _result) {
    lhs = _lhs;
    rhs = _rhs;
    result = _result;
    tac_output = result + " := " + lhs + "[" + rhs + "]";
  }
};

class ArrayCopy : public Tac {
public:
  ArrayCopy(string _lhs, string _rhs, string _result) {
    lhs = _lhs;
    rhs = _rhs;
    result = _result;
    tac_output = lhs + "[" + rhs + "]" + " := " + result;
  }
};

class New : public Tac {
public:
  New(string _type, string _result) {
    op = "new";
    rhs = _type;
    result = _result;
    tac_output = result + " := " + op + " " + rhs;
  }
};

class NewArray : public Tac {
public:
  NewArray(string _lhs, string _type, string _result) {
    op = "new";
    lhs = _lhs;
    rhs = _type;
    result = _result;
    tac_output = result + " := " + op + " " + rhs + ", " + _lhs;
  }
};

class Length : public Tac {
public:
  Length(string _rhs, string _result) {
    op = "length";
    rhs = _rhs;
    result = _result;
    tac_output = result + " := " + op + " " + rhs;
  }
};

class Parameter : public Tac {
public:
  Parameter(string _param) {
    op = "param";
    result = _param;
    tac_output = "param " + result;
  }
};

class MethodCall : public Tac {
public:
  MethodCall(string _lhs, string _rhs, string _result) {
    op = "call";
    lhs = _lhs;
    rhs = _rhs;
    result = _result;
    tac_output = result + " := " + op + " " + lhs + ", " + rhs;
  }
};

class Return : public Tac {
public:
  Return(string _result) {
    op = "return";
    result = _result;
    tac_output = op + " " + result;
  }
};

class UndconditionalJump : public Tac {
public:
  UndconditionalJump(string _result) {
    op = "goto";
    result = _result;
    tac_output = op + " " + result;
  }
};

class ConditionalJump : public Tac {
public:
  ConditionalJump(string _rhs, string _result) {
    op = "iffalse";
    rhs = _rhs;
    result = _result;
    tac_output = op + " " + rhs + " goto " + result;
  }
};

class BasicBlock {
public:
  string name;
  vector<Tac *> instructions;
  Tac *condition;
  BasicBlock *trueExit;
  BasicBlock *falseExit;

  BasicBlock() : condition(NULL), trueExit(NULL), falseExit(NULL) {}

  void dump() {
    cout << name << ":" << endl;
    for (auto t : instructions) {
      cout << "  " << t->dump() << endl;
    }
    if (condition) {
      cout << "  " << condition->dump() << endl;
    }
  }
};

class CFG {
public:
  vector<BasicBlock *> blocks;

  void add_block(BasicBlock *b) { blocks.push_back(b); }

  void generate_dot(string filename) {
    ofstream out;
    out.open(filename);
    out << "digraph {" << endl;
    out << "graph [ splines = ortho ]" << endl;
    out << "node [ shape = box ];" << endl;

    for (auto b : blocks) {
      out << b->name << " [ shape = box label = \"" << b->name << "\\n";
      for (auto t : b->instructions) {
        out << t->dump() << "\\n";
      }
      if (b->condition) {
        out << b->condition->dump() << "\\n";
      }
      out << "\" ];" << endl;
    }

    for (auto b : blocks) {
      if (b->trueExit) {
        out << b->name << " -> " << b->trueExit->name
            << " [ xlabel = \"true\" ];" << endl;
      }
      if (b->falseExit) {
        out << b->name << " -> " << b->falseExit->name
            << " [ xlabel = \"false\" ];" << endl;
      }
    }

    out << "}" << endl;
    out.close();
  }
};

#endif
