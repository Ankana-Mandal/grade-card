#include <stdio.h>
#include <string.h>
#include "average.h"
#include "grade_card.h"

// Function to calculate grades based on average scores
char calculateGrade(double average) {
    if (average >= 90.0)
        return 'A';
    else if (average >= 80.0)
        return 'B';
    else if (average >= 70.0)
        return 'C';
    else if (average >= 60.0)
        return 'D';
    else
        return 'F';
}

// Function to display the grade card table
void displayGradeCard(char names[][20], int rollNos[], char dob[][20], int marks[][5][2], double averages[][5], int key, int rollNo, const char *searchName) {
    printf("Name\tRoll No.\tDOB\t\tM-ISA 1\tM-ISA 2\tP-ISA 1\tP-ISA 2\tC-ISA 1\tC-ISA 2\tGrade\n");
    int index = -1;
    if (key == 1) {
        for (int i = 0; i < 8; i++) {
            if (rollNos[i] == rollNo) {
                index = i;
                break;
            }
        }
    } else if (key == 2) {
        for (int i = 0; i < 8; i++) {
            if (strcmp(searchName, names[i]) == 0) {
                index = i;
                break;
            }
        }
    }
    if (index != -1) {
        printf("%s\t%d\t\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%c\n", names[index], rollNos[index], dob[index],
               marks[index][0][0], marks[index][0][1], marks[index][1][0], marks[index][1][1], marks[index][2][0], marks[index][2][1], calculateGrade((averages[index][0] + averages[index][1] + averages[index][2]) / 3.0));
    } else {
            printf("no student found please type 'all' to see the list of students.\n(or)\nplease  ensure that the initial letter of 'Student' is capitalized.\n");

    }
}

int main() {
    // Arrays to store data for 8 students
    char names[8][20] = {"Liam", "Noah", "Hernandez", "Liam", "Jackson", "Isabella", "James", "Ava"};
    int rollNos[8] = {1,2,3,4,5,6,7,8};
    char dob[8][20] = {"16-JAN-2005", "12-FEB-2005", "19-MAY-2005", "19-MAY-2005", "2-MAY-2005", "11-JUNE-2005", "29-JULY-2005", "18-AUG-2005"};
    int marks[8][5][2] = {
        {{78, 80}, {78, 80}, {78, 80}, {0, 0}, {0, 0}}, 
        {{75, 85}, {76, 88}, {80, 90}, {0, 0}, {0, 0}}, 
        {{85, 88}, {82, 80}, {90, 85}, {0, 0}, {0, 0}}, 
        {{90, 92}, {88, 89}, {85, 90}, {0, 0}, {0, 0}}, 
        {{70, 75}, {68, 72}, {65, 70}, {0, 0}, {0, 0}}, 
        {{82, 84}, {78, 80}, {85, 88}, {0, 0}, {0, 0}}, 
        {{88, 90}, {85, 86}, {90, 92}, {0, 0}, {0, 0}}, 
        {{92, 95}, {90, 92}, {94, 96}, {0, 0}, {0, 0}}  
    };

    // Calculate average scores
    double averages[8][5];
    calculateAverages(marks, averages);

    // Input search criteria
    char searchOption[20];
    printf("Search by:\n1. Roll Number\n2. Name\nEnter your choice( 1 or 2): ");
    scanf("%s", searchOption);

    if (strcmp(searchOption, "1") == 0) {
        int searchRollNo;
        printf("Enter the roll number of the student whose grade you want to display: ");
        scanf("%d", &searchRollNo);
        displayGradeCard(names, rollNos, dob, marks, averages, 1, searchRollNo, NULL);
    } else if (strcmp(searchOption, "2") == 0) {
        char searchName[20];
        printf("Enter the name of the student whose grade you want to display: ");
        scanf("%s", searchName);
        displayGradeCard(names, rollNos, dob, marks, averages, 2, 0, searchName);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
