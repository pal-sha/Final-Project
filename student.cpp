//student.cpp to implement your classes
#include "student.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

//constructor
Student::Student()
{
    //default : intnetionally left blank
}


//setters
void Student::setApplicant(string first, string last, float CGPA, int score)
{
    this -> FirstName = first;
    this -> LastName = last;
    this -> cgpa = roundCGPA(CGPA);
    this -> researchScore = score;
}
void Student::setFirstName(string firstName)
{
    this -> FirstName = firstName;
}
void Student::setLastName(string lastName)
{
    this -> LastName = lastName;
}
void Student::setCGPA(float cGPA)
{
    float roundedCGPA = roundCGPA(cGPA);
    this->cgpa = roundedCGPA;
}
void Student::setResearchScore(int rScore)
{
    this -> researchScore = rScore;
}
void Student::setStudentID(int stuID)
{
    //application ID starts with 20220000 
    this -> studentID = stuID + 20220000; 
}


// getters
string Student::getFirstName() const
{
    return this -> FirstName;
}
string Student::getLastName() const
{
    return this -> LastName;
}
float Student::getCGPA() const
{
    return this -> cgpa;
}
int Student::getResearchScore() const
{
    return this -> researchScore;
}
int Student::getStudentID() const
{
    return this -> studentID;
}


//friend functions 
const int compareCGPA(const Student& stu1, const Student& stu2) {
    // Returns a different number for each situation: equal to, greater than, and less than

    // If student 1's CGPA is higher, return 0
    if (stu1.cgpa == stu2.cgpa)
    {
        return 0;

    // If student 2's CGPA is higher, return 1
    } else if (stu1.cgpa > stu2.cgpa)
    {
        return 1;
    // If both students have the same CGPA, return 2
    } else
    {
        return 2;
    }
}

const int compareResearchScore(const Student& stu1, const Student& stu2)
{
    // Returns a different number for each situation: equal to, greater than, and less than

    // If student 1's research score is higher, return 0
    if (stu1.researchScore == stu2.researchScore)
    {
        return 0;

    // If student 2's research score is higher, return 1
    } else if (stu1.researchScore > stu2.researchScore){

        return 1;

    // If both students have the same research score, return 2
    } else
    {
        return 2;
    }
}

const int compareFirstName(const Student& stu1, const Student& stu2)
{
    // Returns a different number for each situation: equal to, greater than, and less than
    // Returns 0 when both names are the same
    // Returns 1 when student 1's name comes first
    // Returns 2 when student 2's name comes first

    //Determining length of each name
    int name1Length = stu1.FirstName.length();
    int name2Length = stu2.FirstName.length();

    // Variable for return value of function that depends on shorter name
    // This variable is needed in the case that all the letters of the shorter name match the letters
    // of the longer name up to the index equal to last index of the short name.
    // eg. name1 = Karen, name2 = Karena (name1 is shorter and all its letters match the first 5 letters of name2)
    int shorter_name = 0;

    // This variable is used for the for loop that compares the names
    // Its value is set based on which name is shorter. The for loop below will iterate through shorter name.
    int end_index = 0;

    // If name1 length is greater
    if (name1Length > name2Length)
    {
        end_index = name2Length - 1;
        shorter_name = 2;

    // If name2 length is greater or name1 length is equal to name2 length
    // In the case that name1 length is equal to name2 length,
    // the value of shorter_name will be changed accordingly below
    } else {
        end_index = name1Length - 1;
        shorter_name = 1;
    }

    for (int i = 0; i <= end_index; i++)
    {
        // Alphabetically, if first letter in student 1's name is smaller than first letter in student 2's name
        if (stu1.FirstName[i] < stu2.FirstName[i]) {
            return 1;
        }

        // Alphabetically, if first letter in student 2's name is smaller than first letter in student 1's name
        if (stu1.FirstName[i] > stu2.FirstName[i]) {
            return 2;
        }
    }

    // If both names are the same:
    if (name1Length == name2Length) {
        return 0;
    } else {
        return shorter_name;
    }
}

const int compareLastName(const Student& stu1, const Student& stu2)
{
    // Returns a different number for each situation: equal to, greater than, and less than
    // Returns 0 when both names are the same
    // Returns 1 when student 1's name comes first
    // Returns 2 when student 2's name comes first

    //Determining length of each name
    int name1Length = stu1.LastName.length();
    int name2Length = stu2.LastName.length();

    // Variable for return value of function that depends on shorter name
    // This variable is needed in the case that all the letters of the shorter name match the letters
    // of the longer name up to the index equal to last index of the short name.
    // eg. name1 = Kell, name2 = Kelly (name1 is shorter and all its letters match the first 4 letters of name2)
    int shorter_name = 0;

    // This variable is used for the for loop that compares the names
    // Its value is set based on which name is shorter. The for loop below will iterate through shorter name.
    int end_index = 0;

    // If name1 length is greater
    if (name1Length > name2Length)
    {
        end_index = name2Length - 1;
        shorter_name = 2;

    // If name2 length is greater or name1 length is equal to name2 length
    // In the case that name1 length is equal to name2 length,
    // the value of shorter_name will be changed accordingly below
    } else {
        end_index = name1Length - 1;
        shorter_name = 1;
    }

    for (int i = 0; i <= end_index; i++)
    {
        // Alphabetically, if first letter in student 1's name is smaller than first letter in student 2's name
        if (stu1.LastName[i] < stu2.LastName[i]) {
            return 1;
        }

        // Alphabetically, if first letter in student 2's name is smaller than first letter in student 1's name
        if (stu1.LastName[i] > stu2.LastName[i]) {
            return 2;
        }
    }

    // If both names are the same:
    if (name1Length == name2Length) {
        return 0;
    } else {
        return shorter_name;
    }
}

//overloading << operator
ostream &operator <<(ostream&  outs, Student& student)
{
    student.print(outs);
    return outs;
}

void Student::print(ostream& outs){
    // output international student info based on sorting
    outs << std::left << setw(6) << std::left << setw(12) << getFirstName() << std::left << setw(16) << getLastName();
    outs << std::left << std::fixed << setw(10) << setprecision(1) << getCGPA() << std::left << setw(14) << getResearchScore() << std::left << setw(14) << getStudentID() << endl;
}

float Student::roundCGPA(float cgpa){
    float rounded;
    rounded = float(int(cgpa*10 + 0.5)) / 10;
    return rounded;
}