
//A.
#include <stdio.h>
#include <string.h>

void getString(char str[], int maxSize) {
    printf("Enter a string (max length %d): ", maxSize - 1);
    fgets(str, maxSize, stdin);
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}

void displayString(const char str[]) {
    printf("You entered: %s\n", str);
}

int main() {
    int maxSize = 100;
    char inputString[maxSize];
    getString(inputString, maxSize);
    displayString(inputString);
    return 0;
}

//B

#include <stdio.h>
#include <string.h>

int stringLength(const char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char testString[100];
    printf("Enter a string: ");
    fgets(testString, sizeof(testString), stdin);
    if (testString[strlen(testString) - 1] == '\n') {
        testString[strlen(testString) - 1] = '\0';
    }
    int length = stringLength(testString);
    printf("The length of the string is: %d\n", length);
    return 0;
}


//C

#include <stdio.h>
#include <string.h>

void stringCopy(char destination[], const char source[]) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

int main() {
    char originalString[100];
    char copiedString[100];

    printf("Enter a string to copy: ");
    fgets(originalString, sizeof(originalString), stdin);
    if (originalString[strlen(originalString) - 1] == '\n') {
        originalString[strlen(originalString) - 1] = '\0';
    }

    stringCopy(copiedString, originalString);

    printf("Original string: %s\n", originalString);
    printf("Copied string: %s\n", copiedString);

    return 0;
}

//D

#include <stdio.h>
#include <string.h>

void stringConcatenate(char destination[], const char source1[], const char source2[]) {
    int i = 0;
    int j = 0;

    while (source1[i] != '\0') {
        destination[i] = source1[i];
        i++;
    }

    while (source2[j] != '\0') {
        destination[i] = source2[j];
        i++;
        j++;
    }

    destination[i] = '\0';
}

int main() {
    char string1[50];
    char string2[50];
    char concatenatedString[100];

    printf("Enter the first string: ");
    fgets(string1, sizeof(string1), stdin);
    if (string1[strlen(string1) - 1] == '\n') {
        string1[strlen(string1) - 1] = '\0';
    }

    printf("Enter the second string: ");
    fgets(string2, sizeof(string2), stdin);
    if (string2[strlen(string2) - 1] == '\n') {
        string2[strlen(string2) - 1] = '\0';
    }

    stringConcatenate(concatenatedString, string1, string2);

    printf("String 1: %s\n", string1);
    printf("String 2: %s\n", string2);
    printf("Concatenated string: %s\n", concatenatedString);

    return 0;
}