//domestic.hpp to implement DomesticStudent class
#ifndef DOMESTIC_HPP
#define DOMESTIC_HPP

#include "student.hpp"

#include <vector>
#include <iostream>
#include <string>

using std::ostream;

class DomesticStudent : public Student {
    public:
        //constructor
        DomesticStudent();

        //setter
        //sets domestic student province
        void setProvince(string prov);

        //getter
        // returns domestic student province
        string getProvince() const;

        //overloading << operator
        friend ostream &operator <<(ostream& outs, DomesticStudent& student);

        //friend function to compare province
        friend int compareProvince(const DomesticStudent &stu1, const DomesticStudent &stu2);

        //print
        virtual void print(ostream& outs);

    private:
        string province; //where student is from
};

#endif