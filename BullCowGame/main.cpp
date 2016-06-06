#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
void PrintGuess(std::string guess);
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game

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
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls & Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;

	return;
}

// main body of the game
void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();
	constexpr int NUMBER_OF_GUESSES = 5;

	// Loop for the number of turns to guess
	// TODO  change from FOR to WHILE loop once we are validating tries
	for (int count = 0; count < MaxTries; count++)
	{
		std::string Guess = GetGuess(); // TODO make loop checking valid

		// Submit valid guess to the game
		// Print number of bulls and cows

		PrintGuess(Guess);
	}
	return;

	// TODO summarize game
}

// get a guess from the player
std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();

	std::string Guess = "";
	std::cout << "Try #" << CurrentTry << ". ";
	std::cout << "Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

void PrintGuess(std::string guess) 
{
	std::cout << "Your guess was: " << guess << std::endl;
	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	std::getline(std::cin, Response);

	return(Response[0] == 'Y' || Response[0] == 'y');
}

