// Lexi Anderson
//
//

#ifndef SCANNER_H
#define SCANNER_H

#include "token.h"

token scanner(FILE* fp, int line);
int getTableCol(char ch);


#endif
