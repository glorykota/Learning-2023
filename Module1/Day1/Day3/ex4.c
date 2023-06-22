#include <stdio.h>

void findSmallestLargestDigits(int n, ...) {
    va_list args;
    va_start(args, n);

    int smallestDigit = 9;
    int largestDigit = 0;

    for (int i = 0; i < n; i++) {
        int num = va_arg(args, int);
        int temp = num;

        while (temp > 0) {
            int digit = temp % 10;
            if (digit < smallestDigit)
                smallestDigit = digit;
            if (digit > largestDigit)
                largestDigit = digit;
            temp /= 10;
        }
    }

    va_end(args);

    if (smallestDigit == largestDigit)
        printf("Not Valid\n");
    else
        printf("Smallest Digit: %d\nLargest Digit: %d\n", smallestDigit, largestDigit);
}

int main() {
    int n = 3;
    int n1 = 8, n2 = 156, n3 = 123450;

    findSmallestLargestDigits(n, n1, n2, n3);

    return 0;
}
