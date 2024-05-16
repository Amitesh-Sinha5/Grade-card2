#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME_LENGTH 50
#define MAX_SUBJECTS 5
#define max_stud 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int roll_number;
    float marks[MAX_SUBJECTS];
    char grade;
} Student;

void initializeStudents();
int findStudentByName(const char *name);
void printReportCard(const char *name);
void addNewStudent(const char *name, int roll_number, float marks[]);
void saveStudentsToFile();
void loadStudentsFromFile();
float calculateAverage(const float marks[]);
char calculateGrade(float average);
void printClassDetails();

#endif
