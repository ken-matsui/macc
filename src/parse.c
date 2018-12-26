#include "../include/parse.h"


static int pos = 0;

Node* new_node(int ty, Node* lhs, Node* rhs) {
  Node* node = malloc(sizeof(Node));
  node->ty = ty;
  node->lhs = lhs;
  node->rhs = rhs;
  return node;
}

Node* new_node_num(int val) {
  Node* node = malloc(sizeof(Node));
  node->ty = ND_NUM;
  node->val = val;
  return node;
}

Node* term(Token* tokens) {
  if (tokens[pos].ty == TK_NUM) {
    return new_node_num(tokens[pos++].val);
  }
  if (tokens[pos].ty == '(') {
    pos++;
    Node *node = expr(tokens);
    // Node *node = expr();
    if (tokens[pos].ty != ')') {
      error("開きカッコに対応する閉じカッコがありません: %s", tokens[pos].input);
    }
    pos++;
    return node;
  }
  error("数値でも開きカッコでもないトークンです: %s", tokens[pos].input);
}

Node* mul(Token* tokens) {
  Node *lhs = term(tokens);
  if (tokens[pos].ty == '*') {
    pos++;
    return new_node('*', lhs, mul(tokens));
  }
  if (tokens[pos].ty == '/') {
    pos++;
    return new_node('/', lhs, mul(tokens));
  }
  return lhs;
}

Node* expr(Token* tokens) {
  Node* lhs = mul(tokens);
  if (tokens[pos].ty == '+') {
    pos++;
    return new_node('+', lhs, expr(tokens));
  }
  if (tokens[pos].ty == '-') {
    pos++;
    return new_node('-', lhs, expr(tokens));
  }
  return lhs;
}

Node* parse(Token* tokens) {
  Node* node = expr(tokens);
  return node;
}
