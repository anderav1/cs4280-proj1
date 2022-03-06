// Lexi Anderson
//
//

#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum tokenID {
  ID_TK,
  COMM_TK,
  NUM_TK,
  KEYWD_TK,
  OP_TK,
  EOF_TK,
  ERR_TK
};

const std::string tokenNames[] = {
  "Identifier",
  "Comment",
  "Number",
  "Keyword",
  "Operator",
  "EOF",
  "Error"
};

// Respective int values for each final state
// All final states < 0 or > 1000
const int finalStates[] = {
  1001,
  1002,
  1003,
  1004,
  1005,
  1006,
  -1
};

typedef struct {
  tokenID type;
  std::string str;
  int line;
} token;

const std::string keywords[] = {
  "Again",
  "If", 
  "Assign", 
  "Move", 
  "Show", 
  "Flip", 
  "Name", 
  "Home", 
  "Do", 
  "Spot", 
  "Place", 
  "Here", 
  "There"
};

#endif
