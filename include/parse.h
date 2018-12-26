#ifndef __PARSE_H__
#define __PARSE_H__

#include "macc.h"
#include "token.h"

enum {
  ND_NUM = 256,     // Number literal
};

typedef struct Node {
  int ty;           // Node type
  struct Node* lhs; // left-hand side
  struct Node* rhs; // right-hand side
  int val;          // Number literal
} Node;

Node* new_node(int ty, Node* lhs, Node* rhs);
Node* new_node_num(int val);
Node* mul();
// Node* mul(Token* tokens);
Node* expr();
// Node* expr(Token* tokens);
Node* term();
// Node* term(Token* tokens);
Node* parse();
// Node* parse(Token* tokens);

#endif
