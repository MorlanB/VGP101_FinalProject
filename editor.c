#include <stdio.h>
#include <stdlib.h>
#include "helper.h"
#include "questions.h"

void printQuestions(struct Question* questions) {
	int questionNum = 1;
	while(questions != NULL) {
		printf("%d: %s\n", questionNum, questions->question);
		questions = questions->next;
		questionNum++;
	}
}

void resetQuestionOrder(struct Question* questions) {
	while (questions != NULL) {
		if (questions->correctAnswer != 0) {
			char* temp = questions->choices[0];
			questions->choices[0] = questions->choices[questions->correctAnswer];
			questions->choices[questions->correctAnswer] = temp;
			questions->correctAnswer = 0;
		}
		questions = questions->next;
	}
}

void editQuestion(struct Question* question, int questionNum) {
	while (1) {
		clearScreen();
		printf("Editing question %d\n", questionNum);
		printLine();

		// Print the current question
		printf("\n1: Question: %s\n", question->question);
		printf("2: Answer: %s\n", question->choices[0]);
		for (int i = 1; i <= 3; i++) {
			printf("%d: Wrong Answer %d: %s\n", i + 2, i, question->choices[i]);
		}
		printf("6: Friend Hint: %s\n", question->phoneAFriend);
		printLine();

		// Ask the user what they want to edit
		int choice = getIntRange("\nWhat would you like to edit (press 0 to exit)", 0, 6);

		switch (choice) {
			case 0: {
				return;
			} break;
			case 1: {
				question->question = getString("Enter the new question");
			} break;
			case 2: {
				question->choices[0] = getString("Enter the new answer");
			} break;
			case 6: {
				question->phoneAFriend = getString("Enter the new friend hint");
			} break;
			default: {
				question->choices[choice - 2] = getString("Enter a new wrong choice");
			} break;
		}
	}
}

void editorMain(struct Question* questions) {
	resetQuestionOrder(questions);
	while (1) {
		clearScreen();
		printf("Welcome to the editor!\n");
		printLine();
		printQuestions(questions);
		printLine();

		int choice = getIntRange("\nWhich question would you like to edit (press 0 to exit)", 0, 15);

		if (choice == 0) {
			return;
		}

		struct Question* current = questions;
		for (int i = 1; i < choice; i++) {
			current = current->next;
		}

		editQuestion(current, choice);
	}
}