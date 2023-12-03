#pragma once
extern int getInt(char* prompt);
extern int getIntRange(char* prompt, int min, int max);
extern char* getString(char* prompt);
extern void printLine();
extern void clearScreen();
extern void pause();
extern void formatNumber(char* str, int num);