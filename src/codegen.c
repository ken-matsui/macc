#include "../include/codegen.h"

void gen_x86(Node* node) {
  if (node->ty == ND_NUM) {
    printf("  push %d\n", node->val);
    return;
  }

  gen_x86(node->lhs);
  gen_x86(node->rhs);

  printf("  pop rdi\n");
  printf("  pop rax\n");

  switch (node->ty) {
  case '+':
    printf("  add rax, rdi\n");
    break;
  case '-':
    printf("  sub rax, rdi\n");
    break;
  case '*':
    printf("  mul rdi\n");
    break;
  case '/':
    printf("  mov rdx, 0\n");
    printf("  div rdi\n");
  }

  printf("  push rax\n");
}
