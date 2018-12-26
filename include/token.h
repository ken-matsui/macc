#ifndef __TOKEN_H__
#define __TOKEN_H__

#include "common.h"

enum {
  TK_NUM = 256, // Number literal
  TK_EOF,       // End marker
};

typedef struct {
  int ty;      // Token type
  int val;     // Number literal
  char* input; // Token string (for error reporting)
} Token;

Token* tokenize(char* p);

#endif
