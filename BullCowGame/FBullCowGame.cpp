#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() // constructor
{
	Reset();
}

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }  
// const function disallows function from changing properties of object (such as variables)
// will not change anything at run time
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

