#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	
	char guessWords [] [16] =
	
	{
	"istanbul",
	"izmir",
	"tokat",
	"bolu",
	"kirsehir"
	
	
	};
	
	// index for random word
	
	int randomIndex = rand() % 5; // assign module into the amount of province you have	
	int numLives = 5;
	int numCorrect = 0;
	int oldCorrect = 0;	
	int lengthOfWord = strlen(guessWords[randomIndex]);
	int letterGuessed[9] = {0,0,0,0,0,0,0,0,0};	
	int quit = 0;	
	int loopIndex = 0;
	
	char guess[16];
	char letterEntered;
	
	// printf("guessWords:%s\nrandomIndex:%d\nlengthOfWord:%d\n",guessWords[randomIndex],randomIndex,lengthOfWord);
	
	while (numCorrect < lengthOfWord)
	{
		
			printf("\n\nNew Turn...\nHangman Word: \n");
		
			for (loopIndex = 0; loopIndex < lengthOfWord; loopIndex++)
		
		{
			if(letterGuessed[loopIndex] == 1)
			
			{
				printf("%c",guessWords[randomIndex][loopIndex]);
			}
			
			else
			{
				printf("-");
			}
			
			
			
			
		}
		
		
		printf("\n");
		
		
		
		
		
		
		
		
		
		
		printf("Number correct so far: %d\n",numCorrect);
		printf("Number of life: %d\n",numLives);
		
		printf("Enter a guess letter:");
		fgets(guess, 16, stdin);
		
		if (strncmp(guess,"quit", 4) == 0 )
		
		{
			
			quit = 1;
			break;
		}
		
		
		letterEntered = guess[0];	
		printf("LetterEntered:%c\n",letterEntered);
		
		oldCorrect = numCorrect;
		
		for (loopIndex = 0; loopIndex < lengthOfWord; loopIndex++)
		
		{
			if(letterGuessed[loopIndex] == 1)
			
			{
				continue;
			}
			
			
			
			if(letterEntered == guessWords[randomIndex][loopIndex])
			
			{
				
				letterGuessed[loopIndex] = 1;
				numCorrect++;
				
			}
			
			
			
		}
		
		if (oldCorrect == numCorrect)
		{
			
			numLives--;
			printf("Sorry, wrong guess\n");
			
			if(numLives == 0)
			{
				break;
			}
			
		}
		
		
		else
			{
				printf("Correct guess! :)\n");
			}
	}	
	
	
	
	
		
		if(quit == 1)
		
		{
			printf("\nthe user quit early");
			
		}
		
		else if (numLives == 0)
		
		{
			printf("\nSorry, you loose the word was <%s>",guessWords[randomIndex]);
		}
		
		else
		{
			printf("\nYOU WIN!!!");
		}
	
	
	return 0;
}

