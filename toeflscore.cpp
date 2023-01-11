//header file toeflScore.hpp to declare ToeflScore classes
#include "toeflscore.hpp"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

//constructors
//default 
ToeflScore::ToeflScore() : reading(0), listening(0), speaking(0), writing(0) 
{
    //default : intentionally blank
}
ToeflScore::ToeflScore(int read, int listen, int speak, int write, int score)
{
    this -> reading = read;
    this -> speaking = speak;
    this -> listening = listen;
    this -> writing = write;
    this -> totalScore = score;

}


//setters
void ToeflScore::setReading(int read)
{
    this -> reading = read;
}
void ToeflScore::setListening(int listen)
{
    this -> listening = listen;
}
void ToeflScore::setSpeaking(int speak)
{
    this -> speaking = speak;
}
void ToeflScore::setWriting(int write)
{
    this -> writing = write;
}
void ToeflScore::setTotalScore(int score)
{
    this -> totalScore = score;
}


//getters
int ToeflScore::getReading()
{
    return this -> reading;
}
int ToeflScore::getListening()
{
    return this -> listening;
}
int ToeflScore::getSpeaking()
{
    return this -> speaking;
}
int ToeflScore::getWriting()
{
    return this -> writing;
}
int ToeflScore::getTotalScore()
{
    return this -> totalScore;
}


//compute total score
int ToeflScore::total() const
{
    int sum;
    sum = reading + speaking + listening + writing;
    return sum;
}