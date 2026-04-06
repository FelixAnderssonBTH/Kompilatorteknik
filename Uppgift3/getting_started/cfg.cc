#include "Node.h"
#include "TAC_BB.h"
#include <string>

int tempCount = 0;
int blockCount = 0;

string mathOP(Node *node, BasicBlock *current, string dest = "") {
  cout << node->type << endl;
  if (node->type == "Int" || node->type == "Str" || node->type == "TRUE" ||
      node->type == "FALSE" || node->type == "THIS")
    return node->value;

  if (node->type == "BracketsExpression")
    return mathOP(node->children.front(), current);

  if (node->type == "ArrayExpression") {
    auto it = node->children.begin();
    string array = mathOP(*it++, current);
    string index = mathOP(*it, current);
    string result;
    if (dest.empty())
      result = "t_" + to_string(tempCount++);
    else
      result = dest;
    current->instructions.push_back(new ArrayAccess(array, index, result));
    return result;
  }

  if (node->type == "Recursive_Expression") {
    auto it = node->children.begin();
    Node *call = *it++;
    Node *method = *it++;

    string callOP = mathOP(call, current);

    while (it != node->children.end()) {
      current->instructions.push_back(new Parameter(mathOP(*it, current)));
      ++it;
    }

    string result;
    if (dest.empty())
      result = "t_" + to_string(tempCount++);
    else {
      result = dest;
    }
    current->instructions.push_back(
        new MethodCall(callOP + "." + method->value,
                       to_string(node->children.size() - 2), result));
    return result;
  }

  string op;
  if (node->type == "AddExpression")
    op = "+";
  if (node->type == "SubExpression")
    op = "-";
  if (node->type == "MultExpression")
    op = "*";
  if (node->type == "EqualExpression")
    op = "==";
  if (node->type == "LeftArrowExpression")
    op = "<";
  if (node->type == "RightArrowExpression")
    op = ">";
  if (node->type == "AndExpression")
    op = "&&";
  if (node->type == "OrExpression")
    op = "||";
  auto it = node->children.begin();
  string left = mathOP(*it++, current);
  string right = mathOP(*it, current);

  string result;
  if (dest.empty()) {
    result = "t_" + to_string(tempCount++);

  } else {
    result = dest;
  }

  current->instructions.push_back(new Expression(op, left, right, result));
  return result;
}

void traverse(Node *node, BasicBlock *&current, CFG &cfg) {
  if (!node)
    return;

  if (node->type == "MethodDeclaration") {
    BasicBlock *block = new BasicBlock();
    block->name = "block_" + to_string(blockCount++);
    cfg.add_block(block);
    current = block;
  }

  if (node->type == "MethodDeclaration_Body") {
    Node *returnExpr = node->children.back();
    for (Node *child : node->children) {
      if (child != returnExpr)
        traverse(child, current, cfg);
    }
    string result = mathOP(returnExpr, current);
    current->instructions.push_back(new Return(result));
    return;
  }

  if (node->type == " IfElseStatement") {
    auto it = node->children.begin();
    Node *cond = *it++;
    Node *ifNode = *it++;
    Node *elseNode = *it;
    BasicBlock *condBlock;
    if (current->instructions.empty()) {
      condBlock = current;
    } else {
      condBlock = new BasicBlock();
      condBlock->name = "block_" + to_string(blockCount++);
      cfg.add_block(condBlock);
      current->trueExit = condBlock;
    }

    BasicBlock *ifBlock = new BasicBlock();
    BasicBlock *elseBlock = new BasicBlock();
    BasicBlock *mergeBlock = new BasicBlock();
    ifBlock->name = "block_" + to_string(blockCount++);
    elseBlock->name = "block_" + to_string(blockCount++);
    mergeBlock->name = "block_" + to_string(blockCount++);

    condBlock->trueExit = ifBlock;
    condBlock->falseExit = elseBlock;
    condBlock->condition =
        new ConditionalJump(mathOP(cond, condBlock), elseBlock->name);

    cfg.add_block(ifBlock);
    cfg.add_block(elseBlock);
    cfg.add_block(mergeBlock);

    BasicBlock *ifCurrent = ifBlock;
    BasicBlock *elseCurrent = elseBlock;
    traverse(ifNode, ifCurrent, cfg);
    traverse(elseNode, elseCurrent, cfg);

    ifCurrent->trueExit = mergeBlock;
    elseCurrent->trueExit = mergeBlock;
    current = mergeBlock;
    ifCurrent->instructions.push_back(new UndconditionalJump(mergeBlock->name));
    elseCurrent->instructions.push_back(
        new UndconditionalJump(mergeBlock->name));
    return;
  }

  if (node->type == "WhileStatement") {
    auto it = node->children.begin();
    Node *cond = *it++;
    Node *body = *it++;
    BasicBlock *whileCond;
    if (current->instructions.empty()) {
      whileCond = current;
    } else {
      whileCond = new BasicBlock();
      whileCond->name = "block_" + to_string(blockCount++);
      cfg.add_block(whileCond);
      current->trueExit = whileCond;
    }

    BasicBlock *whileBody = new BasicBlock();
    whileBody->name = "block_" + to_string(blockCount++);
    cfg.add_block(whileBody);

    BasicBlock *exitWhile = new BasicBlock();
    exitWhile->name = "block_" + to_string(blockCount++);
    cfg.add_block(exitWhile);

    whileCond->trueExit = whileBody;
    whileCond->falseExit = exitWhile;
    whileCond->condition =
        new ConditionalJump(mathOP(cond, whileCond), exitWhile->name);

    traverse(body, whileBody, cfg);
    whileBody->trueExit = whileCond;
    whileBody->instructions.push_back(new UndconditionalJump(whileCond->name));
    current = exitWhile;
    return;
  }

  if (node->type == "AssinedExpression") {
    auto it = node->children.begin();
    if (node->children.size() == 3) {
      Node *dest = *it++;
      Node *index = *it++;
      Node *src = *it;
      string srcVal = mathOP(src, current);
      string indexVal = mathOP(index, current);
      current->instructions.push_back(
          new ArrayCopy(dest->value, indexVal, srcVal));
    } else {
      Node *dest = *it++;
      Node *expr = *it;
      if (expr->type == "Int" || expr->type == "Str") {
        current->instructions.push_back(new Copy(expr->value, dest->value));
      } else {
        mathOP(expr, current, dest->value);
      }
    }
    return;
  }

  if (node->type == "PrintStatement") {
    if (!current)
      return;

    string expr = mathOP(node->children.front(), current);
    current->instructions.push_back(new Parameter(expr));
    current->instructions.push_back(
        new MethodCallVoid("System.out.println", "1"));
  }

  for (Node *child : node->children)
    traverse(child, current, cfg);
}

void createCFG(Node *node) {
  CFG cfg;
  BasicBlock *current = nullptr;
  traverse(node, current, cfg);
  cfg.generate_dot("cfg.dot");
}
