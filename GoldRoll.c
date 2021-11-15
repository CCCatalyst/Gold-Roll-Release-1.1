#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Declarations for the gamemodes and functions for GoldRoll */

void GameEasy(int credits, int gold);

void GameNormal(int credits, int gold);

void GameHard(int credits, int gold);

void Lucky(int *PointerCredits, int *PointerGold);



int main()
{

	srand(time(NULL)); 
	int Difficulty; //Number represents difficulty, 1 is easy, 2 is normal, 3 is hard
	int credits; //init for the credits variable
	int gold = 0; //start off at 0 gold, gets added upon within the gamemodes

	printf("Please enter in a difficulty: 1 for easy, 2 for medium, 3 for hard: ");
	scanf_s("%d", &Difficulty); //takes user input for Difficulty int
	
	if (Difficulty == 1){
		printf("You chose easy: Reach 10000 gold before you run out of credits!\n");
		credits = 10000;
		GameEasy(credits, gold); //GameEasy function is entered
	}

	if (Difficulty == 2) {
		printf("You chose normal: Reach 12000 gold before you run out of credits!\n");
		credits = 8000;
		GameNormal(credits, gold); //GameNormal function is entered
	}

	if (Difficulty == 3) {
		printf("You chose hard: Reach 14000 gold before you run out of credits!\n");
		credits = 5000;
		GameHard(credits, gold); //GameHard function is entered
	}

	//Prints and proceeds to return 0 if the input is not 1, 2, or 3
	if (Difficulty >= 4 || Difficulty <= 0) {
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
		scanf_s("%d", &userinput); // Prompts user for userinput variable

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
			printf("You currently have this much credits!:%d\n ", *PointerCredits); //Displays current credits
			printf("\n");

			if (*PointerGold < 10000) {

				Lucky(&credits, &gold); //Passes variables into possible luck roll function

			}
		}

		


	}
	
	//Checks gold after loop is finished. If the payout is enough, a win message is displayed. Otherwise, a lose message is displayed
	if (*PointerGold > 10000) {
		printf("You win!");
	}
	else {
		printf("You lose"); 
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
	while (credits > 0 && gold <= 10000)
	{

		printf("How many credits will be put in?\n");
		printf("1 for 100\n2 for 500\n3 for 1000\n"); //Switched to number selection for quicker input
		scanf_s("%d", &userinput); // Prompts user for userinput variable

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
			printf("You currently have this much credits!:%d\n ", *PointerCredits); //Displays current credits
			printf("\n");

			if (*PointerGold < 10000) {

				Lucky(&credits, &gold); //Passes variables into possible luck roll function

			}
		}

		


	}

	//Checks gold after loop is finished. If the payout is enough, a win message is displayed. Otherwise, a lose message is displayed
	if (*PointerGold > 12000) {
		printf("You win!");
	}
	else {
		printf("You lose");
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
	while (credits > 0 && gold <= 10000)
	{

		printf("How many credits will be put in?\n");
		printf("1 for 100\n2 for 500\n3 for 1000\n"); //Switched to number selection for quicker input
		scanf_s("%d", &userinput); // Prompts user for userinput variable

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
			printf("You currently have this much credits!:%d\n ", *PointerCredits); //Displays current credits
			printf("\n");

			if (*PointerGold < 10000) {

				Lucky(&credits, &gold); //Passes variables into possible luck roll function

			}
		}

		



	}

	//Checks gold after loop is finished. If the payout is enough, a win message is displayed. Otherwise, a lose message is displayed
	if (*PointerGold > 14000) {
		printf("You win!");
	}
	else {
		printf("You lose");
	}

	return;
}

void Lucky(int *PointerCredits, int *PointerGold) {

	/*Luck function that runs the two pointers for gold and credits through it*/


	int luck = rand() % 10; //Random number rolled after rolls
	if (luck >= 8) {

		/* A possible 1/5 chance to succeed*/


		int bonusinput;										// New input variable for the function
		int bet = rand() % 2;								// My chance roll for double or nothing, Coin flip
		int credbonus = 1000;								// A bonus 1000 to credits, Possible game saver
		int goldbonus = 600;								// A bonus 600 to gold, Safe Bonus
		int bonus[3] = { bet, goldbonus, credbonus };		// Array that holds the variables for the bonuses


		/*Prompt that shows when luck is succeeded*/
		printf("1: You are granted 1000 additional credits\n2: You are given a bonus of 600 gold\n3: You have a chance to double or halve your gold\n\n");
		printf("BONUS: Input a number to select which bonus you would like to recieve!: ");
		scanf_s("%d", &bonusinput);

		if (bonusinput == 1) {

			*PointerCredits = *PointerCredits + bonus[2];	// Updates the credits variable with an additional 1000 
			printf("\nYou are awarded 1000 extra credits!\n");
			printf("Your credits are now %d\n", *PointerCredits);

		}

		if (bonusinput == 2) {

			*PointerGold = *PointerGold + bonus[1];
			printf("\nYou are awarded 600 extra gold!\n");	// Updates the gold variable with an additional 600
			printf("Your gold is now %d\n ", *PointerGold);

		}

		if (bonusinput == 3) {

			if (bonus[0] == 0) {

				int remainder = *PointerGold % 2;
				int penalty = *PointerGold / 2;

				*PointerGold = penalty + remainder; // Updates the gold variable with a division of 2 + a modulo of 2 for the remainder

				printf("\nYour gold has been halved to %d\n", *PointerGold);

				return;

			}

			else {

				*PointerGold = *PointerGold * 2; // Updates the gold variable with a multiplication of 2
				printf("\nYour gold has been doubled to %d\n", *PointerGold);
				
				return;
			}


		}
	}



}