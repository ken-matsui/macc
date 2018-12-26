#include "../include/token.h"

Token tokens[100];

// Tokenized input is stored to a tokens array.
Token* tokenize(char* p) {
  Token* tokens = malloc(sizeof(Token) * 100);
  int i = 0;
  while (*p) {
    // 空白文字をスキップ
    if (isspace(*p)) {
      p++;
      continue;
    }

    if (*p == '+' ||
        *p == '-' ||
        *p == '*' ||
        *p == '/' ||
        *p == '(' ||
        *p == ')')
    {
      tokens[i].ty = *p;
      tokens[i].input = p;
      i++;
      p++;
      continue;
    }

    if (isdigit(*p)) {
      tokens[i].ty = TK_NUM;
      tokens[i].input = p;
      tokens[i].val = strtol(p, &p, 10);
      i++;
      continue;
    }

    fprintf(stderr, "cannot tokenize: %s\n", p);
    exit(1);
  }

  tokens[i].ty = TK_EOF;
  tokens[i].input = p;
  return tokens;
}
