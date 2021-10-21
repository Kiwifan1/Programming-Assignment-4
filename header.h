/**
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
 *  10/20/21 - edited header to deal with strings instead of cstrings
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

//PlayerCard Class
class PlayerCard
{
private:
    int playerId, numGamesPlayed, totalScore;
    string name;
    double averageScore;
public:
    PlayerCard();
    PlayerCard(string name, int id = 0);

    //getters
    int getPlayerId() const;
    int getNumGames() const;
    int getScore() const;
    string getName() const;
    double getAverage() const;
    void setPlayerId(int id);
    void setAverage(double average);

    //setters
    void generatePlayerId(void);
    void generatePlayerId(int);
    void updateAverageScore(void);
    void setName(string name);
    void addGame();
    void setScore(int score);
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