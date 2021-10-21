/**
 * Name: Joshua Venable
 * Class: CPSC 122, Fall 2021
 * Date Created: October 6, 2021
 * Programming Assignment: PA3
 * Description: A program designed to showcase structures and c string library usage, while creating a dart throwing minigame within console
 * Notes:
 *  - Used Gaddis 3.7 to help with double rounding to 2 decimal points
 *  - I am attempting the extra credit
 * 
 * Last Updated:
 *  10/6/21 - Initialized main and PlayerCard
 *  10/6/21 - added first part of loop (error with not taking cin right now)
 *  10/11/21 - fixed taking cin, added random seed to main instead of in function call every time
 *  10/11/21 - finished off printing all other players, average score not working correctly
 *  10/13/21 - Fixed double going to 2 decimal places
 *  10/14/21 - added comments
 *  10/15/21 - Created dynamic array
 **/

#include "header.h"

int main()
{
    PlayerCard playerOne; //declares a playercard struct variable
    PlayerCard* playerOnePtr = &playerOne;
    ifstream infile; //read from input file
    //vector<PlayerCard> scoreCards;
    //PlayerCard scoreCards[1]; //dynamic array to the score cards from input file
    PlayerCard *scoreCardsPtr = new PlayerCard[0]; //pointer to dynamic array scoreCards
    int scoreCardsSize = 0; //size of scoreCards Dynamic array
    int *scoreCardsSizePtr = &scoreCardsSize; //pointer to size of scoreCards dynamic array
    bool play = true; //controls the game loop
    int hit = 0; // keeps track of hit sUsed Gaddis 3.7 to help with double rounding to 2 decimal pointscore for each throw
    char choice = '\0'; //keeps track of play/not play choice

    srand(time(0)); //set random seed
    cout << "Welcome to the game of darts!\nIt's completely skill-based and not random luck, I promise!\n...\n*wink*" << endl;
    cout << "Please enter a player name (first and last separated by a space):\n";
    
    initializePlayerScoreCard(playerOnePtr);
        
    cout << "Your game card:\n";
    printPlayerScoreCard(playerOne);

    //while loop to continue program for throwing darts until user wants to stop
    while(play){
        tossDart(playerOne);
        cout << "Keep playing? (y/n) ";
        cin >> choice;
        // if user wants to stop
        if(tolower(choice) == 'n')
        {
            cin.clear();
            play = false;
        }
        //else if user wants to continue
        else if(tolower(choice) == 'y'){
            cin.clear();
        }
    }

    //prints out user score card
    cout.precision(3); //this sets decimal places to 2
    cout << "Here's your final score card!" << endl;
    printPlayerScoreCard(playerOne);
    cout << endl << endl;

    //imports and prints out all opponent score cards
    importPlayerScoreCards(infile, &scoreCardsPtr, scoreCardsSizePtr);
    
    cout << "See how your score compares to previous players:\n";
    for (int i = 0; i < scoreCardsSize; i++)
    {
        printPlayerScoreCard(scoreCardsPtr[i]);
        cout << endl << endl;
    }
    delete[] scoreCardsPtr;
    return 0;
}