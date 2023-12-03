#include <stdio.h>
#include <stdlib.h>
#include "questions.h"

struct Question* convertToLinkedList(char* questionsAndAnswers[]);

struct Question* getQuestions() {
	char* questionsAndAnswers[15 * 6] = {
		// Question 1
		"In the base-10 (decimal) number system, how many digits are there?",
			"10", "9", "8", "Infinite",
			"Explore the fundamental properties of the decimal system. How many digits make up the base-10 number system?",
		// Question 2
		"What is the currency of Canada?",
			"Canadian Dollar", "Euro", "Pound Sterling", "Yen",
			"Explore global currencies. Can you identify the official currency of Canada?",
		// Question 3
		"How many times can you subtract 10 from 100?",
			"As many as you want", "Once", "5 times", "10 times",
			"A mind-bending question that might subtract a bit of confidence!",
		// Question 4
		"How many holes are there in a straw?",
			"2", "1", "None", "Infinite",
			"A straw's secret holes may surprise you. Drink carefully!",
		// Question 5
		"Can a match box?",
			"No, but a tin can", "Yes, if it's big enough", "Only on Wednesdays", "Depends on the weather",
			"This one sparks a bit of wordplay. Watch out for a fiery twist!",
		// Question 6
		"What's the square root of a negative pizza?",
			"Pizza can't have a square root", "i", "Cheese", "Sausage",
			"Things are getting irrational. Hold on to your toppings!",
		// Question 7
		"What's the airspeed velocity of an unladen swallow?",
			"What do you mean? An African or European swallow?", "25 miles per hour", "50 miles per hour", "100 miles per hour",
			"This question requires a bit of Monty Python knowledge and avian aerodynamics. It's a real challenge!",
		// Question 8
		"If a tree falls in a forest and no one is around to hear it, does it make a sound?",
			"Yes", "No", "It sends a text message instead", "The forest is a silent disco",
			"A philosophical pondering with a modern twist. Trees might be more tech-savvy than you think!",
		// Question 9
		"How many jellybeans can fit in your dreams?",
			"An infinite amount", "The number is constantly changing", "Only if they're sugar-free", "7",
			"This question is a sweet journey into the realm of dreamy confections!",
		// Question 10
		"How do you catch a time-traveling fish?",
			"Use a wormhole", "Set your reel to the year 3019", "Wait until it's asleep", "With a clock net",
			"The answer involves thinking fourth-dimensionally.",
		// Question 11
		"What's the output of the following C code: printf('%c', 'A' + 1);?",
			"The character 'B'", "'A' + 1", "Compiler error", "66",
			"This ASCII-centric question adds a numeric twist to character manipulation in C. Can you decipher the output?",
		// Question 12
		"Consider the following C code: int x = 10; printf('%d', x++ + ++x); What's the value of x?",
			"22", "13", "14", "Undefined behavior",
			"This incrementing question takes you on a wild ride through C code. Can you catch the final value of x?",
		// Question 13
		"Which of the following is a valid way to declare a multidimensional array in C?",
			"int matrix[3][3];", "int array[][] = {{1, 2}, {3, 4}};", "int grid[2, 2];", "int table[2][2] = {1, 2, 3, 4};",
			"This question takes you on a multidimensional journey in C. Can you spot the invalid declaration?",
		// Question 14
		"Consider the following C code: int z = 3 << 2 + 1; What's the value of z?",
			"24", "14", "10", "20",
			"This bitwise question takes a left shift into a wacky numeric realm. Can you predict the result?",
		// Question 15
		"Why do C programmers prefer dark mode in their code editors?",
			"Less eye strain during long coding sessions", "To hide bugs in the shadows", "It's more mysterious and dramatic", "For a secret underground coder society",
			"A question that sheds some light on the dark side of coding preferences. Can you see through the darkness?",
	};

	return convertToLinkedList(questionsAndAnswers);
}

struct Question* convertToLinkedList(char* questionsAndAnswers[]) {
	struct Question* head = NULL;
	head = (struct Question*)malloc(sizeof(struct Question));
	struct Question* current = head;

	for (int i = 0; i < 15; i++) {
		current->question = questionsAndAnswers[i * 6];
		current->correctAnswer = 0;
		for (int j = 0; j < 4; j++) {
			current->choices[j] = questionsAndAnswers[i * 6 + j + 1];
		}
		current->phoneAFriend = questionsAndAnswers[i * 6 + 5];
		if (i < 14) {
			current->next = (struct Question*)malloc(sizeof(struct Question));
			current = current->next;
		}
	}
	current->next = NULL;

	return head;
}