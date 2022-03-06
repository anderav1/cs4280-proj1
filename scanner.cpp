// Lexi Anderson
//
//

#include <ctype.h>
#include <stdio.h>
#include <string>
#include "scanner.h"
#include "token.h"


const int fsaTable[10][15] = {
          /* A-Z  a-z  0-9   *   WS    &    +    /    %    .    {    }    <    -  EOF */
/* S0 */  {   6,   1,   5,   3,   0,   8,   8,   8,   8,   8,   8,   8,   9,  -1,1006 },
/* S1 */  {   2,   2,   2,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1 },
/* S2 */  {   2,   2,   2,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001 },
/* S3 */  {   3,   3,   3,   4,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3 },
/* S4 */  {1002,1002,1002,1002,1002,1002,1002,1002,1002,1002,1002,1002,1002,1002,1002 },
/* S5 */  {1003,1003,   5,1003,1003,1003,1003,1003,1003,1003,1003,1003,1003,1003,1003 },
/* S6 */  {  -1,   7,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1 },
/* S7 */  {1004,   7,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004 },
/* S8 */  {1005,1005,1005,1005,1005,1005,1005,1005,1005,1005,1005,1005,1005,1005,1005 },
/* S9 */  {  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   8,   8,  -1 },
};

// scanner
// Scan the next token
token scanner(FILE* fp, int line) {
  token tkn;

  int state = 0;
  int nextState = 0;
  
  std::string str = "";
  char curr;
  
  int col;  // FSA table column
  
  // TODO: process chars until final state
  while (state >= 0 && state < 1000) {
    curr = getc(fp);
    col = getTableCol(curr);
    
    if (col == -1) {  // invalid char
      // TODO: return error
      tkn.type = ERR_TK;
      tkn.str = "Invalid token";
      tkn.line = line;
      
      // TODO: print error message
      return tkn;
    }
    
    nextState = fsaTable[state][col];
    if (nextState >= 1000 || nextState < 0) {  // final state
      
    } else {
      
    }
  }
  
  return tkn;
}

int getTableCol(char ch) {
  if (isupper(ch) > 0) return 0;
  if (islower(ch) > 0) return 1;
  if (isdigit(ch) > 0) return 2;
  if (ch == '*') return 3;
  if (isspace(ch) > 0) return 4;
  
  if (ch == '&') return 5;
  if (ch == '+') return 6;
  if (ch == '/') return 7;
  if (ch == '%') return 8;
  if (ch == '.') return 9;
  if (ch == '{') return 10;
  if (ch == '}') return 11;
  if (ch == '<') return 12;
  if (ch == '-') return 13;
  
  if (ch == EOF) return 14;
  
  return -1;
}
