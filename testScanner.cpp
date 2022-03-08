// Lexi Anderson
// CS4280, Proj 1
// testScanner.cpp

#include <iostream>
#include <map>

#include "scanner.h"
#include "testScanner.h"
#include "token.h"

// Stand-in for parser
// Runs the scanner on the input stream until stream is exhausted or error is reached
// input -- input stream (either a file or cin)
void testScanner(std::istream &input) {
  token tkn;
  
  std::cout << "Token type -- Instance -- Line #" << std::endl;
  
  do {
    tkn = scanner(input);
    printToken(tkn);
    
    if (tkn.type == EOF_TK) return;
  } while (tkn.type != ERR_TK);

  if (tkn.type == ERR_TK) {
    std::cout << "SCANNER ERROR: \"" << tkn.str << "\" on line " << tkn.line << std::endl;
    exit(1);
  }
}

// Prints info about the token to cout: type of token, instance, line number
// tkn -- the token to print
void printToken(token tkn) {
  std::map<tokenID, std::string>::const_iterator type = tokenNames.find(tkn.type);
  if (type != tokenNames.end()) std::cout << type->second << " -- \'" << tkn.str << "\' -- " << tkn.line << std::endl;
}
