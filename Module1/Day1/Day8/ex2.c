#include <stdio.h>
#include <string.h>
#include <ctype.h>

void changeToUpperCase(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void changeToLowerCase(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

void changeToSentenceCase(char *str) {
    int len = strlen(str);

    if (len > 0) {
        // Convert first character to uppercase
        *str = toupper((unsigned char)*str);

        // Convert remaining characters to lowercase
        for (int i = 1; i < len; i++) {
            str[i] = tolower((unsigned char)str[i]);
        }
    }
}

void copyFileWithCaseHandling(const char *sourceFileName, const char *destinationFileName, char option) {
    FILE *sourceFile, *destinationFile;
    char ch;

    // Open the source file in read mode
    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Error opening the source file.\n");
        return;
    }

    // Open the destination file in write mode
    destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Error opening the destination file.\n");
        fclose(sourceFile);
        return;
    }

    // Copy the contents from source file to destination file with case handling
    while ((ch = fgetc(sourceFile)) != EOF) {
        if (option == 'u') {
            fputc(toupper((unsigned char)ch), destinationFile);
        } else if (option == 'l') {
            fputc(tolower((unsigned char)ch), destinationFile);
        } else if (option == 's') {
            static int sentenceStart = 1;

            if (sentenceStart && isalpha(ch)) {
                fputc(toupper((unsigned char)ch), destinationFile);
                sentenceStart = 0;
            } else {
                fputc(tolower((unsigned char)ch), destinationFile);

                if (ch == '.' || ch == '?' || ch == '!') {
                    sentenceStart = 1;
                }
            }
        } else {
            fputc(ch, destinationFile);
        }
    }

    // Close the files
    fclose(sourceFile);
    fclose(destinationFile);

    printf("File copied successfully with case handling.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp <option> <source_file> <destination_file>\n");
        printf("Options: -u (Uppercase)  -l (Lowercase)  -s (Sentence case)\n");
        return 1;
    }

    char option = argv[1][1];
    const char *sourceFileName = argv[2];
    const char *destinationFileName = argv[3];

    copyFileWithCaseHandling(sourceFileName, destinationFileName, option);

    return 0;
}
