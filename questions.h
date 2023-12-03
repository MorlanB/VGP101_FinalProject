#pragma once
struct Question {
	char* question;
	char* choices[4];
	char* phoneAFriend;
	int correctAnswer;
	struct Question* next;
};
extern struct Question* getQuestions();