#include <stdio.h>
#include <stdlib.h>
#include "questions.h"

struct Question* convertToLinkedList(char* questionsAndAnswers[]);

struct Question* getQuestions() {
	char* questionsAndAnswers[15 * 6] = {
		"What is the capital of France?", // Question 0
			"Paris", "London", "Berlin", "Madrid",
			"IDK....",
		"How many states are there in the United States?", // Question 1
			"50", "51", "49", "48",
			"IDK....",
		"What is the capital of the United States?", // Question 2
			"Washington D.C.", "New York", "Los Angeles", "Chicago",
			"IDK....",
		"What is the capital of France?", // Question 3
			"Paris", "London", "Berlin", "Madrid",
			"IDK....",
		"How many states are there in the United States?", // Question 4
			"50", "51", "49", "48",
			"IDK....",
		"What is the capital of the United States?", // Question 5
			"Washington D.C.", "New York", "Los Angeles", "Chicago",
			"IDK....",
		"What is the capital of France?", // Question 6
			"Paris", "London", "Berlin", "Madrid",
			"IDK....",
		"How many states are there in the United States?", // Question 7
			"50", "51", "49", "48",
			"IDK....",
		"What is the capital of the United States?", // Question 8
			"Washington D.C.", "New York", "Los Angeles", "Chicago",
			"IDK....",
		"What is the capital of France?", // Question 9
			"Paris", "London", "Berlin", "Madrid",
			"IDK....",
		"How many states are there in the United States?", // Question 10
			"50", "51", "49", "48",
			"IDK....",
		"What is the capital of the United States?", // Question 11
			"Washington D.C.", "New York", "Los Angeles", "Chicago",
			"IDK....",
		"What is the capital of France?", // Question 12
			"Paris", "London", "Berlin", "Madrid",
			"IDK....",
		"How many states are there in the United States?", // Question 13
			"50", "51", "49", "48",
			"IDK....",
		"What is the capital of the United States?", // Question 14
			"Washington D.C.", "New York", "Los Angeles", "Chicago",
			"IDK....",
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