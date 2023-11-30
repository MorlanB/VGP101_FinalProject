#pragma once
extern int getInt(char* prompt);
extern int getIntRange(char* prompt, int min, int max);
extern void getString(char* prompt, char* str, int maxSize);
extern int getChoices(char* title, char** choices, int choiceCount, char* prompt);