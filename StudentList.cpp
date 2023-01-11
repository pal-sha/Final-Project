#include "StudentList.hpp"
#include "DomesticList.hpp"
#include "InternationalList.hpp"
#include "domestic.hpp"
#include "international.hpp"
#include "student.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Constructor
StudentList::StudentList() {
  head = NULL;
  tail = NULL;
}

// Destructor
StudentList::~StudentList() {

  NodePtr temp = head;
  while (head != NULL) {
    head = head->next;
    delete temp;
    temp = head;
  }

  head = NULL;
  tail = NULL;
}

// Getters
NodePtr StudentList::getHead() { return head; }

NodePtr StudentList::getTail() { return tail; }

// Function to insert node
void StudentList::insert(Student &student) {

    // Storing head in a new temporary node pointer to traverse through linked list
    NodePtr currentNode = head;

    // Creating a new temporary node pointer which will hold new student data to traverse through the linked list
    NodePtr temp;

    // Robust error checking when allocating memory
    try {
        temp = new Node;
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

    // Do not traverse through linked list under two conditions:
    // 1. Linked list is empty, i.e. head == NULL
    // -------- OR --------
    // 2. Research score of new student is more than the most competitive student (the head node)

    // In these two cases, the new student becomes the head and the original head becomes head->next
    if (    (compareResearchScore(head->data,temp->data) == 2)
            || ( compareResearchScore(head->data,temp->data) == 0
                 &&
                 compareCGPA(head->data,temp->data) == 2
            )
            || ( compareResearchScore(head->data, temp->data) == 0
                 &&
                 compareCGPA(head->data,temp->data) == 0
                 &&
                 temp->data.getStudentID()>20220100
            )
            ) {

        temp->next = head;
        head = temp;
        return;
    }

    // Traverse through linked list under three conditions:
    // 1. If node after current node does not equal to NULL AND research score of new student is less than current node student
    // -------- OR --------
    // 2. Research score of new student is same as current node student AND CPGA of new student is less than current node student
    // -------- OR --------
    // 3. Research score of new student is same as current node student AND CGPA of new student is same as current node student AND province of new student is less than current node student

    while (   currentNode->next != NULL
              && (        ( compareResearchScore(currentNode->next->data,temp->data) == 1)
                          || ( compareResearchScore(currentNode->next->data,temp->data) == 0
                               &&
                               compareCGPA(currentNode->next->data,temp->data) == 1
                          )
                          || ( compareResearchScore(currentNode->next->data, temp->data) == 0
                               &&
                               compareCGPA(currentNode->next->data,temp->data) == 0
                               &&
                               temp->data.getStudentID()>20220100
                          )
              )
            ) {
        currentNode = currentNode->next;
    }

    temp->next = currentNode->next;

    /*if (currentNode == head) {
        head = temp;
    }*/

    currentNode->next = temp;

    // If temp ends up at the end of the linked list, it is the new tail
    if (temp->next == NULL) {

        tail = temp;
    }

}

// Search functions
void StudentList::search(const float CGPA, const int research) const {
  bool result = false;
  NodePtr temp = head;

  while (temp != nullptr) {
    if (temp->data.getCGPA() >= CGPA &&
        temp->data.getResearchScore() >= research) {
      cout << temp->data;
      result = true;
    }
    temp = temp->next;
  }

  if (result == false) {
    cout << "There is no match with this input threshold." << endl;
  }
}


// Merge function
StudentList StudentList::merge(DomesticNodePtr domList, InternationalNodePtr intList) {
  // declaring variable for the merged domestic & international student linked
  // list
  StudentList merged;

  // declaring temp variables for pointers to domestic & international lists to
  // be merged
  DomesticNodePtr tempDom = domList;
  InternationalNodePtr tempInt = intList;

  // inserting domestic students
  while (tempDom != NULL) {
    // using insert node function in list object
    merged.insert(tempDom->data);
    // going to next node
    tempDom = tempDom->next;
  }

  // after domestic students added, merge international students
  while (tempInt != NULL) {
    // using insert node function in list object
    merged.insert(tempInt->data);
    // going to next node
    tempInt = tempInt->next;
  }

  // storing pointer to merged linked list in a variable
  NodePtr mergedHead = merged.getHead();
  DomesticNodePtr domestic = domList;
  InternationalNodePtr international = intList;

  while (mergedHead != NULL && domestic != NULL && international != NULL)
  {
    // printing international
    if (mergedHead->data.getStudentID() >= 20220101)
    {
      // must only print those with toefl scores within valid range
      if (ValidToefl(international->data) == 1)
      {
        cout << international->data;
      }
      international = international->next;
    }
    // printing domestic
    else if (mergedHead->data.getStudentID() < 20220101)
    {
      cout << domestic->data;
      domestic = domestic->next;
    }
    // go to next node
    mergedHead = mergedHead->next;
  }
  // return merged list
  return merged;
}

StudentList StudentList::createMerge(DomesticNodePtr domList,
                                     InternationalNodePtr intList) {
  // declaring variable for the merged domestic & international student linked
  // list
  StudentList merged;

  // declaring temp variables for pointers to domestic & international lists to
  // be merged
  DomesticNodePtr tempDom = domList;
  InternationalNodePtr tempInt = intList;

  // inserting domestic students
  while (tempDom != nullptr) {
    // using insert node function in list object
    merged.insert(tempDom->data);
    // going to next node
    tempDom = tempDom->next;
  }

  // after domestic students added, merge international students
  while (tempInt != nullptr) {
    // using insert node function in list object
    merged.insert(tempInt->data);
    // going to next node
    tempInt = tempInt->next;
  }

  return merged;
}

//assignment operator
StudentList &StudentList::operator=(const StudentList &copyList){
  if (this != &copyList){
    deleteAll();
    deepCopy(copyList);
  }
  return *this;
}

// helpers for assignment operator
void StudentList::deepCopy(const StudentList &copyList){
  //create new copy node
  head = NULL;
  NodePtr newNode = NULL;
  NodePtr copyNode = copyList.head;

  //traverse through linked list if it is not empty
  if (copyNode != NULL){
    try
    {
      head = new Node;
    }
    catch (std::bad_alloc &)
    {
      cout << "Caught bad_alloc exception." << endl;
    }
    
    head->data = copyNode->data;
    copyNode = copyNode->next;
    NodePtr last = head;
    
    // copy all contents of object to a new node
    while (copyNode != NULL){
      try
      {
        newNode = new Node;
      }
      catch (std::bad_alloc &)
      {
        cout << "Caught bad_alloc exception." << endl;
      }
      
      newNode->data = copyNode->data;
      last->next = newNode;
      last = last->next;
      copyNode = copyNode->next;
    }
    // set last element of list to tail
    tail = last;
  }
}
void StudentList::deleteAll()
{
  NodePtr temp = head;
  //going through linked list and deleting every node
  while (head != NULL){
    head = head->next;
    //freeing memory
    delete temp;
    temp = head;
  }

  //setting head and tail to NULL
  head = NULL;
  tail = NULL;
}

void StudentList::writeToFile(std::ostream &os) {

    if (head == NULL) {
        os << "Linked list is empty." << endl;
        return;
    }

    else {
        NodePtr temp = head;
        os << "------------------------------------------------------------" << endl;
        os << std::left << setw(6) << std::left << setw(12) << "FS" << std::left << setw(16) << "LS"
           << std::left << std::fixed << setw(10) << setprecision(2) << "CGPA" << std::left << setw(14) << "Score"
           << std::left << setw(14) << "Student ID" << endl;


        while (temp != NULL) {

            os << temp->data;
            temp = temp->next;
        }
    }
}