#include <stdio.h>
#include <stdlib.h>
#include "questions.h"
#include "helper.h"

#define FIFTY_FIFTY 0
#define PHONE_A_FRIEND 1
#define ASK_THE_AUDIENCE 2

void shuffleChoices(struct Question* question) {
	for (int i = 0; i < 1; i++) {
		int randomIndex = rand() % 4;
		char* temp = question->choices[i];
		question->choices[i] = question->choices[randomIndex];
		question->choices[randomIndex] = temp;
		if (i == question->correctAnswer) question->correctAnswer = randomIndex;
		else if (randomIndex == question->correctAnswer) question->correctAnswer = i;
	}
}

void setAudienceVotes(int audienceVotes[], int correctAnswer) {
	int totalVotes = 0;
	for (int i = 0; i < 4; i++) {
		audienceVotes[i] = rand() % 100;
		if (audienceVotes[i] < 50) {
			// Correct answer
			if (i == correctAnswer) audienceVotes[i] += 50;
		}
		else {
			// Wrong answer
			if (i != correctAnswer) audienceVotes[i] -= 50;
		}
		totalVotes += audienceVotes[i];
	}
}

void askQuestion(struct Question* question, int questionNumber, int score, int hasLifeline[], int audienceVotes[], int wrongAnswerToKeep) {
	// Format money
	char money[10];
	formatNumber(money, score);
	
	// Ask question
	printf("Question %d / 15\n", questionNumber + 1);
	printf("Money: $%s\n", money);
	printLine();

	// Print questions and choices
	printf("\n%s\n", question->question);
	printLine();
	for (int i = 0; i < 4; i++) {
		if (hasLifeline[FIFTY_FIFTY] == 2 && i != question->correctAnswer && i != wrongAnswerToKeep) {
			continue;
		}
		if (hasLifeline[ASK_THE_AUDIENCE] == 2) {
			printf("%d: %s (%d%%)\n", i + 1, question->choices[i], audienceVotes[i]);
		}
		else {
			printf("%d: %s\n", i + 1, question->choices[i]);
		}
	}
	printLine();

	// Print lifelines
	printf("\nLifelines:\n");
	printf("5. 50/50 (%s)\n", hasLifeline[FIFTY_FIFTY] == 1 ? "Available" : "Used");
	printf("6. Phone a Friend (%s)\n", hasLifeline[PHONE_A_FRIEND] == 1 ? "Available" : "Used");
	printf("7. Ask the Audience (%s)\n", hasLifeline[ASK_THE_AUDIENCE] == 1 ? "Available" : "Used");
	printLine();
}

int getUserChoice(int hasLifeline[], int correctChoice, int wrongAnswerToKeep) {
	while (1) {
		int choice = getIntRange("Select an answer (0 to quit)", 0, 7);
		if (choice == 0) return choice;
		if (choice <= 4) {
			if (hasLifeline[FIFTY_FIFTY] != 2 || choice == correctChoice + 1 || choice == wrongAnswerToKeep + 1) {
				return choice;
			}
		}
		if (choice == 5 && hasLifeline[FIFTY_FIFTY] == 1) return choice;
		if (choice == 6 && hasLifeline[PHONE_A_FRIEND] == 1) return choice;
		if (choice == 7 && hasLifeline[ASK_THE_AUDIENCE] == 1) return choice;
		printf("Error: Invalid choice\n");
	}
}

void endGame(char* message, int score) {
	char money[10];
	formatNumber(money, score);

	clearScreen();
	printLine();
	printf("%s\n", message);
	printf("You have won $%s!\n", money);
	printLine();
}

void correctQuestion(int score) {
	char money[10];

	printf("\n");
	printLine();
	printf("You are correct!\n");
	formatNumber(money, score);
	printf("Your total score is $%s!\n", money);
	printLine();

	pause();
}

void failQuestion(int guaranteedMoney) {
	char money[10];
	printf("\n");
	printLine();
	printf("YOU ARE WRONG!!! HAHAHAHAHAHAHA!\n");
	if (guaranteedMoney == 0) {
		printf("ALL YOUR MONEY IS GONE!!! You get nothing!\n");
	}
	else {
		formatNumber(money, guaranteedMoney);
		printf("All you get is $%s!\n", money);
	}
	printf("Now go away!\n");
	printLine();
}

void gameMain(struct Question* question) {
	// Initialize game
	const int moneyPerRound[16] = { 0, 500, 1000, 2000, 3000, 5000, 7500, 10000, 15000, 25000, 50000, 75000, 150000, 250000, 500000, 1000000 };

	// Lifelines
	int hasLifeline[3] = { 1, 1, 1 }; // 1 = available, 2 = in use, 0 = used
	int audienceVotes[4] = { 0, 0, 0, 0 };
	int wrongAnswerToKeep = 0;

	// More variables
	int guaranteedMoney = 0;
	int questionNumber = 0;

	// Start game loop
	while (question != NULL) {
		if (hasLifeline[0] != 2 && hasLifeline[1] != 2 && hasLifeline[2] != 2) {
			// If no lifelines are in use, shuffle choices, set audience votes, and select a random wrong answer to keep
			shuffleChoices(question);
			setAudienceVotes(audienceVotes, question->correctAnswer);
			wrongAnswerToKeep = ((rand() % 3) + question->correctAnswer + 1) % 4;
		}

		// Ask question
		askQuestion(question, questionNumber, moneyPerRound[questionNumber], hasLifeline, audienceVotes, wrongAnswerToKeep);

		// Use lifeline
		if (hasLifeline[PHONE_A_FRIEND] == 2) {
			printf("\nPHONE A FRIEND:\n%s\n", question->phoneAFriend);
			printLine();
		}

		// Get answer
		int choice = getUserChoice(hasLifeline, question->correctAnswer, wrongAnswerToKeep);

		// Check answer
		if (choice == 0) {
			// Quit
			endGame("Thank you for playing", moneyPerRound[questionNumber]);
			break;
		}
		else if (choice >= 5) {
			// Life lines
			hasLifeline[choice - 5] = 2;
		}
		else if (choice - 1 == question->correctAnswer) {
			// Correct
			if (questionNumber == 14) {
				// Game over
				endGame("Congratulations! You have won the game!", moneyPerRound[questionNumber+1]);
				break;
			}
			else {
				if (questionNumber % 5 == 4) guaranteedMoney = moneyPerRound[questionNumber + 1];

				// Print score
				correctQuestion(moneyPerRound[questionNumber + 1]);

				// Check lifelines
				for (int i = 0; i < 3; i++) {
					if (hasLifeline[i] == 2) hasLifeline[i] = 0;
				}

				// Next question
				questionNumber++;
				question = question->next;
			}
		}
		else {
			// Wrong
			failQuestion(guaranteedMoney);
			break;
		}
		clearScreen();
	}
	pause();
}