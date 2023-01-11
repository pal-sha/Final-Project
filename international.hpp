//international.hpp to implement InternationalStudent class
#ifndef INTERNATIONAL_HPP
#define INTERNATIONAL_HPP

#include "student.hpp"
#include "toeflscore.hpp"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class InternationalStudent : public Student {
    public:
        //constructor
        InternationalStudent(); 

        //setters
        //sets international student country
        void setCountry(string count);
        //sets international student total TOEFL score
        void setToefl(int read, int listen, int speak, int write);
        
        //getters
        //returns international student country
        string getCountry() const;
        //returns international student total TOEFL score
        int getToefl() const;

        //overloading << operator
        friend ostream &operator <<(ostream& outs, InternationalStudent& student);

        //friend function to compare countries
        friend int compareCountry(const InternationalStudent& stu1, const InternationalStudent& stu2);

        //friend function to check if TOEFL scores are valid
        friend int ValidToefl(InternationalStudent& student);
        
        //virtual print function
        virtual void print(ostream& outs);

    private:
        string country; //where student is from
        ToeflScore toefl;
};

#endif