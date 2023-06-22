#include <stdio.h>

int countSetBits(int number) {
    int count = 0;
    while (number > 0) {
        count += number & 1;
        number >>= 1;
    }
    return count;
}

int main() {
    int array[] = {0x1, 0xF4, 0x10001};
    int size = sizeof(array) / sizeof(array[0]);
    int totalSetBits = 0;

    for (int i = 0; i < size; i++) {
        totalSetBits += countSetBits(array[i]);
    }

    printf("Total number of set bits: %d\n", totalSetBits);

    return 0;
}
