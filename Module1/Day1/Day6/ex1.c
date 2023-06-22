#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

double calculateVolume(struct Box *box) {
    return box->length * box->width * box->height;
}

double calculateSurfaceArea(struct Box *box) {
    return 2 * (box->length * box->width + box->width * box->height + box->height * box->length);
}

int main() {
    struct Box box;
    struct Box *boxPtr = &box;

    printf("Enter the length of the box: ");
    scanf("%lf", &(boxPtr->length));

    printf("Enter the width of the box: ");
    scanf("%lf", &(boxPtr->width));

    printf("Enter the height of the box: ");
    scanf("%lf", &(boxPtr->height));

    double volume = calculateVolume(boxPtr);
    double surfaceArea = calculateSurfaceArea(boxPtr);

    printf("Volume of the box: %.2lf\n", volume);
    printf("Total surface area of the box: %.2lf\n", surfaceArea);

    return 0;
}
