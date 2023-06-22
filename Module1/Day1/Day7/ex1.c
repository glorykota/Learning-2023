#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char* input, struct Student students[], int* numStudents) {
    char* token;
    char temp[20];
    int i = 0;

    token = strtok((char*)input, " ");
    while (token != NULL) {
        switch (i) {
            case 0:
                students[*numStudents].rollno = atoi(token);
                break;
            case 1:
                strcpy(students[*numStudents].name, token);
                break;
            case 2:
                students[*numStudents].marks = atof(token);
                break;
        }

        i++;
        if (i > 2) {
            i = 0;
            (*numStudents)++;
            if (*numStudents >= MAX_STUDENTS) {
                return; // Reached the maximum number of students
            }
        }

        token = strtok(NULL, " ");
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;

    char input[] = "1001 Aron 100.00";

    parseString(input, students, &numStudents);

    printf("Initialized Array of Structures:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d\n", i+1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    return 0;
}
