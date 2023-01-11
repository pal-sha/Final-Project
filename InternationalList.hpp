#ifndef ENSC_251_FINAL_PROJECT_INTERNATIONALLIST_H
#define ENSC_251_FINAL_PROJECT_INTERNATIONALLIST_H

#include "international.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class InternationalNode {

public:

    InternationalStudent data;
    InternationalNode* next;
};
typedef InternationalNode* InternationalNodePtr;

class InternationalList{

private:
    InternationalNodePtr head;
    InternationalNodePtr tail;

public:
    //constructor & deconstructor
    InternationalList();
    ~InternationalList();

    //getters
    InternationalNodePtr getHead();
    InternationalNodePtr getTail();

    //insert function
    void insert(InternationalStudent& student);

    //delete function + helpers
    void deleteNode(InternationalNodePtr student);
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

    //  find functions (used as helpers for other functions)
    //  functionally the same as search functions but does not print 
    InternationalNodePtr find(const string &firstName, const string &lastName);
    InternationalNodePtr find(const float &CGPA) const;
    InternationalNodePtr find(const int &ID) const;
    InternationalNodePtr findScore(const int &researchScore) const;

    //delete function -- first & last name
    void deleteExisting (string firstName, string lastName);
    
    //helpers for delete function
    bool isUpper (char check);
    string toLower (string name);
    bool findFirst (string name);
    bool findLast (string name);
    void switch_order(InternationalNodePtr previous);

    //innovation: TOEFLgrant
    bool TOEFLgrant(InternationalNodePtr &stu) const;
    void printGrant();
    void hasGrant(const string& firstName, const string& lastName);

    //innovation: saving linked list data to a .txt file
    void writeToFile(ostream& os);
};
string lowerToUpper(string string);
#endif //ENSC_251_FINAL_PROJECT_INTERNATIONALLIST_H
