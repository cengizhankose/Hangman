#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	
	char guessWords [] [16]=
	
	{
	"istanbul",
	"izmir",
	"tokat",
	"bolu",
	"kirsehir"
	
	
	};
	
	// index for random word
	
	int randomIndex = rand() % 6; // assign module into the amount of province you have
	
	int fullrand = 0;
	
	int numLives = 5;
	int numCorrect = 0;
	int oldCorrect = 0;
	
	int lengthOfWord = strlen(guessWords[randomIndex]);
	int letterGuessed[9] = {0,0,0,0,0,0,0,0,0};
	
	int quit = 0;
	
	int loopIndex = 0;
	
	char guess[16];
	
	printf("guessWords:%s\nrandomIndex:%d\nlengthOfWord:%d\n",guessWords[randomIndex],randomIndex,lengthOfWord);
	
	while (numCorrect < lengthOfWord)
	{
		printf("Enter a guess letter:");
		fgets(guess, 16, stdin);
		
		if (strncmp(guess,"quit", 4) == 0 )
		
		{
			
			quit = 1;
			break;
		}
		
	}	
	
	
		
		if(quit == 1)
		
		{
			printf("\nthe user quit early");
			
		}
		
	
	
	return 0;
}


