# 
# makefile for string_utils project 
# Author: Megan Bogatz 
# 2023-10-26 
# 
  
CC = gcc 
FLAGS = -Wall -std=gnu99 -g 
INCLUDES = 
  
stringTester: string_utils.o stringTester.c 
	$(CC) $(FLAGS) string_utils.o stringTester.c -o stringTester $(INCLUDES) 
  
string_utils.o: string_utils.c string_utils.h 
	$(CC) $(FLAGS) -c string_utils.c -o string_utils.o $(INCLUDES) 
  
clean: 
	rm -Rf *~ *.o stringTester.dSYM 
