/*  This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all user interaction.
For game logic see the FBullCowGame class.
*/
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

using namespace std;

void PrintIntro();
void PlayGame();
void PrintGuess(FText);
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; // instantiate a new game


// the entry point of the application
int main()
{
	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());
	return 0; // exit the application
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	
	// loop asking for guesses while the game is NOT won and there are still tries left
	// TODO change from FOR to WHILE loop once we are validating tries
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		
		//FText Guess = GetValidGuess();



		PrintGuess(GetValidGuess());
	}

	cout << endl;
	PrintGameSummary();
	return;
}

// introduce the game
void PrintIntro()
{
	cout << "\n\nWelcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	cout << " letter isogram I'm thinking of?\n";
	return;
}

// loop continually until the user gives a valid guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		// get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		cout << endl;
		cout << "Try #" << CurrentTry << " of " << BCGame.GetMaxTries(); 
		cout << ". What is your Guess? ";
		getline(cin, Guess); //  TODO make loop checking valid

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n";
			break;
		case EGuessStatus::Not_Isogram:
			cout << "Please enter a word without repeating letters. \n";
			break;
		case EGuessStatus::Not_Lowercase:
			cout << "Please enter only lowercase letters. \n";
			break;
		default:
			// assume the guess is valid
			break;
		}
		//cout << endl;
	} while (Status != EGuessStatus::OK); // keep looping until Status is ok...
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again with the same hidden word (y/n)? ";
	FText Response = "";
	getline(cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');	
}

//repeat the guess back to the player
void PrintGuess(FText Guess)
{
	//  TODO Submit valid guess to the game
	FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
	// Print number of bulls and cows
	cout << "Bulls = " << BullCowCount.Bulls;
	cout << ". Cows = " << BullCowCount.Cows << endl;
	// cout << "You Guessed: " << Guess << endl;
	return;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		cout << "WELL DONE - YOU WIN!\n";
	}
	else
	{
		cout << "Better luck next time!\n";
	}
}