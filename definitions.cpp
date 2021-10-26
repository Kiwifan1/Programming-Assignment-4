/**
 * Name: Joshua Venable
 * Class: CPSC 122, Fall 2021
 * Date Created: October 20, 2021
 * Programming Assignment: PA4
 * Description: A program designed to showcase structures and c string library usage, while creating a dart throwing minigame within console
 * Notes:
 *  
 * 
 * Last Updated:
 *  10/20/21 - edited definitions to deal with strings instead of cstrings
 *  10/20/21 - created getter methods
 *  10/21/21 - created some getter and some setter methods
 *  10/21-22/21 - edited a majority of the functions, so that they were able to use the player functions, rather than accessing directly
 *  10/26/21 - added more javadoc comments, deprecated the array
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
 * Name: Joshua Venable
 * Date created: 10/21/21
 * Date last modified: 10/26/21
 * Description: default constructor for player object
 * @pre unmade player object
 * @post player object held in memory
 **/
PlayerCard::PlayerCard()
{
    PlayerCard("", -1);
}

/**
 * Name: Joshua Venable
 * Date created: 10/21/21
 * Date last modified: 10/26/21
 * Description: constructor making the player Object with parameters
 * @param name the string of the name going to be set
 * @param id the number of id going to be set
 * @pre unmade player object
 * @post player object held in memory
 **/
PlayerCard::PlayerCard(string name, int id)
{
    this->name = name;
    if(id == -1){
        generatePlayerId();
    }
    else{
        setPlayerId(id);
    }
    this->name = name;
    this->totalScore = 0;
    this->averageScore = 0.0;
    this->numGamesPlayed = 0;
}

/**
 * Name: Joshua Venable
 * Date created: 10/26/21
 * Date last modified: 10/26/21
 * Description: destructor for playerCard Object
 * @pre object of player
 * @post freed memory
 **/
PlayerCard::~PlayerCard()
{
    
}

/**
 * Name: Joshua Venable
 * Date created: 10/20/21
 * Date last modified: 10/20/21
 * Description: returns the ID of the player object
 * @return the integer representing the ID of the object
 * @pre unknown ID number
 * @post returned ID number
 **/
int PlayerCard::getPlayerId() const
{
    return this->playerId;
}

/**
 * Name: Joshua Venable
 * Date created: 10/20/21
 * Date last modified: 10/20/21
 * Description: returns the number of games a player has played in total
 * @return the total amount of games played
 * @pre unknown total games played
 * @post returned total games played
 **/
int PlayerCard::getNumGames() const
{
    return this->numGamesPlayed;
}

/**
 * Name: Joshua Venable
 * Date created: 10/20/21
 * Date last modified: 10/20/21
 * Description: returns the total score of a player
 * @return the total score of specific player object
 * @pre unknown total player score
 * @post returned total player score
 **/
int PlayerCard::getScore() const
{
    return this->totalScore;
}

/**
 * Name: Joshua Venable
 * Date created: 10/20/21
 * Date last modified: 10/20/21
 * Description: returns the name of the player object
 * @return string of the player name
 * @pre unknown player name
 * @post returned player name as string
 **/
string PlayerCard::getName() const
{
    return this->name;
}

/**
 * Name: Joshua Venable
 * Date created: 10/20/21
 * Date last modified: 10/20/21
 * Description: returns the average of the player's games
 * @return double average of games of object
 * @pre unknown average
 * @post returned average score
 **/
double PlayerCard::getAverage() const
{
    return this->averageScore;
}

/**
 * Name: Joshua Venable
 * Date created: 10/20/21
 * Date last modified: 10/20/21
 * Description: Sets the player object's id from a parameter
 * @param id the integer of id to be set
 * @return nothing
 * @pre an empty id identifier for a player
 * @post a set id identifier for a player
 **/
void PlayerCard::setPlayerId(int id)
{
    this->playerId = id;
}

/**
 * Name: Joshua Venable
 * Date created: 10/20/21
 * Date last modified: 10/20/21
 * Description: sets the average score for a player from a parameter
 * @param average the average score passed as a double
 * @return nothing
 * @pre an empty average score
 * @post a filled average score for player object
 **/
void PlayerCard::setAverage(double average)
{
    this->averageScore = average;
}

/**
 * Name: Joshua Venable
 * Date created: 10/20/21
 * Date last modified: 10/20/21
 * Description: generates a player id in case the player does not have one yet
 * @return nothing
 * @pre an unknown player ID
 * @post a set and known player ID set
 **/
void PlayerCard::generatePlayerId(void)
{
    int randomId = randomIdGenerator();
    PlayerCard::setPlayerId(randomId);
}

/**
 * Name: Joshua Venable
 * Date created: 10/20/21
 * Date last modified: 10/20/21
 * Description: overloaded function generating player Id if the id is given as a a parameter
 * @param id the id going to be set to player
 * @return nothing
 * @pre unknown player id
 * @post a known and set player id from parameter
 **/
void PlayerCard::generatePlayerId(int id)
{
    PlayerCard::setPlayerId(id);
}

/**
 * Name: Joshua Venable
 * Date created: 10/20/21
 * Date last modified: 10/20/21
 * Description: updates the average score whenever a score is hit for the player object
 * @return nothing
 * @pre the previous average score for games
 * @post the new average score
 **/
void PlayerCard::updateAverageScore(void)
{
    double averageScore;
    if(this->totalScore == 0)
    {
        setAverage(0);
        return;
    }
    averageScore = ((double)this->totalScore / (double)this->numGamesPlayed);
    setAverage(averageScore);
}

/**
 * Name: Joshua Venable
 * Date created: 10/20/21
 * Date last modified: 10/20/21
 * Description: sets the name of the player from parameter
 * @param name the name of player as a string
 * @return nothing
 * @pre unknown player name
 * @post known and set player name
 **/
void PlayerCard::setName(string name)
{
    this->name = name;
}

/**
 * Name: Joshua Venable
 * Date created: 10/20/21
 * Date last modified: 10/20/21
 * Description: sets the total amount of games played of a players
 * @param numGames the total amount of games played
 * @return nothing
 * @pre the previous amount of total games played
 * @post the new amount of total games played
 **/
void PlayerCard::setGames(int numGames)
{
    this->numGamesPlayed = numGames;
}

/**
 * Name: Joshua Venable
 * Date created: 10/20/21
 * Date last modified: 10/20/21
 * Description: sets the total score of the player from parameter
 * @param score the score of player as an integer to be updated to the object
 * @return nothing
 * @pre the previous score held in object
 * @post the new score held in object
 **/
void PlayerCard::setScore(int score)
{
    this->totalScore = score;
}

/**
 * Name: Joshua Venable
 * Date created: 10/26/21
 * Date last modified: 10/26/21
 * Description: simple helper function that prints out all of the imported players
 * @param scoreCards the vector holding all the player data
 * @return nothing
 * @pre non printed out but held imported players
 * @post printed out all players
 **/
void printAllPlayerCards(vector<PlayerCard> scoreCards)
{
    for (int i = 0; i < scoreCards.size(); i++)
    {
        printPlayerScoreCard(scoreCards.at(i));
        cout << endl << endl;
    }
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
    player.setGames(player.getNumGames() + 1);
    player.setScore(player.getScore() + randThrow);
    player.updateAverageScore();
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
    string name;
    cout << "Please enter a player name (first and last separated by a space):\n";
    getline(cin, name);
    player->setName(name);
    player->generatePlayerId();
    player->setGames(0);
    player->setScore(0);
    player->updateAverageScore();
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
    cout << "-----------------------|PID:" << player.getPlayerId() << "|\n";
    cout << player.getName() << "'s Score Card\n--------------------------------\n";
    cout << "Games Played: " << player.getNumGames() << endl;
    cout << "Running Score: " << player.getScore() << endl;

    //if the player hasn't played a game, then this is printed
    if(player.getNumGames() == 0)
    {
        cout << "No games played\n";
    }
    else
    {
        cout << "Average Score: " << player.getAverage() << endl;
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
 * @deprecated no longer needed because I switched back to a vector
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
 * Date Last Modified: 10/20/21
 * Description: Imports all of the people data from an input file and holds it in a vector
 * @param inputFile the input file to be read from
 * @param scoreCards the vector holding all the personal files
 * @return nothing
 * @pre an unopened and unread inputFile
 * @post an output parameter vector of playerCards
 * */
void importPlayerScoreCards(ifstream& inputFile, vector<PlayerCard>& scoreCards)
{
    stringstream scanner;
    PlayerCard player = PlayerCard(); //the player being imported 
    PlayerCard* playerPtr = &player; // a pointer to the player data
    string tempWord; //char array for getting the player first name
    string tempWord2; // char array for getting player last name
    string name; //name of the player
    int id;
    int totalScore;
    int numGamesPlayed;
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
                    istringstream(tempWord) >> id;
                    playerPtr->generatePlayerId(id);
                    playerDataType ++;
                    break;
                
                //handles the player's total score
                case 2:
                    istringstream(tempWord) >> totalScore;
                    playerPtr->setScore(totalScore);
                    playerDataType ++;
                    break;

                //handles the player's total games played
                case 3:
                    istringstream(tempWord) >> numGamesPlayed;
                    playerPtr->setGames(numGamesPlayed);
                    playerDataType ++;
                    break;

                //handles the player's average score
                case 4:
                    istringstream(tempWord) >> averageScore;
                    playerPtr->updateAverageScore();
                    playerDataType = 0;
                    scoreCards.push_back(*playerPtr);
                    break;
                }
            }

            //handles the player's name
            else
            {
                //concatenates the two words together with the space in between them
                inputFile >> tempWord2;

                name = tempWord + " " + tempWord2;
                player.setName(name);
                playerDataType ++;
            }
        }
    }
}