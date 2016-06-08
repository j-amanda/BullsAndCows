/* 
This is the console executable that makes use of the Bull Cow Class.
This acts as the view in a MVC pattern and is responsible for all 
user interaction. For game logic, see the FBUllCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// Unreal Engine coding standards:
using FText = std::string; 
using int32 = int; 

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// the entry point for our application
int main() 
{
	PrintIntro();
	do {
		PlayGame();
	} while (AskToPlayAgain());

	return 0;
}


// introduce the game
void PrintIntro()
{
	int32 WordLength = BCGame.GetHiddenWordLength();
	std::cout << "Welcome to Bulls & Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WordLength;
	std::cout << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;

	return;
}

// main body of the game
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	constexpr int32 NUMBER_OF_GUESSES = 5;

	// Loop for the number of turns to guess
	
	for (int32 count = 0; count < MaxTries; count++) // TODO  change from FOR to WHILE loop once we are validating tries
	{
		FText Guess = GetGuess(); // TODO make loop checking valid

		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ", Cows = " << BullCowCount.Cows; 
		std::cout << std::endl;

	}
	return;

	// TODO summarize game
}

// get a guess from the player
FText GetGuess() // TODO change to GetValidGuess
{
	int32 CurrentTry = BCGame.GetCurrentTry();

	FText Guess = "";
	std::cout << "Try #" << CurrentTry << ". ";
	std::cout << "Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);

	return(Response[0] == 'Y' || Response[0] == 'y');
}

