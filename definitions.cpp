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
 *  10/6/21 - initialized
 *  10/6/21 - randomIdGenerator, initializePlayerCard, and printPlayerScoreCard all completed
 *  10/11/21 - edited randomNum generators, as well as creating openFile and importPlayerScoreCards
 *  10/11/21 - built findLastName, importFile, and importPlayerScoreCards, fixed addition of player points (error with rounding average)
 *  10/13/21 - fixed double to 2 decimal places
 *  10/14/21 - added comments
 *  10/15/21 - Created Dynamic array
 * */



/////////////////////////////////// COPY PASTE BLOCK ///////////////////////////////////////

#include "header.h"

/**
 * Function: randomNumGenerator()
 * Date Created: 10/6/21
 * Date Last Modified: 10/11/21
 * Description: Generates a random integer between 1000 and 9999
 * @param: nothing
 * @return an random integer
 * @pre no random integer
 * @post a random integer between 1000 and 9999 returned
 * */
int randomIdGenerator()
{
    int randIndex;
    randIndex = (rand() % 10000) + 1000; //random index between 1000 and 9999 inclusive
    return (randIndex);
}

/**
 * Function: tossDart()
 * Date Created: 10/6/21
 * Date Last Modified: 10/11/21
 * Description: 'throws' a dart by generating a random number between 0 and 10, determining how well you threw
 * @param player the player passed by reference to add stats
 * @return nothing
 * @pre a non thrown dart
 * @post a result from throwing the dart printed out to console as well as added to player
 * */
void tossDart(PlayerCard& player)
{
    int randThrow;
    randThrow = (rand() % 11); //creates the random number between 0 and 10 inclusive

    cout << "You throw a dart!\n";

    //if throw misses
    if (randThrow == 0)
    {
        cout << "Oh man... you missed!\n";
    }

    //if throw is average
    else if (randThrow < 6)
    {
        cout << "Oof, nice try but you only hit a " << randThrow << ". You should try again!\n";
    }
    //if throw is above average
    else{
        cout << "Nice! You hit a " << randThrow << ". Time to move on I think!" << endl;
    }

    //increments player data
    player.numGamesPlayed ++;
    player.totalScore += randThrow;
    player.averageScore = ((double)player.totalScore/(double)player.numGamesPlayed);
}

/**
 * Function: findLastName()
 * Date Created: 10/11/21 
 * Date Last Modified: 10/14/21
 * Description: finds the index of the last letter of a name in the array
 * @param name the cstring representing the name of a player
 * @return the index of the last letter before '\0'
 * @pre an unknown index for last letter of name 
 * @post a known index for the last letter of name
 * */
int endOfName(char name[])
{
    int endLetter = -1;

    //for loop that goes till end of the char array if needed
    for (int i = 0; i < MAX_NAME_SIZE; i++)
    {
        //finds the empty spot indicated name is done
        if(name[i] == '\0')
        {
            endLetter = i - 1;
            //if there is room in the array, then add a space to the name
            if(i < MAX_NAME_SIZE - 1)
            {
                name[i+1] = '\0';
            }
            break;
        }
    }
    return endLetter;
}

/**
 * Function: initializePlayerScoreCard()
 * Date Created: 10/6/21
 * Date Last Modified: 10/6/21
 * Description: Accepts a playercard that is empty and fills it from console input
 * @param player is a pointer to a PlayerCard Structure
 * @return the PlayerCard as an output parameter, nothing explicity returned
 * @pre a pointer variable with no player information in it
 * @post the same playerCard with data filled by user
 * */
void initializePlayerScoreCard(PlayerCard* player)
{
    //storing data
    cin.getline(player->name, MAX_NAME_SIZE);
    player->playerId = randomIdGenerator();
    player->totalScore = 0;
    player->numGamesPlayed = 0;
    player->averageScore = 0.0;
}

/**
 * Function: printPlayerScoreCard()
 * Date Created: 10/6/21
 * Date Last Modified: 10/13/21
 * Description: Prints out to console the stats of a given player
 * @param player the player that is going to have their data printed
 * @return nothing
 * @pre a player with all their data taken as referenced, but unable to change
 * @post a printed out score card
 * */
void printPlayerScoreCard(const PlayerCard& player)
{
    //prints out player data passed in
    cout << "-----------------------|PID:" << player.playerId << "|\n";
    cout << player.name << "'s Score Card\n--------------------------------\n";
    cout << "Games Played: " << player.numGamesPlayed << endl;
    cout << "Running Score: " << player.totalScore << endl;

    //if the player hasn't played a game, then this is printed
    if(player.numGamesPlayed == 0)
    {
        cout << "No games played\n";
    }
    else
    {
        cout << "Average Score: " << player.averageScore << endl;
    }
    cout << "--------------------------------\n\n";
}

/**
 * Function: importFile()
 * Date Created: 10/11/21
 * Date Last Modified: 10/11/21
 * Description: opens the input file and returns success or not
 * @param infile the input file to be opened
 * @return true or false whether file was opened successfully
 * @pre an unopened input file
 * @post an opened input file
 * */
bool openFile(ifstream& infile)
{
    //simply opens the file and says whether it passes
    infile.open("playercards.txt");
    if(infile.is_open()){
        return true;
    }
    return false;
}

/**
 * Function: pushBackPlayerCard()
 * Date Created: 10/14/21
 * Date Last Modified: 10/14/21
 * Description: to act as a pushback function for dynamically allocated array
 * @param playerCard a pointer to an array of the playerCards
 * @param size the pointer to the size of the array
 * @param newPlayerCardData the new player card added to the array
 * @return nothing
 * @pre a smaller array without newPlayerCardData in it
 * @post a larger array with newPlayerCardData in it
 * */
void pushBackPlayerCard(PlayerCard** playerCard, int* size, PlayerCard newPlayerCardData)
{
    PlayerCard* playerCardArray = new PlayerCard[((*size) + 1)];

    //for the length of the original array
    for (int i = 0; i < (*size); i++)
    {
        playerCardArray[i] = (*playerCard)[i];
    }
    //adds the new Integer

    playerCardArray[(*size)] = newPlayerCardData;
    (*size) += 1;
    
    delete[] *playerCard;   
    *playerCard = playerCardArray;//issue transferring the address from one to another
}

/**
 * Function: importPlayerScoreCards()
 * Date Created: 10/6/21
 * Date Last Modified: 10/11/21
 * Description: Imports all of the people data from an input file and holds it in a vector
 * @param inputFile the input file to be read from
 * @param scoreCards the vector holding all the personal files
 * @return nothing
 * @pre an unopened and unread inputFile
 * @post an output parameter vector of playerCards
 * */
void importPlayerScoreCards(ifstream& inputFile, PlayerCard** scoreCards, int* size)
{
    PlayerCard player; //the player being imported 
    PlayerCard* playerPtr = &player; // a pointer to the player data
    char tempWord[MAX_NAME_SIZE]; //char array for getting the player first name
    char tempWord2[MAX_NAME_SIZE]; // char array for getting player last name
    int indexOfLastLetter; //the index of the laster letter of the first name
    int playerDataType = 0; //the type of data grabbed from the file in the 5 row format
    double averageScore = 0.0; //the average score of the player

    if(!openFile(inputFile))
    {
        cout << "Error opening file." << endl;
        return;
    }
    else
    {
        while (inputFile.good())
        {  
            inputFile >> tempWord;
            //if its not the name of the person don't attempt to get second word
            if(playerDataType != 1)
            {
                switch (playerDataType)
                {
                //handles the player ID
                case 0:
                    playerPtr->playerId = atoi(tempWord);
                    playerDataType ++;
                    break;
                
                //handles the player's total score
                case 2:
                    playerPtr->totalScore = atoi(tempWord);
                    playerDataType ++;
                    break;

                //handles the player's total games played
                case 3:
                    playerPtr->numGamesPlayed = atoi(tempWord);
                    playerDataType ++;
                    break;

                //handles the player's average score
                case 4:
                    averageScore = atof(tempWord);
                    playerPtr->averageScore = averageScore;
                    playerDataType = 0;
                    pushBackPlayerCard(scoreCards, size, player);
                    break;
                }
            }

            //handles the player's name
            else
            {
                indexOfLastLetter = endOfName(tempWord);

                //if the last letter isn't the end of the array
                if(indexOfLastLetter != -1)
                {
                    tempWord[indexOfLastLetter + 1] = ' ';
                }
                //concatenates the two words together with the space in between them
                inputFile >> tempWord2;
                strcat_s(tempWord, MAX_NAME_SIZE, tempWord2);
                strcpy_s(player.name, MAX_NAME_SIZE, tempWord);
                playerDataType ++;
            }
        }
    }
}