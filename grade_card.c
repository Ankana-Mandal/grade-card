#include <stdio.h>

void generateGradeCard(char names[][20], int rollNos[], char dob[][12], int marks[][5][2]) {
    printf("Name\tRoll No.\tDOB\t\tM-ISA 1\tM-ISA 2\tP-ISA 1\tP-ISA 2\tC-ISA 1\tC-Exam2\n");
    for (int i = 0; i < 8; i++) {
        printf("%s\t%d\t\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", names[i], rollNos[i], dob[i], 
               marks[i][0][0], marks[i][0][1], marks[i][1][0], marks[i][1][1], marks[i][2][0], marks[i][2][1]);
    }
}