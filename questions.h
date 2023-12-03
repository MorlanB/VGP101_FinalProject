#pragma once
struct Question {
	char* question;
	char* choices[4];
	char* phoneAFriend;
	int correctAnswer;
	struct Question* next;
};
struct QuestionSet {
	struct Question* questions;
	char* creator;
	struct QuestionSet* next;
};
extern struct QuestionSet* getQuestions();