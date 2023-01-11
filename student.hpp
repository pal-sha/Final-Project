//header file student.hpp to declare your classes
#include <string> //you will have to use string in C++
#include <vector>
#include <iomanip>
using namespace std; //use namespace std


#ifndef STUDENT_HPP
#define STUDENT_HPP

class Student{   
    public:
        //constructor 
        Student();


        //setters
        //setting student info
        void setApplicant(string first, string last, float cgpa, int score);
        //setting first name
        void setFirstName(string firstName);
        //setting last name
        void setLastName(string lastName);
        //setting cgpa
        void setCGPA(float cGPA);
        //setting research score 
        void setResearchScore(int rScore);
        //setting student applicant ID
        void setStudentID(int stuID);
        
        
        //getters
        //return first name
        string getFirstName() const;
        //return last name
        string getLastName() const;
        //return research score
        int getResearchScore() const;
        //return student application ID
        int getStudentID() const;
        //return CGPA 
        float getCGPA() const;
        //helper to round cgpa;
        float roundCGPA(float cgpa);

        //friend functions
        //compares CGPA and tells if equal to, greater than, and less than
        friend const int compareCGPA(const Student& stu1, const Student& stu2);
        //compares research score and tells if equal to, greater than, and less than
        friend const int compareResearchScore(const Student& stu1, const Student& stu2);
        //compares first name and tells if equal to, greater than, and less than
        friend const int compareFirstName(const Student& stu1, const Student& stu2);
        //compares last name and tells if equal to, greater than, and less than
        friend const int compareLastName(const Student& stu1, const Student& stu2);
        //overloading << operator
        friend ostream &operator <<(ostream& outs, Student& student);
        //virtual print
        virtual void print(ostream& outs);
    private:
        string FirstName;
        string LastName;
        //cgpa at sfu is a 4.3 scale
        float cgpa;
        //research score from 0-100
        int researchScore;
        //8 digit student ID
        int studentID;    
};

#endif

