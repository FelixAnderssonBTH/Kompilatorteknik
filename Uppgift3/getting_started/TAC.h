#ifndef TAC_H
#define TAC_H

#include <iostream>
#include <string>
using namespace std;

class Tac {
public:
  string op, lhs, rhs, result;

  // getters and setters
  void dump() {
    cout << result << " := " << lhs << " " << op << " " << rhs << endl;
  }
};
class Expression : public Tac {};

class UnaryExpression : public Tac {};

class Copy : public Tac {};

class ArrayAccess : public Tac {};

class New : public Tac {};

class NewArray : public Tac {};

class Length : public Tac {};

class Parameter : public Tac {};

class MethodCall : public Tac {};

class Return : public Tac {};

class UndconditionalJump : public Tac {};

class ConditionalJump : public Tac {};

#endif
