#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "helper.h"
#include "game.h"
#include "editor.h"
#include "questions.h"

void title() {
	printf("--------------------------------\n");
	printf("|          Welcome to:         |\n");
	printf("|        Who Wants to Be       |\n");
	printf("|         A Millionaire        |\n");
	printf("--------------------------------\n");
	printf("Created by: Benjamin, Haoxi, Lucas, Morlan, & Narda\n");
}

struct Question* selectQuestionSet(struct QuestionSet* questionSets) {
	int sets = 2;

	// Header
	clearScreen();
	printf("Question Sets\n");
	printLine();
	
	// Print question sets
	int totalSets = 0;
	struct QuestionSet* current = questionSets;
	while(current != NULL) {
		printf("%d: %s\n", ++totalSets, current->creator);
		current = current->next;
	}
	printLine();

	// Select a set
	int setNum = getIntRange("Select a set (press 0 to return to menu)", 0, totalSets);
	if (setNum == 0) return NULL;
	for(int i = 1; i < setNum; i++) {
		questionSets = questionSets->next;
	}
	clearScreen();

	return questionSets->questions;
}

void mainMenu(struct QuestionSet* questionSets) {
	while (1) {
		clearScreen();
		title();
		printf("\nMain Menu\n");
		printLine();
		printf("1: Play the Game\n");
		printf("2: Question Editor\n");
		printLine();
		int menuChoice = getIntRange("Select a mode (press 0 to quit)", 0, 2);

		clearScreen();
		if (menuChoice == 0) {
			// We're done here
			printLine();
			printf("Thank you for playing!\n");
			printLine();
			pause();
			return;
		}

		// Select a question set
		struct Question* questions = selectQuestionSet(questionSets);
		if (questions == NULL) continue;
		if (menuChoice == 1) gameMain(questions);
		else editorMain(questions);
	}
}

int main() {
	srand((unsigned int) time(NULL));
	mainMenu(getQuestions());
	return 0;
}