#include "Node.h"
#include "TAC_BB.h"
#include <string>

int tempCount = 0;
int blockCount = 0;

string mathOP(Node *node, BasicBlock *current, string dest = "") {
  if (node->type == "Int" || node->type == "Str")
    return node->value;
  if (node->type == "BracketsExpression")
    return mathOP(node->children.front(), current);

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

  if (node->type == " IfElseStatement") {
    auto it = node->children.begin();
    Node *cond = *it++;
    Node *ifNode = *it++;
    Node *elseNode = *it;

    BasicBlock *condBlock = new BasicBlock();
    condBlock->name = "block_" + to_string(blockCount++);
    cfg.add_block(condBlock);
    current->trueExit = condBlock;

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

    ifBlock->trueExit = mergeBlock;
    elseBlock->trueExit = mergeBlock;

    cfg.add_block(ifBlock);
    cfg.add_block(elseBlock);
    cfg.add_block(mergeBlock);

    traverse(ifNode, ifBlock, cfg);
    traverse(elseNode, elseBlock, cfg);

    current = mergeBlock;
    return;
  }

  if (node->type == "AssinedExpression") {
    auto it = node->children.begin();
    Node *dest = *it++;
    Node *expr = *it;
    if (expr->type == "Int" || expr->type == "Str") {
      current->instructions.push_back(new Copy(expr->value, dest->value));
    } else {
      mathOP(expr, current, dest->value);
    }
    return;
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
