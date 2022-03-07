// Lexi Anderson
//
//

#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>

#include "token.h"

token scanner(std::istream &input);
int getTableCol(char ch);


#endif
