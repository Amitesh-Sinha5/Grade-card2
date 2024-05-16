#include <stdio.h>
#include <string.h>
#include "student.h"

#define FILENAME "students.txt"

Student students[max_stud]; 
int numStudents = 0;

void initializeStudents() {
    loadStudentsFromFile();
}

int findStudentByName(const char *name) {
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void printReportCard(const char *name) {
    int index = findStudentByName(name);
    if (index == -1) {
        printf("Student '%s' not found.\n", name);
    } else {
        printf("Name: %s\n", students[index].name);
        printf("Roll Number: %d\n", students[index].roll_number);
        printf("Marks:\n");
        for (int i = 0; i < MAX_SUBJECTS; i++) {
            printf("Subject %d: %.2f\n", i + 1, students[index].marks[i]);
        }
        float average = calculateAverage(students[index].marks);
        students[index].grade = calculateGrade(average);
        printf("Average Marks: %.2f\n", average);
        printf("Grade: %c\n", students[index].grade);
    }
}

void addNewStudent(const char *name, int roll_number, float marks[]) {
    if (numStudents < max_stud) {
        strcpy(students[numStudents].name, name);
        students[numStudents].roll_number = roll_number;
        for (int i = 0; i < MAX_SUBJECTS; i++) {
            students[numStudents].marks[i] = marks[i];
        }
        numStudents++;
        saveStudentsToFile();
        printf("New student added successfully.\n");
    } else {
        printf("Maximum number of students reached.\n");
    }
}

void saveStudentsToFile() {
    FILE *file = fopen(FILENAME, "w");
    if (file) {
        for (int i = 0; i < numStudents; i++) {
            fprintf(file, "%s %d", students[i].name, students[i].roll_number);
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                fprintf(file, " %.2f", students[i].marks[j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
}

void loadStudentsFromFile() {
    FILE *file = fopen(FILENAME, "r");
    if (file) {
        while (fscanf(file, "%s %d", students[numStudents].name, &students[numStudents].roll_number) != EOF) {
            for (int i = 0; i < MAX_SUBJECTS; i++) {
                fscanf(file, "%f", &students[numStudents].marks[i]);
            }
            numStudents++;
        }
        fclose(file);
    }
}

float calculateAverage(const float marks[]) {
    float sum = 0.0;
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        sum += marks[i];
    }
    return sum / MAX_SUBJECTS;
}

char calculateGrade(float average) {
    if (average >= 90.0) {
        return 'A';
    } else if (average >= 80.0) {
        return 'B';
    } else if (average >= 70.0) {
        return 'C';
    } else if (average >= 60.0) {
        return 'D';
    } else {
        return 'F';
    }
}

void printClassDetails() {
    printf("\nClass Teacher: Biwas Sir\n");
    printf("College: Pes University\n");
    printf("Semester : 3rd\n");
    printf("Branch : CSE\n");
    printf("*****************************************************");
}
