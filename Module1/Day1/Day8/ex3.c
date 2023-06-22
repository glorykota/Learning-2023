#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct LogEntry {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
};

void extractLogEntries(struct LogEntry logEntries[], int *numEntries) {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening data file.\n");
        return;
    }

    char line[100];
    char *token;

    // Skip the header line
    fgets(line, sizeof(line), file);

    // Read each line and extract the log entry
    *numEntries = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        token = strtok(line, ",");
        logEntries[*numEntries].entryNo = atoi(token);

        token = strtok(NULL, ",");
        strcpy(logEntries[*numEntries].sensorNo, token);

        token = strtok(NULL, ",");
        logEntries[*numEntries].temperature = atof(token);

        token = strtok(NULL, ",");
        logEntries[*numEntries].humidity = atoi(token);

        token = strtok(NULL, ",");
        logEntries[*numEntries].light = atoi(token);

        token = strtok(NULL, ",");
        strcpy(logEntries[*numEntries].time, token);

        (*numEntries)++;
    }

    fclose(file);
}

void displayLogEntries(struct LogEntry logEntries[], int numEntries) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTime\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%d\t%s\t\t%.1f\t\t%d\t\t%d\t%s\n",
               logEntries[i].entryNo,
               logEntries[i].sensorNo,
               logEntries[i].temperature,
               logEntries[i].humidity,
               logEntries[i].light,
               logEntries[i].time);
    }
}

int main() {
    struct LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;

    extractLogEntries(logEntries, &numEntries);
    displayLogEntries(logEntries, numEntries);

    return 0;
}
