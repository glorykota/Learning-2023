#include <stdio.h>

typedef struct {
    int hours;
    int minutes;
    int seconds;
} TimePeriod;

void getTimePeriod(TimePeriod *tp) {
    printf("Enter the time period:\n");
    printf("Hours: ");
    scanf("%d", &(tp->hours));
    printf("Minutes: ");
    scanf("%d", &(tp->minutes));
    printf("Seconds: ");
    scanf("%d", &(tp->seconds));
}

void printTimePeriod(TimePeriod tp) {
    printf("Time Period: %d hours, %d minutes, %d seconds\n", tp.hours, tp.minutes, tp.seconds);
}

TimePeriod calculateDifference(TimePeriod tp1, TimePeriod tp2) {
    TimePeriod diff;
    int totalSeconds1, totalSeconds2, diffSeconds;

    totalSeconds1 = tp1.hours * 3600 + tp1.minutes * 60 + tp1.seconds;
    totalSeconds2 = tp2.hours * 3600 + tp2.minutes * 60 + tp2.seconds;

    diffSeconds = totalSeconds1 - totalSeconds2;

    diff.hours = diffSeconds / 3600;
    diff.minutes = (diffSeconds % 3600) / 60;
    diff.seconds = (diffSeconds % 3600) % 60;

    return diff;
}

int main() {
    TimePeriod tp1, tp2, difference;

    printf("Enter the first time period:\n");
    getTimePeriod(&tp1);

    printf("\nEnter the second time period:\n");
    getTimePeriod(&tp2);

    printf("\n");

    printf("First time period:\n");
    printTimePeriod(tp1);

    printf("Second time period:\n");
    printTimePeriod(tp2);

    printf("\n");

    difference = calculateDifference(tp1, tp2);

    printf("Difference between the two time periods:\n");
    printTimePeriod(difference);

    return 0;
}
