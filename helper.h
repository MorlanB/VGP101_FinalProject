#pragma once
extern int getIntRange(char* prompt, int min, int max);
extern char* getString(char* prompt);
extern void printLine();
extern void clearScreen();
extern void pause();
extern void formatNumber(char* str, int num);
extern struct Question* selectSet(struct QuestionSet* questionSets, int setNum);
extern void printSets(struct QuestionSet* questionSets);