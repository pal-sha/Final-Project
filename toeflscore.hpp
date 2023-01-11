
#ifndef TOEFLSCORE_HPP
#define TOEFLSCORE_HPP

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class ToeflScore {
    public:
        //constructors
        //default
        ToeflScore();
        ToeflScore(int read, int listen, int speak, int write, int score);


        //setters
        //setting reading score
        void setReading(int read);
        //setting listening score
        void setListening(int listen);
        //setting speaking score
        void setSpeaking(int speak);
        //setting writing score
        void setWriting(int write);
        //setting total score
        void setTotalScore(int score);


        // getters
        int getReading();
        int getListening();
        int getSpeaking();
        int getWriting();
        int getTotalScore();


        //calculates total score
        int total() const;

    private:
        //score from 0 to 30 possible
        int reading;
        int listening;
        int speaking;
        int writing;
        int totalScore; //out of 120
};

#endif



