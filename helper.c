#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

// User Input
int getInt(char* prompt) {
    int num;
    printf("%s: ", prompt);
    while (scanf_s("%d", &num) != 1) {
        while (getchar() != '\n');
        printf("Error: Invalid input\n%s: ", prompt);
    }
    return num;
}

int getIntRange(char* prompt, int min, int max) {
    int result;
    while(1) {
        result = getInt(prompt);
        if (result < min || result > max) {
            printf("Error: Out of range\n");
        } else {
            break;
        }
    }
    return result;
}

char* getString(char* prompt) {
    char* str = (char*) malloc(100);
    printf("%s: ", prompt);
    scanf_s(" %[^\n]s", str, 100);
    return str;
}

void printLine() {
    printf("------------------------------\n");
}

void clearScreen() {
	system("cls");
}

void pause() {
	system("pause");
}

void formatNumber(char* str, int num) {
    if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }

    int strIndex = 0;
    int digitCount = 0;

    // add commas
    while (num > 0) {
        if (digitCount++ == 3) {
            str[strIndex++] = ',';
            digitCount = 0;
        }
        else {
            str[strIndex++] = (num % 10) + '0';
            num /= 10;
        }
    }

    // reverse string
    for (int i = 0; i < strIndex / 2; i++) {
        char temp = str[i];
        str[i] = str[strIndex - i - 1];
        str[strIndex - i - 1] = temp;
    }
    str[strIndex] = '\0';
}

void printSets(struct QuestionSet* questionSets) {
    clearScreen();
    printf("Question Sets\n");
    printLine();
    printf("\n");

    // Print question sets
    struct QuestionSet* current = questionSets;
    int setNum = 1;
    while (current != NULL) {
		printf("%d: %s's set\n", setNum++, current->creator);
		current = current->next;
	}
    printLine();
}