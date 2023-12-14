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
			"Explore the fundamental properties of the decimal system.",
		// Question 2
		"What is the currency of Canada?",
			"Canadian Dollar", "Euro", "Pound Sterling", "Yen",
			"Explore global currencies.",
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
			"This ASCII-centric question adds a numeric twist to character manipulation in C.",
		// Question 12
		"Consider the following C code: int x = 10; printf('%d', x++ + ++x); What's the value of x?",
			"22", "13", "14", "Undefined behavior",
			"This incrementing question takes you on a wild ride through C code.",
		// Question 13
		"Which of the following is a valid way to declare a multidimensional array in C?",
			"int matrix[3][3];", "int array[][] = {{1, 2}, {3, 4}};", "int grid[2, 2];", "int table[2][2] = {1, 2, 3, 4};",
			"This question takes you on a multidimensional journey in C.",
		// Question 14
		"Consider the following C code: int z = 3 << 2 + 1; What's the value of z?",
			"24", "14", "10", "20",
			"This bitwise question takes a left shift into a wacky numeric realm.",
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
			"Explore the world of social media.",
		// Question 2
		"Which of these countries is not part of the European Union as of 2023?",
			"Norway", "France", "Germany", "Spain",
			"Navigate through geopolitical knowledge.",
		// Question 3
		"Which of these actors played the role of Batman in the 2021 film The Batman?",
			"Robert Pattinson", "Christian Bale", "Ben Affleck", "Michael Keaton",
			"Dive into the world of superheroes.",
		// Question 4
		"Which of these musical artists won the most Grammy Awards in 2022?",
			"Beyoncé", "Billie Eilish", "Taylor Swift", "Harry Styles",
			"Explore the world of music.",
		// Question 5
		"Which of these is the name of the first human-made object to land on Mars in 1971?",
			"Mars 2", "Viking 1", "Pathfinder", "Curiosity",
			"Embark on a space exploration.",
		// Question 6
		"Which of these is the capital city of Canada?",
			"Ottawa", "Toronto", "Montreal", "Vancouver",
			"Explore Canadian geography.",
		// Question 7
		"Which of these is the title of the seventh and final book in the Harry Potter series by J.K. Rowling?",
			"Harry Potter and the Deathly Hallows", "Harry Potter and the Order of the Phoenix", "Harry Potter and the Half-Blood Prince", "Harry Potter and the Cursed Child",
			"Immerse yourself in the wizarding world.",
		// Question 8
		"Which of these is the name of the largest bone in the human body?",
			"Femur", "Humerus", "Tibia", "Pelvis",
			"Explore human anatomy.",
		// Question 9
		"Which of these is the name of the ancient city that was destroyed by a volcanic eruption in 79 AD?",
			"Pompeii", "Athens", "Rome", "Babylon",
			"Step into ancient history.",
		// Question 10
		"Which of these is the name of the painting that Leonardo da Vinci worked on for over a decade and never finished?",
			"The Battle of Anghiari", "Mona Lisa", "The Last Supper", "The Vitruvian Man",
			"Explore the art of Leonardo da Vinci.",
		// Question 11
		"Which of these is the name of the branch of mathematics that deals with the properties and relationships of numbers, shapes, and space?",
			"Geometry", "Algebra", "Calculus", "Statistics",
			"Embark on a mathematical journey.",
		// Question 12
		"Which of these is the name of the first woman to win the Nobel Prize in Physics in 1903?",
			"Marie Curie", "Lise Meitner", "Rosalind Franklin", "Ada Lovelace",
			"Explore Nobel laureates.",
		// Question 13
		"Which of these is the name of the longest river in the world by total length?",
			"Amazon", "Nile", "Yangtze", "Mississippi",
			"Navigate through geography.",
		// Question 14
		"Which of these is the name of the war that lasted from 1618 to 1648 and involved most of the European countries at the time?",
			"The Thirty Years’ War", "The Hundred Years’ War", "The Napoleonic Wars", "The World War I",
			"Step into historical conflicts.",
		// Question 15
		"Which of these is the name of the chemical element with the highest atomic number that has been officially named and confirmed by the International Union of Pure and Applied Chemistry (IUPAC)?",
			"Oganesson", "Tennessine", "Livermorium", "Ununennium",
			"Dive into the periodic table.",
	};

	return convertToLinkedList(questionsAndAnswers, "Lucas");
}

struct QuestionSet* haoxiSet() {
	char* questionsAndAnswers[15 * 6] = {
		// Question 1
		"Nintendo released the NES (Nintendo Entertainment System) in 1985, what was the name of this game console in Japan?",
		"Family Computer", "Game & Watch", "Master System", "Super Nintendo",
		"It seems like a very common name.",
		// Question 2
		"What was Nintendo's first game console?",
		"Color TV-Game", "Game & Watch", "Family Computer (Nintendo Entertainment System)", "Atari 2600",
		"The most famous are often not first.",
		// Question 3
		"How many total video game generations are there as of 2023?",
		"9", "10", "8", "11",
		"Video game generations are primairly divided based on the progression of consoles.",
		// Question 4
		"What is the best selling video game?",
		"Minecraft", "Grand Theft Auto V", "Tetris", "Super Mario",
		"Not an old game!",
		// Question 5
		"What was the TGA Game of the Year in 2014?",
		"Dragon Age: Inquistion", "Dark Souls II", "Middle-earth: Shadow of Mordor", "Hearthstone",
		"It's a RPG game.",
		// Question 6
		"Which of the following war had the highest number of casualties?",
		"Vientnam War", "Korean War", "Yugoslav Wars", "Soviet-Afghan War",
		"It's an American-led war.",
		// Question 7
		"How many dynasties were there in China from 1279-1912?",
		"3", "1", "5", "4",
		"A number that is no more and no less.",
		// Question 8
		"How many voyages to the Americans did Columbus make in total?",
		"4", "3", "2", "1",
		"More then you think.",
		// Question 9
		"Which of the following plants were not part of the Columbian exchange (from the New World to the Old World)?",
		"Sugarcane", "Cactus", "Potato", "Maize",
		"A plant that can be used as a sugar source.",
		// Question 10
		"What was published at the 20th Congress of the Communist Party of the Soviet Union that made its worldwide impact?",
		"Secret Speeech", "Peaceful coexistence", "CCCP completes the full constuction of communism", "Sino-Soviet spilt",
		"It was an event related to Stalin.",
		// Question 11
		"What was the first human satelite?",
		"Sputnik 1", "Explorer 1", "Dong Fang Hong 1", "Vostok 1",
		"It's a Soviet satelite.",
		// Question 12
		"What year was the last human landing mission to the Moon?",
		"1972", "1967", "1969", "1980",
		"Only a few years separated the first and last human landings on the Moon.",
		// Question 13
		"What was the name of the helicopter that humans sent to Mars?",
		"Ingenuity", "Perseverance", "Zhurong", "Curiosity",
		"Another name for this helicopter is Ginny.",
		// Question 14
		"In which years did mankind achieve the first recoverable rocket?",
		"2015", "2016", "2012", "2018",
		"SpaceX's Falcon 9.",
		// Question 15
		"Which of the follwing satellites is farthest from Earth?",
		"Voyager 1", "Voyager 2", "Juno", "Cassini-Huygens",
		"The earlist launches naturally have the longest range.",
	};

	return convertToLinkedList(questionsAndAnswers, "Haoxi");
}
struct QuestionSet* nardaSet() {
	char* questionsAndAnswers[15 * 6] = {
		// Question 1
		"What experiment number is Stich?",
		"626", "326", "676", "888",
		"-",
		// Question 2
		"In which movie does the villain named Clayton Appear?",
		"Tarzan", "Atlantis", "Pocahontas", "Coco",
		"He is a jungle man",
		// Question 3
		"Where does Marlin go to find his son Nemo?",
		"Sydney", "Atlanta", "California", "Mexico",
		"Observatory Hill Park",
		// Question 4
		"Which princess is Pascal friend?",
		"Rapunzel", "Tiana", "Moana","Elsa",
		"Long hair",
		// Question 5
		"What kind of fairy is Tinker Bell?",
		"Tinker Talent", "Garden Talent", "Animal Talent", "Water Faires",
		"They invent and create special tools to help the fairies.",
		// Question 6
		"What is the name of Ariels daughter",
		"Melody", "Wendy", "Alondra", "Ana",
		"Sound like a song",
		// Question 7
		"What is the name of the villain in the Little Mermaid movie?",
		"Ursula", "Cruella de Vil", "Maleficent", "Jafar",
		"Looks like an octopus",
		// Question 8
		"Which Disney character has a magic lamp and a genie?",
		"Aladdin", "Jafar", "Abu", "Ursula",
		"Use a magic carpet and have a monkey as a friend",
		// Question 9
		"What is the name of Pinocchio's best friend?",
		"Cricket", "Pascal", "Sebastian", "Flounder",
		"A small animal and it makes sound at night",
		// Question 10
		"What is the name of the mouse enemy in the Cinderella story?",
		"Lucifer", "Scar", "Timon", "Buster",
		"It is a cat with a creepy name",
		// Question 11
		"What princess lives under the sea ?",
		"Ariel", "Cinderella", "Elsa", "Rapunzel",
		"Is the daughter of King Triton",
		// Question 12
		"What is the name of Jacks dog? ",
		"Zero", "Sparky", "Scraps", "Gus",
		"Is a numerical quantity",
		// Question 13
		"How many brothers does Merida have ? ",
		"3", "2", "4", "1",
		"More then you think",
		// Question 14
		"What is the name of the villain of Hercules?",
		"Hades", "Jafar", "Gantu", "Sid",
		"Is the brother of Zeus",
		// Question 15
		"What is the indentity of Darth Vader?",
		"Anakin Skywalker", "Rey Skywalker", "Obi Wan Kenobi", "Luke Skywalker",
		"He was the child prodify",
	};

	return convertToLinkedList(questionsAndAnswers, "Narda");
}

struct QuestionSet* morlanSet() {
	char* questionsAndAnswers[15 * 6] = {
		// Question 1
		"What would be the correct code for the function CancelFallVelocity()?",
			"player.AddForce(new Vector2(0, -player.rigidbody.velocity.y));",
			"player.AddForce(new Vector2(0, player.rigidbody.velocity.y));",
			"player.AddForce(new Vector2(-player.rigidbody.velocity.x, 0));",
			"player.AddForce(new Vector2(player.rigidbody.velocity.x, 0));",
			"It is the difference in their positions.",
		//Question 2
		"How would we make the player invulnerable for 1 second?",
			"player.isVulnerable = false; while (time < 1) return null; player.isVulnerable = true;",
			"player.isVulnerable = true; while (time < 1) return null; player.isVulnerable = false;",
			"player.isVulnerable = false; while (time > 1) return null; player.isVulnerable = true;",
			"player.isVulnerable = true; while (time > 1) return null; player.isVulnerable = false;",
			"First we need to make it not be vulnerable, then wait to revert it.",
		//Question 3
		"How can we make objA look at objB?",
			"objA.rotation = Quaternion.LookRotation(objB.position - objA.position);",
			"objA.rotation = Quaternion.LookRotation(objA.position - objB.position);",
			"objA.rotation += Quaternion.LookRotation(objA.position - objB.position);",
			"objB.rotation -= Quaternion.LookRotation(objB.position + objA.position);",
			"It is the direction resulting from the difference in their positions.",
		//Question 4
		"Which of the following is true?",
			"if (true == false || (false != true && (true || false)))",
			"if (true == false || (false != true && false || !true))",
			"if (true == true && (false != true && false))",
			"if (true != false && (false != true && !true))",
			"We saw that in math, you should know...",
		//Question 5
		"If the class Soldier inherits from the class Enemy...",
			"We can access soldier.health as long as Enemy has a protected 'health' variable.",
			"We can access soldier.health as long as Enemy has a private 'health' variable.",
			"We can access enemy.health as long as Soldier has a public 'health' variable.",
			"We can access enemy.health as long as Soldier has a protected 'health' variable.",
			"A child has the variables of the parent, but not the other way around.",
		//Question 6
		"What is the correct code to make an object rotate toward the player's position?",
			"transform.LookAt(player.transform.position);",
			"transform.Rotate(player.transform.position - transform.position);",
			"transform.RotateAround(player.transform.position, Vector3.up, 180f);",
			"transform.Rotate(Vector3.up * 180f);",
			"LookAt() is a function that makes an object look at the given position.",
		//Question 7
		"How can you pause the game in Unity?",
			"Time.timeScale = 0f;",
			"gamePaused = true;",
			"gameObject.SetActive(false);",
			"Pause();",
			"Time.timeScale is a variable that controls the speed of the game.",
		//Question 8
		"Which statement calls Attack() on an instance enemy of type Enemy?",
			"enemy.Attack();",
			"Enemy.Attack();",
			"Attack(enemy);",
			"Enemy(enemy).Attack();",
			"instanceName.FunctionName();",
		//Question 9
		"In C#, how would we declare 'name' if we don't want to change it after assigning its value?",
			"const string name;",
			"readonly string name;",
			"mutable string name;",
			"static string name;",
			"Please, it's in the question",
		//Question 10
		"In C#, what is the term for a piece of code that is executed when a specific condition is met?",
			"Event",
			"Method",
			"Delegate",
			"Callback",
			"Idk",
		//Question 11
		"In C#, how should we create a new instance of a class or structure?",
			"new Weapon();",
			"class Weapon(weapon);",
			"instance.Weapon;",
			"create(Weapon);",
			"Idk",
		//Question 12
		"Which of these is a regex to validate an email address?",
			"(?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*|""(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21\x23-\x5b\x5d-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])*"")@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?|\[(?:(?:(2(5[0-5]|[0-4][0-9])|1[0-9][0-9]|[1-9]?[0-9]))\.){3}(?:(2(5[0-5]|[0-4][0-9])|1[0-9][0-9]|[1-9]?[0-9])|[a-z0-9-]*[a-z0-9]:(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21-\x5a\x53-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])+)\])",
			"validateEmail(134.255.55.59.111.67.12.162.16.152.149.242);",
			"IsEmailAdress(userInput);",
			"emailAdress.Validate();",
			"Uhhhh wth is even that??",
		//Question 13
		"What git command do you probably not want to use if it's your first day as an intern?",
			"git push --all",
			"git pull origin main",
			"git clone <repository-url>",
			"git status",
			"Pushing all your code to the main branch is a big no-no.",
		//Question 14
		"In a Python script, what library should we use to read a CSV file?",
			"pandas",
			"beautiful soup",
			"pillow",
			"django",
			"Idk, but those are some p random names",
		//Question 15
		"What is the internal codename for Android 15?",
			"Vanilla Ice Cream",
			"Upside Down Cake",
			"New York Cheesecake",
			"Ice Cream Sandwich",
			"I am hungry now"
	};

	return convertToLinkedList(questionsAndAnswers, "Morlan");
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
		haoxiSet(),
		nardaSet(),
		morlanSet()
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
