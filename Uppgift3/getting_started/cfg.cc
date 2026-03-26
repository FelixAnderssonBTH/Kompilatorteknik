#include "TAC_BB.h"

int main() {
  CFG cfg;

  BasicBlock *b0 = new BasicBlock();
  b0->name = "block_0";

  BasicBlock *b1 = new BasicBlock();
  b1->name = "block_1";
  b1->instructions.push_back(new Expression("<", "x", "1", "t1"));
  b1->condition = new ConditionalJump("t1", "block_3");

  BasicBlock *b2 = new BasicBlock();
  b2->name = "block_2";
  b2->instructions.push_back(new Copy("b", "a"));

  BasicBlock *b3 = new BasicBlock();
  b3->name = "block_3";

  // link exits
  b0->trueExit = b1;
  b1->trueExit = b2;
  b1->falseExit = b3;
  b2->trueExit = b1;

  cfg.add_block(b0);
  cfg.add_block(b1);
  cfg.add_block(b2);
  cfg.add_block(b3);

  cfg.generate_dot("cfg.dot");
  cout << "Done!" << endl;

  return 0;
}
