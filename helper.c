#include <stdio.h>

// User Input
int getInt(char* prompt) {
    int num;
    printf("%s: ", prompt);
    scanf_s("%d", &num);
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

void getString(char* prompt, char* str, int maxSize) {
    printf("%s: ", prompt);
    scanf_s(" %[^\n]s", str, maxSize);
}

int getChoices(char* title, char** choices, int choiceCount, char* prompt) {
    printf("\n%s\n", title);
    printf("------------------------------\n");
    for (int i = 0; i < choiceCount; i++) {
        printf("%d: %s\n",i+1,choices[i]);
    }
    printf("------------------------------\n");
    return getIntRange(prompt, 1, choiceCount)-1;
}