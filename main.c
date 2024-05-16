#include <stdio.h>
#include "student.h"

int main() {
    initializeStudents();

    char name[MAX_NAME_LENGTH];
    printf("Enter student name: ");
    scanf("%s", name);

    int index = findStudentByName(name);
    if (index == -1) {
        printf("Student not found. Adding new student...\n");
        int roll_number;
        float marks[MAX_SUBJECTS];
        printf("Enter roll number: ");
        scanf("%d", &roll_number);
        printf("Enter marks for 5 subjects:\n");
        for (int i = 0; i < MAX_SUBJECTS; i++) {
            printf("Subject %d: ", i + 1);
            scanf("%f", &marks[i]);
        }
        addNewStudent(name, roll_number, marks);
    } else {
        printReportCard(name);
    }

    printClassDetails();

    return 0;
}

