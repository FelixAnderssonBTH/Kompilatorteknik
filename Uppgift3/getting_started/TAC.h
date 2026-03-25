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
class Expression : public Tac {
public:
};
class MethodCall : public Tac {
public:
};
class Jump : public Tac {
public:
};
class CondJump : public Tac {
public:
};

#endif
