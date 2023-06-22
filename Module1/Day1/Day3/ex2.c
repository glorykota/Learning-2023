#include <stdio.h>

void printBits(unsigned int num) {
    int bitCount = sizeof(num) * 8;
    unsigned int mask = 1 << (bitCount - 1);

    for (int i = 0; i < bitCount; i++) {
        if (num & mask)
            printf("1");
        else
            printf("0");

        mask >>= 1;
    }

    printf("\n");
}

int main() {
    unsigned int num;
    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);

    printf("Binary representation: ");
    printBits(num);

    return 0;
}
