#include <stdio.h>

#define MAX_STUDENTS 10

struct Student {
    int rollno;
    char name[20];
    float marks;
};

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
    int numStudents = 3;

    // Assume the students array is already populated with data

    // Display all members of the array of structures
    displayStudents(students, numStudents);

    return 0;
}
