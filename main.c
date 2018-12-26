#include "include/macc.h"
#include "include/codegen.h"
#include "include/parse.h"
#include "include/token.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: macc <code>\n");
    return 1;
  }

  // Tokenize and parse.
  Token* tokens = tokenize(argv[1]);
  Node* node = parse(tokens);

  fprintf(stderr, "%d", node->ty);

  // Output the first part of the assembly. 
  printf(".intel_syntax noprefix\n");

#ifdef __APPLE__
  printf(".global _main\n");
  printf("_main:\n");
#else
  printf(".global main\n");
  printf("main:\n");
#endif

  // 抽象構文木を下りながらコード生成
  gen_x86(node);

  // スタックトップに式全体の値が残っているはずなので
  // それをRAXにロードして関数からの返り値とする
  printf("  pop rax\n");
  printf("  ret\n");
  return 0;
}
