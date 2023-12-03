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
			printLine();
			printf("Thank you for playing!\n");
			printLine();
			pause();
			break;
		}
		else if (menuChoice == 1) gameMain(questionSets);
		else editorMain(questionSets);
	}
}

int main() {
	srand((unsigned int) time(NULL));
	mainMenu(getQuestions());
	return 0;
}