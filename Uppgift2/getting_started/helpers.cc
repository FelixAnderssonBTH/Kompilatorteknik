#include "Node.h"

string get_str_type(Node *it) {

  if (it && it->value == "Identifier" && !it->children.empty()) {
    return it->children.front()->value;
  }
  return it ? it->value : "unknown";
}
