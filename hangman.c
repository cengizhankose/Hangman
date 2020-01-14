// Student Name: Adem Onur Oztas | Student ID:1904010025 
// Student Name: Mert Altuntas   | Student ID:1804010005 

/*
This is a game called Hangman.
We added and developed some extraordinary features compare to standart hangman games.
This game has 2 game difficulty. Easy and normal. In order to activate difficulty please
remove the double slash at the beginning of line at 267. from source code.

Cheat Codes:

Cheat 1: "runomeda" : Set the remain live to 9999 (it means ademonur when readed from backward and also a username)
Cheat 2: "mertfozzy" : Set the remain live to 9999  
Cheat 3: "ozlemfeyza" : User immediately wins the game --------- LOL :)

If you want to see our progress step by step check it out our Github link!
https://github.com/runomeda/Hangman

Enjoy and have fun!!

*/

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void visual(int numLives);	// Prototype of hangman statement as visually
void topic(void);			// Prototype of hangman title at the top of the console

int main(void)
{
	srand(time(NULL));	// Feeding the random function

	// Declaring all the provinces in Turkey as an array
	char guessWords[][16] =

		{
			"adana",
			"adiyaman",
			"afyon",
			"agri",
			"amasya",
			"ankara",
			"antalya",
			"artvin",
			"aydin",
			"balikesir",
			"bilecik",
			"bingol",
			"bitlis",
			"bolu",
			"burdur",
			"bursa",
			"canakkale",
			"cankiri",
			"corum",
			"denizli",
			"diyarbakir",
			"edirne",
			"elazig",
			"erzincan",
			"erzurum",
			"eskisehir",
			"gaziantep",
			"giresun",
			"gumushane",
			"hakkari",
			"hatay",
			"isparta",
			"mersin",
			"istanbul",
			"izmir",
			"kars",
			"kastamonu",
			"kayseri",
			"kirklareli",
			"kirsehir",
			"kocaeli",
			"konya",
			"kutahya",
			"malatya",
			"manisa",
			"kahramanmaras",
			"mardin",
			"mugla",
			"mus",
			"nevsehir",
			"nigde",
			"ordu",
			"rize",
			"sakarya",
			"samsun",
			"siirt",
			"sinop",
			"sivas",
			"tekirdag",
			"tokat",
			"trabzon",
			"tunceli",
			"sanliurfa",
			"usak",
			"van",
			"yozgat",
			"zonguldak",
			"aksaray",
			"bayburt",
			"karaman",
			"kirikkale",
			"batman",
			"sirnak",
			"bartin",
			"ardahan",
			"igdir",
			"yalova",
			"karabuk",
			"kilis",
			"osmaniye",
			"duzce" };

	// Index for random word	
	int randomIndex = rand() % 81;	// assign module into the amount of province you have

	// Declaring remain lives of the user	
	int numLives = 6;

	// Declaring and storing correct number the user replied
	int numCorrect = 0;

	// This declaration prevents the user from free win if user enters the same letter over and over already existed
	int oldCorrect = 0;

	// Calculates the length of the word
	int lengthOfWord = strlen(guessWords[randomIndex]);

	// Store all the arrays to 0 unless the user enters correct letter
	int letterGuessed[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	// quit from game feature	
	int quit = 0;

	// Cheat Codes
	int runomeda, mertfozzy, ozlemfeyza = 0;

	// Index the for statement value
	int loopIndex = 0;

	// Waits the user answer
	char guess[16];

	// The letter user types in
	char letterEntered;

	// Prints the hangman text 
	topic();

	// Debugging Assistant
	// printf("guessWords:%s\nrandomIndex:%d\nlengthOfWord:%d\n",guessWords[randomIndex],randomIndex,lengthOfWord);

	// Prints the length of the selected word for being user friendly
	printf("Your word has %d letter\n", lengthOfWord);

	// Game Loop
	while (numCorrect < lengthOfWord)
	{
		// Prompt
		printf("\nHangman Word: ");

		// A for loop check the user answers
		for (loopIndex = 0; loopIndex < lengthOfWord; loopIndex++)

		{
			if (letterGuessed[loopIndex] == 1)

			{
				printf("%c ", guessWords[randomIndex][loopIndex]);
			}	//end of if
			else
			{
				printf("- ");
			}	//end of else
		}	//end of for

		// User Prompt
		printf("\nCorrect Guess: %d\n", numCorrect);
		printf("Number of life: %d\n", numLives);

		// Takes input from the user including quit function and cheats
		printf("Enter a guess letter:");
		fgets(guess, 16, stdin);

		if (strncmp(guess, "quit", 4) == 0)

		{
			quit = 1;
			break;
		}	// end of if

		if (strncmp(guess, "runomeda", 8) == 0)

		{
			runomeda = 1;

		}	// end of if

		if (strncmp(guess, "mertfozzy", 9) == 0)

		{
			mertfozzy = 1;

		}	// end of if

		if (strncmp(guess, "ozlemfeyza", 10) == 0)

		{
			ozlemfeyza = 1;

		}	// end of if

		// Takes the first number of letter whatever user typed in
		letterEntered = guess[0];
		// printf("LetterEntered:%c\n",letterEntered);

		oldCorrect = numCorrect;

		for (loopIndex = 0; loopIndex < lengthOfWord; loopIndex++)

		{
			// It prevents the user from earning correct number if some letter is already exposed and user entered that.
			if (letterGuessed[loopIndex] == 1)

			{
				continue;
			}	//end of if 

			// Set value 0 to 1 which array is correct of the selected word  
			if (letterEntered == guessWords[randomIndex][loopIndex])

			{
				letterGuessed[loopIndex] = 1;
				numCorrect++;

			}	//end of if
		}	// end of for

		// if user didn't entered the correct letter it takes a life point from user
		if (oldCorrect == numCorrect)
		{
			numLives--;

			visual(numLives);
			printf("\nSorry, wrong guess\n");

			// if there isn't left any life user loose
			if (numLives == 0)
			{
				break;
			}	// end of if
		}	// end of if
		else
		{
			visual(numLives);
			printf("\nCorrect guess! :)\n");

			// This is for easy difficulty
			// numLives++;

		}	// end of else

		// if user types runomeda to console activate cheat
		if (runomeda == 1)
		{
			numLives = 9999;
			printf("\033[1;31m");
			printf("\n\nCheat activated!\n");
			runomeda = 0;
		}	//end of if

		// if user types mertfozzy to console activate cheat
		if (mertfozzy == 1)
		{
			numLives = 9999;
			printf("\033[1;31m");
			printf("\n\nCheat activated!\n");
			mertfozzy = 0;
		}	//end of if

		// if user types ozlemfeyza to console activates cheat and wins the game
		if (ozlemfeyza == 1)
		{
			printf("\033[1;31m");
			printf("\n\nUltra Cheat activated!\n");

			break;

		}	//end of if
	}	//end of while

	// if user types quit to console the game stops
	if (quit == 1)

	{
		printf("\nthe user quit early");

	}	// end of if

	// Prompt screen when user loose
	else if (numLives == 0)

	{
		printf("\nSorry, you loose the word was -----------> < %s >", guessWords[randomIndex]);
	}	// end of else-if

	// Prompt screen when user win
	else
	{
		printf("\nYOU WIN!!!");
	}	// end of else

	return 0;
}	//end of main

// Prints hangman title at the top of the console
void topic(void)

{
	printf("--------------------------------------------\n");
	printf("| #  #   #   #   #  #### #   #   #   #   # |\n");
	printf("| #  #  # #  ##  # #     ## ##  # #  ##  # |\n");
	printf("| #### ##### # # # #  ## # # # ##### # # # |\n");
	printf("| #  # #   # #  ## #   # #   # #   # #  ## |\n");
	printf("| #  # #   # #   #  ###  #   # #   # #   # |\n");
	printf("--------------------------------------------\n\n");

}	// end of topic

// This function shows the hangman after each wrong try
void visual(int numLives)
{
	switch (numLives)
	{
		case 0:
			system("cls");
			topic();

			printf("\n\t||===== ");
			printf("\n\t||    | ");
			printf("\n\t||   %cO/", '\\');
			printf("\n\t||    | ");
			printf("\n\t||   / %c", '\\');
			printf("\n\t||      ");
			break;
		case 1:
			system("cls");

			topic();

			printf("\n\t||===== ");
			printf("\n\t||    | ");
			printf("\n\t||   %cO/", '\\');
			printf("\n\t||    | ");
			printf("\n\t||     %c", '\\');
			printf("\n\t||      ");
			break;
		case 2:
			system("cls");

			topic();

			printf("\n\t||===== ");
			printf("\n\t||    | ");
			printf("\n\t||   %cO/", '\\');
			printf("\n\t||    | ");
			printf("\n\t||      ");
			printf("\n\t||      ");
			break;
		case 3:
			system("cls");

			topic();

			printf("\n\t||===== ");
			printf("\n\t||    | ");
			printf("\n\t||   %cO/", '\\');
			printf("\n\t||      ");
			printf("\n\t||      ");
			printf("\n\t||      ");
			break;
		case 4:
			system("cls");

			topic();

			printf("\n\t||===== ");
			printf("\n\t||    | ");
			printf("\n\t||   %cO ", '\\');
			printf("\n\t||      ");
			printf("\n\t||      ");
			printf("\n\t||      ");
			break;
		case 5:
			system("cls");

			topic();

			printf("\n\t||===== ");
			printf("\n\t||    | ");
			printf("\n\t||    O ");
			printf("\n\t||      ");
			printf("\n\t||      ");
			printf("\n\t||      ");
			break;

		case 6:
			system("cls");

			topic();

			printf("\n\t||===== ");
			printf("\n\t||    | ");
			printf("\n\t||      ");
			printf("\n\t||      ");
			printf("\n\t||      ");
			printf("\n\t||      ");
			break;

		default:
			system("cls");

			topic();

			printf("\n\t||===== ");
			printf("\n\t||    | ");
			printf("\n\t||      ");
			printf("\n\t||      ");
			printf("\n\t||      ");
			printf("\n\t||      ");
			break;
	}	//end of switch-case
	return;
}	//end of main
