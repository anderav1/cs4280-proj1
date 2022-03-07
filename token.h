// Lexi Anderson
//
//

#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum tokenID {
  ID_TK = 1001,
  COMM_TK = 1002,
  NUM_TK = 1003,
  KEYWD_TK = 1004,
  OP_TK = 1005,
  EOF_TK = 1006,
  ERR_TK = -1
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
