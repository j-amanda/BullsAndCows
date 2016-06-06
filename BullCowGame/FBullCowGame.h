#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// do not include namespaces in header files, you can lose track of which namespaces you're using and where
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame 
{
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO make a more rich return value
	bool CheckGuessValidity(FString);

	FBullCowCount SubmitGuess(FString);


// please try and ignore this and focus on the interface above :)
private:
	// see constructor for initilization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};