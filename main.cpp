// Lexi Anderson
//
//

#include <fstream>
#include <iostream>
#include <stdio.h>

#include "scanner.h"
#include "testScanner.h"

std::string fileName;

void printArgV(int, char*[]);


int main(int argc, char* argv[]) {
  //std::istream* fp;
  //std::istream fp;
  std::istream* fp = &std::cin;
  
  // TODO: process command line args
  if (argc == 0 || argc > 2) {
    printf("Fatal: Improper usage\nUsage:");
    printArgV(argc, argv);
    exit(1);
  }
  else if (argc == 2) {
    //readFromFile(argv[1]);
    //fp = new std::ifstream(argv[1]);
    //fp = (std::istream&) std::ifstream(argv[1]);
    //fp = std::ifstream(argv[1]);
    //std::ifstream* fp;
    std::ifstream f{argv[1]};
    fp = &f;
    //fp = &std::ifstream(argv[1]);
    //testScanner(std::ifstream(argv[1]));
    testScanner(*fp);
  }
  else if (argc == 1) {
    //readFromCin();
    //fp = (std::istream&) std::cin;
    //testScanner(std::cin);
    testScanner(*fp);
  }
  
  // TODO??
  //testScanner(fp);
  
  if (fp != &std::cin) delete fp;
  
  return 0;
}

// Print the entered command followed by line break
// argc -- argument count
// argv -- argument array
void printArgV(int argc, char* argv[]) {
  int i;
  for (i = 0; i < argc; i++) std::cout << " " << argv[i];
  std::cout << std::endl;
}
