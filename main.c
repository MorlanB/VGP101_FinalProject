#include <stdio.h>
#include <stdlib.h>
#include "helper.h"
#include "game.h"
#include "editor.h"

void title() {
	printf("--------------------------------\n");
	printf("|          Welcome to:         |\n");
	printf("|        Who Wants to Be       |\n");
	printf("|         A Millionaire        |\n");
	printf("--------------------------------\n");
}

int main() {
	char* mainMenu[] = {
		"Play the Game",
		"Question Editor"
	};

	while (1) {
		system("cls"); // clear screen
		title();
		int menuChoice = getChoices("Main Menu", mainMenu, 2, "Select a mode");
		
		system("cls"); // clear screen... again
		if (menuChoice == 0) gameMain();
		else editorMain();
	}
}