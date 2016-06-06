#pragma once
#include <string>

// do not include namespaces in header files, you can lose track of which namespaces you're using and where

class FBullCowGame 
{
public:
	FBullCowGame(); // constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO make a more rich return value
	bool CheckGuessValidity(std::string);

	// provide method for counting bulls and cows, incrementing turn


// please try and ignore this and focus on the interface above :)
private:
	// see constructor for initilization
	int MyCurrentTry;
	int MyMaxTries;
};