#include <stdio.h>

typedef struct {
    int field1;
    float field2;
    char field3;
} MyStruct;

void swapFields(MyStruct *struct1, MyStruct *struct2) {
    MyStruct temp;

    // Swap field1
    temp.field1 = struct1->field1;
    struct1->field1 = struct2->field1;
    struct2->field1 = temp.field1;

    // Swap field2
    temp.field2 = struct1->field2;
    struct1->field2 = struct2->field2;
    struct2->field2 = temp.field2;

    // Swap field3
    temp.field3 = struct1->field3;
    struct1->field3 = struct2->field3;
    struct2->field3 = temp.field3;
}

int main() {
    MyStruct struct1, struct2;

    // Initialize struct1
    struct1.field1 = 10;
    struct1.field2 = 3.14;
    struct1.field3 = 'A';

    // Initialize struct2
    struct2.field1 = 20;
    struct2.field2 = 2.71;
    struct2.field3 = 'B';

    printf("Before swapping:\n");
    printf("struct1: field1 = %d, field2 = %.2f, field3 = %c\n", struct1.field1, struct1.field2, struct1.field3);
    printf("struct2: field1 = %d, field2 = %.2f, field3 = %c\n", struct2.field1, struct2.field2, struct2.field3);

    // Swap the fields of struct1 and struct2
    swapFields(&struct1, &struct2);

    printf("\nAfter swapping:\n");
    printf("struct1: field1 = %d, field2 = %.2f, field3 = %c\n", struct1.field1, struct1.field2, struct1.field3);
    printf("struct2: field1 = %d, field2 = %.2f, field3 = %c\n", struct2.field1, struct2.field2, struct2.field3);

    return 0;
}
