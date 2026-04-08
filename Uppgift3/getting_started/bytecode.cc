#include "TAC_BB.h"
#include <fstream>

bool isNumber(const string &s) {
  if (s.empty())
    return false;
  for (char c : s) {
    if (c != '-' && !isdigit(c))
      return false;
  }
  return true;
}

void valueOrVariable(const string &str, ostream &out) {
  if (str.find("t_") == 0)
    return;
  if (isNumber(str))
    out << "iconst " << str << endl;
  else
    out << "iload " << str << endl;
}

void byteOP(Tac *tac, ostream &out) {
  // MATH OP
  if (tac->op == "+") {
    valueOrVariable(tac->lhs, out);
    valueOrVariable(tac->rhs, out);
    out << "iadd" << endl;
    if (tac->result.find("t_") != 0)
      out << "istore " << tac->result << endl;

  } else if (tac->op == "-") {
    valueOrVariable(tac->lhs, out);
    valueOrVariable(tac->rhs, out);
    out << "isub" << endl;
    if (tac->result.find("t_") != 0)
      out << "istore " << tac->result << endl;

  } else if (tac->op == "*") {
    valueOrVariable(tac->lhs, out);
    valueOrVariable(tac->rhs, out);
    out << "imul" << endl;
    if (tac->result.find("t_") != 0)
      out << "istore " << tac->result << endl;

  } else if (tac->op == "/") {
    valueOrVariable(tac->lhs, out);
    valueOrVariable(tac->rhs, out);
    out << "idiv" << endl;
    if (tac->result.find("t_") != 0)
      out << "istore " << tac->result << endl;

  } else if (tac->op == "&&") {
    valueOrVariable(tac->lhs, out);
    valueOrVariable(tac->rhs, out);
    out << "iand" << endl;
    if (tac->result.find("t_") != 0)
      out << "istore " << tac->result << endl;

  } else if (tac->op == "||") {
    valueOrVariable(tac->lhs, out);
    valueOrVariable(tac->rhs, out);
    out << "ior" << endl;
    if (tac->result.find("t_") != 0)
      out << "istore " << tac->result << endl;

  } else if (tac->op == "<") {
    valueOrVariable(tac->lhs, out);
    valueOrVariable(tac->rhs, out);
    out << "ilt" << endl;
    if (tac->result.find("t_") != 0)
      out << "istore " << tac->result << endl;

  } else if (tac->op == ">") {
    valueOrVariable(tac->lhs, out);
    valueOrVariable(tac->rhs, out);
    out << "igt" << endl;
    if (tac->result.find("t_") != 0)
      out << "istore " << tac->result << endl;

  } else if (tac->op == "==") {
    valueOrVariable(tac->lhs, out);
    valueOrVariable(tac->rhs, out);
    out << "ieq" << endl;
    if (tac->result.find("t_") != 0)
      out << "istore " << tac->result << endl;

  } else if (tac->op == "!") {
    valueOrVariable(tac->rhs, out);
    out << "inot" << endl;
    if (tac->result.find("t_") != 0)
      out << "istore " << tac->result << endl;

    // Other OP
  } else if (tac->op == "new") {

  } else if (tac->op == "param") {
    valueOrVariable(tac->result, out);

  } else if (tac->op == "call") {
    if (tac->lhs == "System.out.println") {
      out << "print" << endl;
    } else {
      out << "invokevirtual " << tac->lhs << endl;
      if (tac->result.find("t_") != 0)
        out << "istore " << tac->result << endl;
    }
  }

  // NO OP
  else if (tac->op == "") {
    if (tac->rhs == "" && isNumber(tac->lhs)) {
      out << "iconst " << tac->lhs << endl;
      out << "istore " << tac->result << endl;
    } else if (tac->rhs == "" && !isNumber(tac->lhs)) {
      out << "iload " << tac->lhs << endl;
      out << "istore " << tac->result << endl;
    }
  }

  // JUMP/return OP
  else if (tac->op == "goto") {
    out << "goto " << tac->result << endl;
  } else if (tac->op == "iffalse") {
    valueOrVariable(tac->rhs, out);
    out << "iffalse goto " << tac->result << endl;
  } else if (tac->op == "return") {
    valueOrVariable(tac->result, out);
    out << "ireturn" << endl;
  }
}

void generateBytecode(CFG &cfg) {
  ofstream file("BlockCode.mj");

  for (auto *block : cfg.blocks) {
    cout << block->name << ":" << endl;
    file << block->name << ":" << endl;
    for (auto &param : block->params) {
      cout << "istore " << param << endl;
      file << "istore " << param << endl;
    }
    for (auto *tac : block->instructions) {
      byteOP(tac, cout);
      byteOP(tac, file);
    }
    if (block->condition) {
      byteOP(block->condition, cout);
      byteOP(block->condition, file);
    }
    if (block->name.find(".main") != string::npos) {
      cout << "stop" << endl;
      file << "stop" << endl;
    }
    cout << "\n";
    file << "\n";
  }
  file.close();
}
