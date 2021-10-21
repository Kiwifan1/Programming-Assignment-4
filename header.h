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
 *  10/6/21 - created w/ basic libraries included
 *  10/13/21 - added <iomanip> for double manipulation
 *  10/14/21 - removed unneeded libraries
 **/

#ifndef HEADER_H
#define HEADER _H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_NAME_SIZE = 30; //global constant variable for max name length

//PlayerCard Structure
struct PlayerCard
{
    int playerId, numGamesPlayed, totalScore;
    string name;
    double averageScore;
};

int randomIdGenerator();

void tossDart(PlayerCard& player);

int endOfName(char name[]);

void pushBackPlayerCard(PlayerCard** playerCard, int* size, PlayerCard newPlayerCardData);

bool openFile(ifstream& infile);

void initializePlayerScoreCard(PlayerCard* player);

void printPlayerScoreCard(const PlayerCard& player);

void importPlayerScoreCards(ifstream& inputFile, PlayerCard** scoreCards, int* size);



#endif