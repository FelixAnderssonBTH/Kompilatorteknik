#ifndef TAC_H
#define TAC_H

#include <iostream>
#include <string>

using namespace std;

class Tac {
public:
  string tac_output, op, lhs, rhs, result;

  // getters and setters
  string dump() {
    // for debugging
    cout << result << " := " << lhs << " " << op << " " << rhs << endl;
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
    tac_output = op + " " + rhs + "goto" + result;
  }
};

#endif
