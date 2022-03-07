// Lexi Anderson
//
//

#include <iostream>

#include "scanner.h"
#include "testScanner.h"
#include "token.h"


void testScanner(std::istream &input) {
  token tkn;
  do {
    tkn = scanner(input);
  } while (tkn.type != EOF_TK);
}
