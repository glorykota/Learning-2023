#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void searchStudentByName(const struct Student students[], int numStudents, const char *searchName) {
    int found = 0;

    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("Student found:\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with name '%s' not found.\n", searchName);
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 5;

    // Assume the students array is already populated with data

    char searchName[20];
    printf("Enter the name of the student to search: ");
    scanf("%s", searchName);

    // Perform search operation based on name
    searchStudentByName(students, numStudents, searchName);

    return 0;
}
