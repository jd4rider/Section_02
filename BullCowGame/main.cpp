#include <iostream>
#include <string>
#include "FBullCowGame.h"

using namespace std;

void PrintIntro();
void PlayGame();
void PrintGuess(string);
string GetGuess();
bool AskToPlayAgain();

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
	int MaxTries = BCGame.GetMaxTries();

	
	// loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE loop once we are validating tries
	for (int count = 1; count <= MaxTries; count++)
	{
		PrintGuess(GetGuess());  
	}

	// TODO Summarise Game

	cout << endl;
	return;
}

// introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	return;
}

// get guess from the player
string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();

	string Guess = "";
	cout << endl;
	cout << "Try #" << CurrentTry << ". What is your Guess? ";
	getline(cin, Guess); //  TODO make loop checking valid
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again (y/n)? ";
	string Response = "";
	getline(cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');	
}

//repeat the guess back to the player
void PrintGuess(string a)
{
	//  TODO Submit valid guess to the game
	// Print number of bulls and cows
	cout << "You Guessed: " << a << endl;
	return;
}