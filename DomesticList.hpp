#ifndef ENSC_251_FINAL_PROJECT_DOMESTICLIST_H
#define ENSC_251_FINAL_PROJECT_DOMESTICLIST_H

#include "domestic.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class DomesticNode {

public:

    DomesticStudent data;
    DomesticNode* next;
};
typedef DomesticNode* DomesticNodePtr;

class DomesticList{

    private:
        DomesticNodePtr head;
        DomesticNodePtr tail;

    public:
        //constructor + deconstructor
        DomesticList();
        ~DomesticList();

        //getters
        DomesticNodePtr getHead();
        DomesticNodePtr getTail();

        //insert function
        void insert(DomesticStudent& student);

        //delete functions
        void deleteNode(DomesticNodePtr student);
        void deleteHead();
        void deleteTail();
        void deleteHead_Tail();

        //print function
        void print();

        // search functions -- overloaded: first & last names, cgpa, id
        // non-overloaded: research score
        void search(const string &firstName, const string &lastName);
        void search(const float &CGPA) const;
        void search(const int &ID) const;
        void searchScore(const int &researchScore) const;

        // find functions (used as helpers for other functions)
        // functionally the same as search functions but does not print 
        DomesticNodePtr find(const string &firstName, const string &lastName);
        DomesticNodePtr find(const float &CGPA) const;
        DomesticNodePtr find(const int &ID) const;
        DomesticNodePtr findScore(const int &researchScore) const;

        //delete function -- first & last name
        void deleteExisting (string firstName, string lastName);
        
        //helpers for delete function
        bool isUpper (char check);
        string toLower (string name);
        bool findFirst (string name);
        bool findLast (string name);
        void switch_order(DomesticNodePtr previous);
        void switch_order_rev(DomesticNodePtr previous);

    //innovation: saving linked list data to a .txt file
    void writeToFile(ostream& os);
        
};
string lowerToUpper(string string);
#endif //ENSC_251_FINAL_PROJECT_DOMESTICLIST_H
