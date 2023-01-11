
#include "student.hpp"
#include "InternationalList.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

// Constructor
InternationalList::InternationalList() {
    head = NULL;
    tail = NULL;
}

// Destructor
InternationalList::~InternationalList() {

    InternationalNodePtr temp = head;
    while (head != NULL) {
        head = head->next;
        delete temp;
        temp = head;
    }

    head = NULL;
    tail = NULL;
}

// Getters
InternationalNodePtr InternationalList::getHead() {
    return head;
}

InternationalNodePtr InternationalList::getTail() {
    return tail;
}

// Function to insert a node
void InternationalList::insert(InternationalStudent& student) {

    // Storing head in a new temporary node pointer to traverse through linked list
    InternationalNodePtr currentNode = head;

    // Creating a new temporary node pointer which will hold new student data to traverse through the linked list
    InternationalNodePtr temp;

    // Robust error checking when allocating memory
    try {
        temp = new InternationalNode;
    }

    catch (std::bad_alloc) {
        cout << "bad_alloc error caught!" << endl;
    }

    // Storing new student's data inside temporary node pointer
    temp->data = student;
    temp->next = NULL;

    // In the case that linked list is empty, i.e. head == NULL
    // the new student node becomes both the head and tail
    if (head == NULL) {
        temp->next = head;
        head = temp;
        tail = temp;
        temp->next = NULL;
        return;
    }


    // If linked list is not empty,
    // Do not traverse through linked list under 3 conditions:
    // 1. Research score of new student is more than the most competitive student (the head node)
    // -------- OR --------
    // 2. Research score of new student is same as current node student AND CGPA of new student is more than current node student
    // -------- OR --------
    // 3. Research score AND CGPA of new student is same as current node student AND country of new student is more than current node student

    // In these three cases, the new student becomes the head and the original head becomes head->next
    if (       (compareResearchScore(head->data,temp->data) == 2)
               || ( compareResearchScore(head->data,temp->data) == 0
                    &&
                    compareCGPA(head->data,temp->data) == 2)
               || ( compareResearchScore(head->data, temp->data) == 0
                    &&
                    compareCGPA(head->data,temp->data) == 0
                    &&
                    compareCountry(head->data, temp->data) == 2))
    {
        temp->next = head;
        head = temp;
        return;
    }

    // Traverse through linked list under three conditions:
    // 1. If node after current node does not equal to NULL
    // -------- AND --------
    // Research score of new student is less than current node student
    // -------- OR --------
    // 2. Research score of new student is same as current node student AND CGPA of new student is less than current node student
    // -------- OR --------
    // 3. Research score of new student is same as current node student AND CGPA of new student is same as current node student AND country of new student is less than current node student

    while (   currentNode->next != NULL
              && (      (compareResearchScore(currentNode->next->data,temp->data) == 1)
                        || (compareResearchScore(currentNode->next->data,temp->data) == 0
                            &&
                            compareCGPA(currentNode->next->data,temp->data) == 1)
                        || (compareResearchScore(currentNode->next->data, temp->data) == 0
                            &&
                            compareCGPA(currentNode->next->data,temp->data) == 0
                            &&
                            compareCountry(currentNode->next->data, temp->data) == 0)
              )
            ) {
        currentNode = currentNode->next;
    }

    temp->next = currentNode->next;
    currentNode->next = temp;

    // If temp ends up at the end of the linked list, it is the new tail
    if (temp->next == NULL) {
        tail = temp;
    }
}


// Helper function to delete a node

// Function to delete a node

// Helper function to delete the head
void InternationalList::deleteHead() {

    // Check if list is empty or not
    if (head == NULL) {
        cout << "Linked list is empty." << endl;
        return;
    }

        // if head does exist
    else {

        // Store head in temporary variable pointer
        InternationalNodePtr temp = head;

        // Assign head to next node in line
        head = head->next;

        // Free temporary variable i.e. delete the head
        delete temp;
    }
}

// Helper function to delete the tail
void InternationalList::deleteTail() {

    // Check if list is empty or not
    if (head == NULL) {
        cout << "Linked list is empty." << endl;
        return;
    }

    // if head is the only node in the linked list, delete it
    if (head->next == NULL){
        delete head;
        head = NULL;
        return;
    }

    // In the case that head is not the only node in the linked list
    // Recurse through node for as long as there are two more nodes after the current node
    // When a node after which all pointers are NULL, stop traversing and exit loop
    // This is basically finding the second last node
    InternationalNodePtr currentNode = head;
    while (currentNode->next->next != NULL) {

        // Setting current node to the one after it
        currentNode = currentNode->next;
    }

    // Deleting the last node i.e. the tail
    delete (currentNode->next);

    // Setting the former second last node to be the tail
    tail = currentNode;

    // Setting the next pointer of last node/tail to NULL
    tail->next = NULL;

}

// Function to delete both head and tail
void InternationalList::deleteHead_Tail() {

    deleteHead();
    deleteTail();
}

// Search functions
InternationalNodePtr InternationalList::find(const string& firstName,const string& lastName){
    //declaring string variables to store input first and last names
    string userFirst = firstName; 
    string userLast = lastName;

    //setting temp pointer to head of current node
    InternationalNodePtr temp = head;
    //going through linked list until end is reached
    while (temp != nullptr)
    {   
        //converting user input and node data to lower case
        string nodeFirst = temp->data.getFirstName();
        string nodeLast = temp->data.getLastName();
        string lowerUserFirst = lowerToUpper(userFirst);
        string lowerNodeFirst = lowerToUpper(nodeFirst);
        string lowerUserLast = lowerToUpper(userFirst); 
        string lowerNodeLast = lowerToUpper(nodeLast);

        //comparing user input and node data until they match
        if (userFirst == nodeFirst && userLast == nodeLast) {
            return temp;
        }
        else
        //else go to next node
            temp = temp->next;
    }
    return nullptr;
}

void InternationalList::search(const string& firstName, const string& lastName){
    bool result = false;
    
    //declaring string variables to store input first and last names
    string userFirst = firstName; 
    string userLast = lastName;

    //setting temp pointer to head of current node
    InternationalNodePtr temp = head;
    //going through linked list until end is reached
    while (temp != nullptr)
    {   
        //converting user input and node data to lower case
        string nodeFirst = temp->data.getFirstName();
        string nodeLast = temp->data.getLastName();
        string lowerUserFirst = lowerToUpper(userFirst);
        string lowerNodeFirst = lowerToUpper(nodeFirst);
        string lowerUserLast = lowerToUpper(userFirst); 
        string lowerNodeLast = lowerToUpper(nodeLast);

        //comparing user input and node data until they match
        if (userFirst == nodeFirst && userLast == nodeLast) {
			cout << temp->data;
			result = true;
        }
        temp = temp->next;
    }

    if(result == false){
        cout << "There is no match found with this first and last name." << endl;
    }
}

InternationalNodePtr InternationalList::find(const float& CGPA) const{
    //setting temp to head of current node
    InternationalNodePtr temp = head;

    //going through linked list until it hits null
    while(temp != nullptr){
        //checks if user input matches with data of current node
        if(temp->data.getCGPA() == CGPA){
            return temp;
        } 
        else 
        //if no match, set pointer to next node
            temp = temp->next;
    }
    return nullptr;
}

void InternationalList::search(const float& CGPA) const{
    bool result = false;
    //setting temp to head of current node
    InternationalNodePtr temp = head;

    //going through linked list until it hits null
    while(temp != nullptr){
        //checks if user input matches with CGPA of current node
        if(temp->data.getCGPA() == CGPA){
            cout << temp->data;
            result = true;
        } 
        temp = temp->next;
    }

    if(result == false){
        cout << "There is no match with this CGPA." << endl;
    }
}

InternationalNodePtr InternationalList::find(const int& ID) const{
    //setting temp to head of current node
    InternationalNodePtr temp = head;

    //going through linked list until it hits null
    while(temp != nullptr){
        //checks if user input matches with ID of current node
        if(temp->data.getStudentID() == ID){
            return temp;
        }
        else
        //if no match, set pointer to next node
            temp = temp->next;
    }
    return nullptr;
}

void InternationalList::search(const int& ID) const{
    bool result = false;
    //setting temp to head of current node
    InternationalNodePtr temp = head;

    //going through linked list until it hits null
    while(temp != nullptr){
        //checks if user input matches with ID of current node
        if(temp->data.getStudentID() == ID){
            cout << temp->data;
            result = true;
        }
        temp = temp->next;
    }

    if(result == false){
        cout << "There is no match with this student ID." << endl;
    }
}

InternationalNodePtr InternationalList::findScore(const int& researchScore) const{
    //setting temp to head of current node
    InternationalNodePtr temp = head;

    //going through linked list until it hits null
    while(temp != nullptr){
        //checks if user input matches with research score of current node
        if(temp->data.getResearchScore() == researchScore){
            return temp;
        }
        else
        //if no match, set pointer to next node
            temp = temp->next;
    }
    return nullptr;
}

void InternationalList::searchScore(const int& researchScore) const{
    bool result = false;
    //setting temp to head of current node
    InternationalNodePtr temp = head;

    //going through linked list until it hits null
    while(temp != nullptr){
        //checks if user input matches with research score of current node
        if(temp->data.getResearchScore() == researchScore){
            cout << temp->data;
            result = true;
        }
        temp = temp->next;
    }

    if(result == false){
        cout << "There is no match with this research score." << endl;
    }
}

// Function to delete existing object based on user input
void InternationalList::deleteExisting (string firstName, string lastName) {

    InternationalNodePtr temp_h = head;
    InternationalNodePtr del_temp = head;

    if (findFirst(firstName) && findLast(lastName)) {
        //compare to see if the selected first and last name exists in the list 
        if (toLower(head->data.getFirstName()) == toLower(firstName) && toLower(head->data.getLastName()) == toLower(lastName)) {
            head = head->next;
            delete del_temp;
        }
        
        while (temp_h->next != NULL) {
            //search for link before the one that is to be deleted to switch order
            if (toLower(temp_h->next->data.getFirstName()) == toLower(firstName) && toLower(temp_h->next->data.getLastName()) == toLower(lastName)) {
                switch_order(temp_h);
            }
            temp_h = temp_h->next;
        }

        cout << "Student has been deleted from the list." << endl;
    }
    else {
        cout << "No students with this name exist in this list." << endl;
    }
}

//helper functions for deleteExixting
//helper function to check if any letters in the string are uppercase
bool InternationalList::isUpper (char check) {
    //if the ASCII value falls in the range A-Z return true
    if (check >= 'A' && check <= 'Z') {
        return 1;
    }
    return 0;
}

//helper function to convert any uppercase letters to lowercase
string InternationalList::toLower(string name) {
    for (int i = 0; i < name.size(); i++) {
        if (isUpper(name[i])) {
            //adding 32 to uppercase ASCII values converts them to lowercase
            name[i] = name[i] + 32;
        }
    }
    return name;
}

//helper function to find domestic objects with the same first name
bool InternationalList::findFirst (string name) {

    InternationalNodePtr temp_h = head;
    //create a variable whos value will increase if names are equal
    int inc = 0;

    //search list from head to tail
    while (temp_h != NULL) {
        //if names are equal after being converted to lowercase output 
        if (toLower(temp_h->data.getFirstName()) == toLower(name)) {
            //print out the data contained in the node
            cout << temp_h->data;
            //increase variable value 
            inc++;
        }
        temp_h = temp_h->next;
    }

    //if variable value has been increased return true to indicate names are equal
    if (inc != 0) {
        cout << "Student(s) with this first name exist." << endl;
        return 1;
    }
    if (inc == 0) {
        cout << "No students with this first name exist." << endl;
    }
    return 0;
}

//helper function to find domestic objects with the same last name
bool InternationalList::findLast (string name) {

    InternationalNodePtr temp_h = head;
    //create a variable whos value will increase if names are equal
    int inc = 0;

    //search list from head to tail
    while (temp_h != NULL) {
        //if names are equal after being converted to lowercase output 
        if (toLower(temp_h->data.getLastName()) == toLower(name)) {
            //print out the data contained in the node
            cout << temp_h->data;
            //increase variable value 
            inc++;
        }
        temp_h = temp_h->next;
    }

    //if variable value has been increased return true to indicate names are equal
    if (inc != 0) {
        cout << "Student(s) with this last name exist" << endl;
        return 1;
    }
    if (inc == 0) {
        cout << "No students with this last name exist" << endl;
        //return 0;
    }
    return 0;
}

//helper function to switch link order before deleting
void InternationalList::switch_order(InternationalNodePtr previous) {
    InternationalNodePtr temp;
    temp = previous->next;
    //link together the nodes before and after the node that has to be deleted
    previous->next = temp->next;
    delete temp;
}

//print function for main
void InternationalList::print(){
    InternationalNodePtr temp = head;

	while(temp != nullptr)
	{
		cout << temp->data;
		temp = temp->next;
	}
}

//innovation: TOEFLgrant
//Description: Checks if the international student has been awarded a grant.
bool InternationalList::TOEFLgrant(InternationalNodePtr &stu) const{
    if (stu->data.getToefl() >= 100){
        return true;
    }
    else return false;
}

//innovation: printGrant
//Description: Prints out students who achieved the TOEFL grant.
void InternationalList::printGrant(){

    //Setting temp pointer at the top of linked list
    InternationalNodePtr temp = head;

    //goes through whole list of international students
    while(temp != nullptr){
        if(temp)
            //finding students with >= 100 TOEFL score
            if(TOEFLgrant(temp) == true){
                cout << temp->data;
            }
            //goes to next node
            temp = temp->next;
    }
}

//innovation helper: hasGrant
//Description: Allows the user to search by first and last name if the student has received a TOEFL grant.
//             Function also prints the amount the student is awarded.
void InternationalList::hasGrant(const string& firstName, const string& lastName) {
    //findin user input
    InternationalNodePtr awardee = find(firstName, lastName);

    if(awardee == nullptr){
        cout << "This student cannot be found in the admission system." << endl;
        return;
    }

    if(TOEFLgrant(awardee) == true){
    cout << firstName << " " << lastName << " has been awarded a grant!" << endl;

    //Calculating awarded amount 
    int score = awardee->data.getToefl();
    int awarded = score * 5;
    
    cout << "The grant is worth $" << awarded << "." << endl;
    } 
    else {
        cout << firstName << " " << lastName << "is not qualified to receive the grant." << endl;
    }
}

void InternationalList::writeToFile(std::ostream &os) {
    if (head == NULL) {
        os << "Linked list is empty." << endl;
        return;
    }

    else {
        InternationalNodePtr temp = head;
        os << "------------------------------------------------------------" << endl;
        os << std::left << setw(6) << std::left << setw(12) << "FS"
           << std::left << setw(16) << "LS" << std::left << setw(10)
           << "COUNTRY";
        os << std::left << setw(12) << std::fixed << setprecision(2) << "CGPA"
           << std::left << setw(14) << "Score" << std::left << setw(14)
           << "Student ID" << endl;

        while (temp != NULL) {
            os << temp->data;
            temp = temp->next;
        }
    }
    os << endl;
}