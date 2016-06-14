#include "FBullCowGame.h"
#include <map>
# define TMap std::map

FBullCowGame::FBullCowGame() // constructor
{
	Reset();
}

// const function disallows function from changing properties of object (such as variables)
// will not change anything at run time

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const // TODO replace false with methods
{
	if (!IsIsogram(Guess)) // not an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) // not all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) // wrong length
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 5;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

// receives a valid guess, increments turn, and returns count of Bulls & Cows
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	int32 WordLength = MyHiddenWord.length(); // assuming same length as guess

	// compare guess to isogram:
	for (int32 i = 0; i < WordLength; i++) 
	{
		for (int32 j = 0; j < WordLength; j++) 
		{
			if (Guess[j] == MyHiddenWord[i]) // runs only if letters match position i and j
			{ 
				if (j == i) // only if letters match in same position we'll add a bull
				{ 
					BullCowCount.Bulls++;
				}
				else 
				{
					BullCowCount.Cows++;
				}
			}
		}
	}

	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}

	return BullCowCount;
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word) 
	{
		if (!islower(Letter)) 
		{
			return false;
		}
	}
	return true;
}

bool FBullCowGame::IsIsogram(FString Word) const 
{ 
	// treat 0 and 1 letter words as isogram
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;
	for (auto Letter : Word) 
	{
		Letter = tolower(Letter); // handle mixed case words

		// if the letter doesn't exist in the map then add it, 
		// otherwise return false because we have a duplicate letter
		if (!LetterSeen[Letter]) 
		{
			LetterSeen[Letter] = true;
		}
		else 
		{
			return false;
		}
	}
	return true; 
}