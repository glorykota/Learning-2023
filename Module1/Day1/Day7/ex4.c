#include <stdio.h>

#define MAX_STUDENTS 10

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void sortStudentsByMarks(struct Student students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                // Swap the positions of students[j] and students[j+1]
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void displayStudents(const struct Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 5;

    // Assume the students array is already populated with data

    // Sort the array of structures by marks in descending order
    sortStudentsByMarks(students, numStudents);

    // Display all members of the sorted array of structures
    displayStudents(students, numStudents);

    return 0;
}
