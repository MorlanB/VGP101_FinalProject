#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

struct QuestionSet* convertToLinkedList(char* questionsAndAnswers[], char* name);

struct QuestionSet* benjaminSet() {
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

	return convertToLinkedList(questionsAndAnswers, "Benjamin");
}

struct QuestionSet* lucasSet() {
	char* questionsAndAnswers[15 * 6] = {
		// Question 1
		"Which of these is a popular video-sharing app that was launched in 2016?",
			"TikTok", "Snapchat", "Instagram", "YouTube",
			"Explore the world of social media. Which app, launched in 2016, gained popularity for short-form videos?",
		// Question 2
		"Which of these countries is not part of the European Union as of 2023?",
			"Norway", "France", "Germany", "Spain",
			"Navigate through geopolitical knowledge. Can you identify the country that is not part of the European Union as of 2023?",
		// Question 3
		"Which of these actors played the role of Batman in the 2021 film The Batman?",
			"Robert Pattinson", "Christian Bale", "Ben Affleck", "Michael Keaton",
			"Dive into the world of superheroes. Who portrayed Batman in the 2021 film 'The Batman'?",
		// Question 4
		"Which of these musical artists won the most Grammy Awards in 2022?",
			"Beyoncé", "Billie Eilish", "Taylor Swift", "Harry Styles",
			"Explore the world of music. Who secured the most Grammy Awards in the year 2022?",
		// Question 5
		"Which of these is the name of the first human-made object to land on Mars in 1971?",
			"Mars 2", "Viking 1", "Pathfinder", "Curiosity",
			"Embark on a space exploration. What is the name of the first human-made object to land on Mars in 1971?",
		// Question 6
		"Which of these is the capital city of Canada?",
			"Ottawa", "Toronto", "Montreal", "Vancouver",
			"Explore Canadian geography. Can you identify the capital city of Canada?",
		// Question 7
		"Which of these is the title of the seventh and final book in the Harry Potter series by J.K. Rowling?",
			"Harry Potter and the Deathly Hallows", "Harry Potter and the Order of the Phoenix", "Harry Potter and the Half-Blood Prince", "Harry Potter and the Cursed Child",
			"Immerse yourself in the wizarding world. What is the title of the seventh and final book in the Harry Potter series?",
		// Question 8
		"Which of these is the name of the largest bone in the human body?",
			"Femur", "Humerus", "Tibia", "Pelvis",
			"Explore human anatomy. Can you identify the largest bone in the human body?",
		// Question 9
		"Which of these is the name of the ancient city that was destroyed by a volcanic eruption in 79 AD?",
			"Pompeii", "Athens", "Rome", "Babylon",
			"Step into ancient history. Which city faced destruction due to a volcanic eruption in 79 AD?",
		// Question 10
		"Which of these is the name of the painting that Leonardo da Vinci worked on for over a decade and never finished?",
			"The Battle of Anghiari", "Mona Lisa", "The Last Supper", "The Vitruvian Man",
			"Explore the art of Leonardo da Vinci. Which painting remained unfinished after over a decade of work?",
		// Question 11
		"Which of these is the name of the branch of mathematics that deals with the properties and relationships of numbers, shapes, and space?",
			"Geometry", "Algebra", "Calculus", "Statistics",
			"Embark on a mathematical journey. Which branch of mathematics focuses on numbers, shapes, and space?",
		// Question 12
		"Which of these is the name of the first woman to win the Nobel Prize in Physics in 1903?",
			"Marie Curie", "Lise Meitner", "Rosalind Franklin", "Ada Lovelace",
			"Explore Nobel laureates. Who was the first woman to win the Nobel Prize in Physics in 1903?",
		// Question 13
		"Which of these is the name of the longest river in the world by total length?",
			"Amazon", "Nile", "Yangtze", "Mississippi",
			"Navigate through geography. What is the name of the longest river in the world by total length?",
		// Question 14
		"Which of these is the name of the war that lasted from 1618 to 1648 and involved most of the European countries at the time?",
			"The Thirty Years’ War", "The Hundred Years’ War", "The Napoleonic Wars", "The World War I",
			"Step into historical conflicts. What is the name of the war that lasted from 1618 to 1648, involving most European countries?",
		// Question 15
		"Which of these is the name of the chemical element with the highest atomic number that has been officially named and confirmed by the International Union of Pure and Applied Chemistry (IUPAC)?",
			"Oganesson", "Tennessine", "Livermorium", "Ununennium",
			"Dive into the periodic table. What is the name of the chemical element with the highest confirmed atomic number?",
	};

	return convertToLinkedList(questionsAndAnswers, "Lucas");
}

struct QuestionSet* convertToLinkedList(char* questionsAndAnswers[], char* name) {
	struct QuestionSet* set = (struct QuestionSet*)malloc(sizeof(struct QuestionSet));
	set->creator = name;
	set->questions = (struct Question*)malloc(sizeof(struct Question));
	struct Question* current = set->questions;


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

	return set;
}

struct QuestionSet* getQuestions() {
	struct QuestionSet* sets[] = {
		benjaminSet(),
		lucasSet(),
	};

	struct QuestionSet* head = sets[0];
	struct QuestionSet* current = head;

	for (int i = 1; i < sizeof(sets)/sizeof(sets[0]); i++) {
		current->next = sets[i];
		current = current->next;
	}
	current->next = NULL;

	return head;
}