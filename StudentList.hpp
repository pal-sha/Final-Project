#ifndef ENSC_251_FINAL_PROJECT_STUDENTLIST_H
#define ENSC_251_FINAL_PROJECT_STUDENTLIST_H

#include "student.hpp"
#include "international.hpp"
#include "domestic.hpp"
#include "InternationalList.hpp"
#include "DomesticList.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Node {

    public:

        // Student types
        DomesticStudent DomStudent;
        InternationalStudent IntStudent;
        Student data;
        Node* next;

}; 
typedef Node* NodePtr;

class StudentList {

    private:

        NodePtr head;
        NodePtr tail;

        //helpers for overloaded assignment operator
        void deepCopy(const StudentList& copyList);
        void deleteAll();

    public:

        StudentList();
        ~StudentList();

        //getters
        NodePtr getHead();
        NodePtr getTail();

        //insert function
        void insert(Student& student);

        //search input threshold function
        void search(const float CGPA, const int research) const;

        //friend function defined in InternationalStudent class (used in merge)
        friend int ValidToefl(InternationalStudent& student); 

        //overload operator<<
        friend ostream &operator<<(ostream& outs, Student& student);

        //overload assignment operator (used for merge in main)
        StudentList &operator=(const StudentList& copyList);

        //merge function -- prints merged list
        StudentList merge(DomesticNodePtr domList, InternationalNodePtr intList); 
        //merge function -- does not print (used for main)
        StudentList createMerge(DomesticNodePtr domList, InternationalNodePtr intList);

        //innovation: saving linked list data to a .txt file
        void writeToFile(ostream& os);

};

#endif //ENSC_251_FINAL_PROJECT_STUDENTLIST_H
