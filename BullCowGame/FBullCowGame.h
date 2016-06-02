#pragma once
#include <string>

// do not include namespaces in header files, you can lose track of which namespaces you're using and where

class FBullCowGame 
{
public:
	void Reset(); // TODO make a more rich return value
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string);
	int NumberOfGamesWon();


// please try and ignore this and focus on the interface above :)
private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};