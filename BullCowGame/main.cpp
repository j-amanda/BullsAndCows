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
FText GetValidGuess();
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
	std::cout << "\n\nWelcome to Bulls & Cows, a fun word game." << std::endl;
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

	// Loop asking for guesses while game is NOT won
	// and there are still tries remaining

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ", Cows = " << BullCowCount.Cows << "\n\n";
	}
	return;

	// TODO summarize game
}

// loop continually until user gives a valid guess
FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";

	do {
		// get a guess from player 
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try #" << CurrentTry << ". " << "Enter your guess: ";
		std::getline(std::cin, Guess);

		// check guess validity
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word that is an isogram (no repeating letters).\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please only guess your word in lowercase.\n";
			break;
		case EGuessStatus::Not_Letters:
			std::cout << "Please only guess words (no numbers or spaces allowed!)\n";
			break;
		default:
			// assuming guess is valid
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); // keep looping until no errors
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);

	return(Response[0] == 'Y' || Response[0] == 'y');
}

