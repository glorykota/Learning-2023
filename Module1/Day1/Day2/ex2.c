#include <stdio.h>

void swap(void* ptr1, void* ptr2, size_t size) {
    char* temp = (char*)malloc(size);
    memcpy(temp, ptr1, size);
    memcpy(ptr1, ptr2, size);
    memcpy(ptr2, temp, size);
    free(temp);
}

int main() {
    int a = 10, b = 20;
    printf("Before swapping: a = %d, b = %d\n", a, b);

    swap(&a, &b, sizeof(int));
    printf("After swapping: a = %d, b = %d\n", a, b);

    double x = 3.14, y = 2.71;
    printf("Before swapping: x = %lf, y = %lf\n", x, y);

    swap(&x, &y, sizeof(double));
    printf("After swapping: x = %lf, y = %lf\n", x, y);

    char c1 = 'A', c2 = 'B';
    printf("Before swapping: c1 = %c, c2 = %c\n", c1, c2);

    swap(&c1, &c2, sizeof(char));
    printf("After swapping: c1 = %c, c2 = %c\n", c1, c2);

    return 0;
}
