#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/*Declarations for the gamemodes and functions for GoldRoll */

void GameEasy(int credits, int gold);

void GameNormal(int credits, int gold);

void GameHard(int credits, int gold);

void Lucky(int *PointerCredits, int *PointerGold);



// A structure that holds the variables for the gold, credits, and difficulty amounts.
typedef struct {

	int difficulty, credits, gold;

} Main;

int main()
{

	

	srand(time(NULL));  //For Rand() function in gamemodes
	
	Main start; // Structure variable
	start.gold = 0;
	printf("Please enter in a difficulty: 1 for easy, 2 for medium, 3 for hard: ");
	scanf_s("%d", &start.difficulty); //takes user input for Difficulty int
	
	if (start.difficulty == 1){
		printf("You chose easy: Reach 10000 gold before you run out of credits!\n");
		start.credits = 10000;
		GameEasy(start.credits, start.gold); //GameEasy function is entered
	}

	if (start.difficulty == 2) {
		printf("You chose normal: Reach 12000 gold before you run out of credits!\n");
		start.credits = 8000;
		GameNormal(start.credits, start.gold); //GameNormal function is entered
	}

	if (start.difficulty == 3) {
		printf("You chose hard: Reach 14000 gold before you run out of credits!\n");
		start.credits = 5000;
		GameHard(start.credits, start.gold); //GameHard function is entered
	}

	//Prints and proceeds to return 0 if the input is not 1, 2, or 3
	if (start.difficulty >= 4 || start.difficulty <= 0) {
		printf("invalid input, exiting..."); 
	}
	return 0;

}

void GameEasy(int credits, int gold) 
{

	int userinput; //init for user input
	

	int *PointerGold, *PointerCredits; //Pointers for the gold and credit values that will change throughout the game

	PointerGold = &gold; 
	PointerCredits = &credits;
	

	//while loop that always checks for credits to be a number above 0
	while (credits > 0 && gold <= 10000)
	{
		
		printf("How many credits will be put in?\n");
		printf("1 for 100\n2 for 500\n3 for 1000\n"); //Switched to number selection for quicker input
		if (scanf_s("%d", &userinput) != 1) {
			printf("\nUnexpected input, exiting...");
			return EXIT_FAILURE; //Program exits if a non-integer value is entered
		}
			

		/*Error Messages*/
		if (userinput == 2 && *PointerCredits < 500 && *PointerCredits != 0) {
			printf("\nYou do not have enough credits for that!\n");
			printf("You currently have this much gold!:%d ", *PointerGold); //Displays current gold
			printf("You currently have this much credits!:%d\n ", *PointerCredits); //Displays current credits
		}

		if (userinput == 3 && *PointerCredits < 1000 && *PointerCredits != 0) {
			printf("\nYou do not have enough credits for that!\n"); //Shows when a user tries to input more credits than they have
			printf("You currently have this much gold!:%d ", *PointerGold); 
			printf("You currently have this much credits!:%d\n ", *PointerCredits); 
		}

		if (userinput > 3 || userinput < 1) {
			printf("Please input a valid choice\n"); //Whenever a number besides 1, 2, or 3 are provided
			printf("You currently have this much gold!:%d ", *PointerGold); 
			printf("You currently have this much credits!:%d\n ", *PointerCredits); 
			
		}

	
		//Takes away 100 credits and adds a random amount of gold up to 200: Safe but low payout. No chance for luck roll
		if (userinput == 1 && *PointerCredits >= 100)
		{
			credits = credits - 100;
			gold = gold + rand() % 200; 
			
			printf("You currently have this much gold!:%d ", *PointerGold); 
			printf("You currently have this much credits!:%d\n ", *PointerCredits); 

		}

		//Takes away 500 credits and adds a random amount of gold up to 1000: Middle payout, but with a bit of risk. No chance for luck roll
		if (userinput == 2 && *PointerCredits >= 500)
		{
			credits = credits - 500;
			gold = gold + rand() % 1000;

			
			printf("You currently have this much gold!:%d ", *PointerGold); 
			printf("You currently have this much credits!:%d\n ", *PointerCredits); 
		}

		
		//Takes away 1000 credits and adds a random amount of gold up to 2000: Chance to almost double payout, adds luck, but bigger risk
		if (userinput == 3 && *PointerCredits >= 1000)
		{
			credits = credits - 1000;
			gold = gold + rand() % 2000;
			
			printf("You currently have this much gold!:%d ", *PointerGold); 
			printf("You currently have this much credits!:%d\n\n ", *PointerCredits); 

			if (*PointerGold < 10000) {

				Lucky(&credits, &gold); //Passes variables into possible luck roll function

			}
		}

		


	}
	
	//Checks gold after loop is finished. If the payout is enough, a win message is displayed. Otherwise, a lose message is displayed
	if (*PointerGold > 10000) {
		printf("You win!");
		FILE* f = fopen("score.txt", "w");
		if (f == NULL)
		{
			printf("Cannot find score.txt!\n");
		}

		// Print the score to a text file
		printf(" Your Score has been saved to score.txt\n");
		int* score = *PointerGold;
		fprintf(f, "Your score from the last game is %d", score);
	}
	else {
		printf("You lose.");
		FILE* f = fopen("score.txt", "w");
		if (f == NULL)
		{
			printf("Cannot find score.txt!\n");
		}

		// Print the score to a text file
		printf(" Your Score has been saved to score.txt\n");
		int *score = *PointerGold;
		fprintf(f, "Your score from the last game is %d", score);
	}
	
	return;
}

void GameNormal(int credits, int gold)
{
	int userinput; //init for user input
	int* PointerGold, * PointerCredits; //Pointers for the gold and credit values that will change throughout the game

	PointerGold = &gold;
	PointerCredits = &credits;


	//while loop that always checks for credits to be a number above 0
	while (credits > 0 && gold <= 12000)
	{
		printf("How many credits will be put in?\n");
		printf("1 for 100\n2 for 500\n3 for 1000\n"); //Switched to number selection for quicker input
		if (scanf_s("%d", &userinput) != 1) 
		{
			printf("\nUnexpected input, exiting...");
			return EXIT_FAILURE; //Program exits if a non-integer value is entered
		}

		/*Error Messages*/

		if (userinput == 2 && *PointerCredits < 500 && *PointerCredits != 0) {
			printf("\nYou do not have enough credits for that!\n");
		}

		if (userinput == 3 && *PointerCredits < 1000 && *PointerCredits != 0) {
			printf("\nYou do not have enough credits for that!\n"); //Shows when a user tries to input more credits than they have
		}

		if (userinput > 3) {
			printf("Please input a valid choice\n"); //Whenever a number besides 1, 2, or 3 are provided

		}


		//Takes away 100 credits and adds a random amount of gold up to 200: Safe but low payout. No chance for luck roll
		if (userinput == 1 && *PointerCredits >= 100)
		{
			credits = credits - 100;
			gold = gold + rand() % 200;

			printf("You currently have this much gold!:%d ", *PointerGold); //Displays current gold
			printf("You currently have this much credits!:%d\n ", *PointerCredits); //Displays current credits

		}

		//Takes away 500 credits and adds a random amount of gold up to 1000: Middle payout, but with a bit of risk. No chance for luck roll
		if (userinput == 2 && *PointerCredits >= 500)
		{
			credits = credits - 500;
			gold = gold + rand() % 1000;


			printf("You currently have this much gold!:%d ", *PointerGold); //Displays current gold
			printf("You currently have this much credits!:%d\n ", *PointerCredits); //Displays current credits
		}


		//Takes away 1000 credits and adds a random amount of gold up to 2000: Chance to almost double payout, adds luck, but bigger risk
		if (userinput == 3 && *PointerCredits >= 1000)
		{
			credits = credits - 1000;
			gold = gold + rand() % 2000;

			printf("You currently have this much gold!:%d ", *PointerGold); //Displays current gold
			printf("You currently have this much credits!:%d\n", *PointerCredits); //Displays current credits

			if (*PointerGold < 10000) {

				Lucky(&credits, &gold); //Passes variables into possible luck roll function

			}
		}
	}

	//Checks gold after loop is finished. If the payout is enough, a win message is displayed. Otherwise, a lose message is displayed
	if (*PointerGold > 12000) {
		printf("You win!");
		FILE* f = fopen("score.txt", "w");
		if (f == NULL)
		{
			printf("Cannot find score.txt!\n");
		}

		// Print the score to a text file
		printf(" Your Score has been saved to score.txt\n");
		int* score = *PointerGold;
		fprintf(f, "Your score from the last game is %d", score);
	}
	else {
		printf("You lose.");
		FILE* f = fopen("score.txt", "w");
		if (f == NULL)
		{
			printf("Cannot find score.txt!\n");
		}

		// Print the score to a text file
		printf(" Your Score has been saved to score.txt\n");
		int* score = *PointerGold;
		fprintf(f, "Your score from the last game is %d", score);
	}

	return;
}

void GameHard(int credits, int gold)
{
	int userinput; //init for user input
	int* PointerGold, * PointerCredits; //Pointers for the gold and credit values that will change throughout the game

	PointerGold = &gold;
	PointerCredits = &credits;


	//while loop that always checks for credits to be a number above 0
	while (credits > 0 && gold <= 14000)
	{

		printf("How many credits will be put in?\n");
		printf("1 for 100\n2 for 500\n3 for 1000\n"); //Switched to number selection for quicker input
		if (scanf_s("%d", &userinput) != 1) {
			printf("\nUnexpected input, exiting...");
			return EXIT_FAILURE; //Program exits if a non-integer value is entered
		}

		/*Error Messages*/

		if (userinput == 2 && *PointerCredits < 500 && *PointerCredits != 0) {
			printf("\nYou do not have enough credits for that!\n");
		}

		if (userinput == 3 && *PointerCredits < 1000 && *PointerCredits != 0) {
			printf("\nYou do not have enough credits for that!\n"); //Shows when a user tries to input more credits than they have
		}

		if (userinput > 3) {
			printf("Please input a valid choice\n"); //Whenever a number besides 1, 2, or 3 are provided

		}


		//Takes away 100 credits and adds a random amount of gold up to 200: Safe but low payout. No chance for luck roll
		if (userinput == 1 && *PointerCredits >= 100)
		{
			credits = credits - 100;
			gold = gold + rand() % 200;

			printf("You currently have this much gold!:%d ", *PointerGold); //Displays current gold
			printf("You currently have this much credits!:%d\n ", *PointerCredits); //Displays current credits

		}

		//Takes away 500 credits and adds a random amount of gold up to 1000: Middle payout, but with a bit of risk. No chance for luck roll
		if (userinput == 2 && *PointerCredits >= 500)
		{
			credits = credits - 500;
			gold = gold + rand() % 1000;


			printf("You currently have this much gold!:%d ", *PointerGold); 
			printf("You currently have this much credits!:%d\n ", *PointerCredits); 
		}


		//Takes away 1000 credits and adds a random amount of gold up to 2000: Chance to almost double payout, adds luck, but bigger risk
		if (userinput == 3 && *PointerCredits >= 1000)
		{
			credits = credits - 1000;
			gold = gold + rand() % 2000;

			printf("You currently have this much gold!:%d ", *PointerGold); 
			printf("You currently have this much credits!:%d\n\n", *PointerCredits); 
			

			if (*PointerGold < 10000) {

				Lucky(&credits, &gold); //Passes variables into possible luck roll function

			}
		}

		


	}

	//Checks gold after loop is finished. If the payout is enough, a win message is displayed. Otherwise, a lose message is displayed
	if (*PointerGold > 14000) {
		printf("You win!");
		FILE* f = fopen("score.txt", "w");
		if (f == NULL)
		{
			printf("Cannot find score.txt!\n");
		}

		// Print the score to a text file
		printf(" Your Score has been saved to score.txt\n");
		int* score = *PointerGold;
		fprintf(f, "Your score from the last game is %d", score);
	}
	else {
		printf("You lose.");
		FILE* f = fopen("score.txt", "w");
		if (f == NULL)
		{
			printf("Cannot find score.txt!\n");
		}

		// Print the score to a text file
		printf(" Your Score has been saved to score.txt\n");
		int* score = *PointerGold;
		fprintf(f, "Your score from the last game is %d", score);
	}

	return;
}

void Lucky(int *PointerCredits, int *PointerGold) {

	/*Luck function that runs the two pointers for gold and credits through it*/


	int luck = rand() % 10; //Random number rolled after rolls
	if (luck >= 8) {

		/* A possible 1/5 chance to succeed*/


		int bonusinput;										// New input variable for the function
		

		//A union that holds the variables for the bonus options.
		typedef union {
			int bet;
			int credbonus;
			int goldbonus;
		} bonus;

		bonus Choice;
		/*Prompt that shows when luck is succeeded*/
		printf("1: You are granted 1000 additional credits\n2: You are given a bonus of 600 gold\n3: You have a chance to double or halve your gold\n\n");
		printf("BONUS: Input a number to select which bonus you would like to recieve!: ");
		if (scanf_s("%d", &bonusinput) != 1) 
		{
			printf("\nUnexpected input, exiting...");
			return EXIT_FAILURE; 
		}

		if (bonusinput == 1) {

			Choice.credbonus = 1000;
			*PointerCredits = *PointerCredits + Choice.credbonus;	// Updates the credits variable with an additional 1000 
			printf("\nYou are awarded 1000 extra credits!\n");
			printf("Your credits are now %d\n", *PointerCredits);

		}

		if (bonusinput == 2) {
			Choice.goldbonus = 600;
			*PointerGold = *PointerGold + Choice.goldbonus;
			printf("\nYou are awarded 600 extra gold!\n");	// Updates the gold variable with an additional 600
			printf("Your gold is now %d\n", *PointerGold);

		}

		if (bonusinput == 3) {

			Choice.bet = rand() % 2;

			if (Choice.bet == 0) {

				int remainder = *PointerGold % 2;
				int penalty = *PointerGold / 2;

				*PointerGold = penalty + remainder; // Updates the gold variable with a division of 2 + a modulo of 2 for the remainder

				printf("\nYour gold has been halved to %d\n", *PointerGold);

				return;

			}

			else 
			{

				*PointerGold = *PointerGold * 2; // Updates the gold variable with a multiplication of 2
				printf("\nYour gold has been doubled to %d\n", *PointerGold);
				
				return;
			}
		}
	}
}