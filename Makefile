# Lexi Anderson
#
#


CC = g++
CFLAGS = -g -Wall -std=c++11
OBJS = main.o testScanner.o scanner.o
DEPS = testScanner.h scanner.h token.h
TARGET = scanner

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
  
$(OBJS): %.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<
  

# clean up generated files
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
  
  
