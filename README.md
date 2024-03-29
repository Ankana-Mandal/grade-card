# grade-card
semester-2 case study

main.c: his file contains the main function and user interface logic.

average.h: Header file containing the function prototype for the calculateAverages function

average.c: Source file containing the implementation of the calculateAverages function.

grade_card.h: Header file containing the function prototype for the generateGradeCard function, used to display the grade card for students.

grade_card.c: Source file containing the implementation of the generateGradeCard function.

makefile.mak: Makefile for compiling the program with multiple source files.

How to Compile and Run: make

                        gcc -Wall -Wextra -std=c99 -o grade_card main.c average.c grade_card.c
                        
                        ./grade_card
                        
                        
