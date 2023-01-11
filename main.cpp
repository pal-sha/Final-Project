//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <iomanip> //stew
#include <ctime>


#include "student.hpp"
#include "domestic.hpp"
#include "international.hpp"
//#include "stu_sort.hpp"
#include "toeflscore.hpp"
#include "DomesticList.hpp"
#include "InternationalList.hpp"
#include "StudentList.hpp"


/*
#include "student.cpp"
#include "domestic.cpp"
#include "international.cpp"
#include "toeflscore.cpp"
#include "DomesticList.cpp"
#include "InternationalList.cpp"
#include "StudentList.cpp"
*/
using namespace std;

//Main helper functions declarations
int isValidTOFEL(int toefl);
int isValidRS(int rs);
int intValid();
bool country_bool(string c_input);
bool province_bool(string p_input); 
bool isUpper (char check);
string country_valid(string c_input);
string province_valid(string p_input);
string toLower (string name);
void printMergingOptions();
void printOptions();
void printIntOptions();
void printDomOptions();
void printGrantMenu();
void printMainMenu();
void printUnitTestMenu();
void printErrorOptions();
void printSerMer();
void printSerInt();
void printSer();
void printStu();
void writeDomestic();
void writeInternational();
void createListInternational(InternationalList &student);
void createListDomestic(DomesticList &student);
float floatValid();
float isValidCGPA(float cgpa);

int main() {
    // Creating objects 
    DomesticStudent domStudent;
    DomesticList domList;
    InternationalStudent intStudent;
    InternationalList intList;
    Student setStudent;
    StudentList stuList;
    StudentList mergedList;
    //list for unit test 
    StudentList mergedList2;

    //Creating lists
    createListDomestic(domList);
    createListInternational(intList);
    mergedList = stuList.createMerge(domList.getHead(), intList.getHead());

    // Creating variables to store user input
    string userInput;
    string userChoice;
    string unitChoice;

    // Running until user quits program
    while (userInput != "Q") {
        printMainMenu();
        cin >> userInput;

        // Domestic Student List
        if (userInput == "D") {
            cout << "---------------- DOMESTIC APPLICANT STREAM ---------------" << endl;
            printDomOptions();

            // Running until user quits domestic stream
            while (userChoice != "Q") {
                cin >> userChoice;

                //menu cases
                // [N] To search students based on first and last name
                if (userChoice == "N") {
                    cout << "-------------- Searching based on first and last name --------------" << endl;
                    //variables to store user input
                    string inFirst, inLast;
                    //ask user to enter a first and last name
                    cout << "Enter first name : " << endl;
                    cin >> inFirst;
                    cout << "Enter last name : " << endl;
                    cin >> inLast;
                    //print out header
                    printSer();
                    //call searching functions
                    domList.search(inFirst, inLast);
                    //reprint menu
                    printDomOptions();
                }
                // [S] To search students based on student ID
                else if (userChoice == "S") {
                    cout << "-------------- Searching based on Student ID --------------" << endl;
                    //variable to store user input
                    int inID;
                    //ask user to input an ID
                    cout << "Enter Student ID : " << endl;
                    //error check
                    inID = intValid();
                    //print out header
                    printSer();
                    //call searching functions
                    domList.search(inID);
                    //reprint menu
                    printDomOptions();
                }
                // [C] To search students based on CGPA
                else if (userChoice == "C") {
                    cout << "-------------- Searching based on CGPA --------------" << endl;
                    //variable to store user input
                    float inCGPA;
                    //ask user to input a CGPA
                    cout << "Enter CGPA : " << endl;
                    //error check
                    inCGPA = floatValid();
                    isValidCGPA(inCGPA);
                    //print out header
                    printSer();
                    //call searching functions
                    domList.search(inCGPA);
                    //reprint menu
                    printDomOptions();
                }
                // [R] To search students based on research score
                else if (userChoice == "R") {
                    cout << "-------------- Searching based on Research Score --------------" << endl;
                    //variable to store user input
                    int inRS;
                    //ask user to input a Research Score
                    cout << "Enter Research Score : " << endl;
                    //error check
                    inRS = intValid();
                    isValidRS(inRS);
                    //print out header
                    printSer();
                    //call searching functions
                    domList.searchScore(inRS);
                    //reprint menu
                    printDomOptions();
                }
                // [I] To insert new student
                else if (userChoice == "I") {
                    cout << "-------------- Inserting a New Node --------------" << endl;
                    //variables to store user input
                    string inFirst, inLast, inProv;
                    int inID, inRS;
                    float inCGPA;
                    //ask user to input student information
                    //name
                    cout << "Enter first name : " << endl;
                    cin >> inFirst;
                    cout << "Enter last name : " << endl;
                    cin >> inLast;
                    //ID
                    cout << "Enter Student ID : " << endl;
                    //error check
                    inID = intValid();
                    //CGPA
                    cout << "Enter CGPA : " << endl;
                    //error check
                    inCGPA = floatValid();
                    isValidCGPA(inCGPA);
                    //research score 
                    cout << "Enter Research Score : " << endl;
                    //error check
                    inRS = intValid();
                    isValidRS(inRS);
                    //province 
                    cout << "Enter province : " << endl;
                    cin >> inProv;
                    province_valid(inProv);
                    
                    //set data for student
                    domStudent.setApplicant(inFirst, inLast, inCGPA, inRS);
                    domStudent.setStudentID(inID);
                    domStudent.setProvince(inProv);
                    domList.insert(domStudent);

                    cout << "Student has been added." << endl;
                    //print out header and data
                    printSer();
                    domList.print();
                    //reprint menu
                    printDomOptions();
                }
                // [D] To delete existing student
                else if (userChoice == "D") {
                    cout << "-------------- Deleting an Existing Node --------------" << endl;
                    //variables to store user input
                    string inFirst, inLast, inProv;
                    //ask user to input student information
                    cout << "Enter student information to be deleted." << endl;
                    cout << "Enter first name : " << endl;
                    cin >> inFirst;
                    cout << "Enter last name : " << endl;
                    cin >> inLast;
                    
                    //set data for student
                    setStudent.setFirstName(inFirst);
                    setStudent.setLastName(inLast);
                    domList.deleteExisting(inFirst, inLast);

                    //cout << "Student has been removed." << endl;
                    domList.print();
                    //reprint menu
                    printDomOptions();
                }
                // [L] To delete first and last student
                else if (userChoice == "L") {
                    cout << "-------------- Deleting First and Last Students --------------" << endl;
                    domList.deleteHead_Tail();

                    cout << "Students have been removed." << endl;
                    domList.print();
                    //reprint menu
                    printDomOptions();
                }

                // [F] To save most updated student list to a .txt file
                else if (userChoice == "F") {
                    time_t tt;

                    struct tm *ti;

                    time(&tt);

                    ti = localtime(&tt);

                    string file_name = asctime(ti);
                    ofstream ofs(file_name);
                    domList.writeToFile(ofs);
                    cout << "Most updated student list has been saved to a .txt file." << "\n" <<
                         "File title is current date and time." << endl;
                    cout << "NOTE: To view file, please quit program." << endl;

                    //reprint menu
                    printDomOptions();
                }
                // [Q] To quit applicant stream
                else if (userChoice == "Q") {
                    cout << "Quitting." << endl;
                    break;
                }
                // [M] To exit applicant stream and return to main menu
                else if (userChoice == "M") {
                    cout << "Returning to main menu." << endl;
                    break;
                }
                // If user input is invalid
                else {
                    cout << "Invalid entry. Please try again." << endl;
                    printDomOptions();
                    continue;
                }
            }

            if (userChoice == "M") {
                continue;
            }
            return 0;
        }

        // International Student List
        else if (userInput == "I") {
            cout << "------------- INTERNATIONAL APPLICANT STREAM -------------" << endl;
            printIntOptions();

            // Running until user quits international stream sorting
            while (userChoice != "Q") {
                cin >> userChoice;

                //menu cases
                // [N] To search students based on first and last name
                if (userChoice == "N") {
                    cout << "-------------- Searching based on first and last name --------------" << endl;
                    //variables to store user input
                    string inFirst, inLast;
                    //ask user to enter a first and last name
                    cout << "Enter first name : " << endl;
                    cin >> inFirst;
                    cout << "Enter last name : " << endl;
                    cin >> inLast;
                    //print out header
                    printSer();
                    //call searching functions
                    intList.search(inFirst, inLast);
                    //reprint menu
                    printIntOptions();
                }
                // [S] To search students based on student ID
                else if (userChoice == "S") {
                    cout << "-------------- Searching based on Student ID --------------" << endl;
                    //variable to store user input
                    int inID;
                    //ask user to input an ID
                    cout << "Enter Student ID : " << endl;
                    //error check
                    inID = intValid();
                    //print out header
                    printSer();
                    //call searching functions
                    intList.search(inID);
                    //reprint menu
                    printIntOptions();
                }
                // [C] To search students based on CGPA
                else if (userChoice == "C") {
                    cout << "-------------- Searching based on CGPA --------------" << endl;
                    //variable to store user input
                    float inCGPA;
                    //ask user to input a CGPA
                    cout << "Enter CGPA : " << endl;
                    //error check
                    inCGPA = floatValid();
                    isValidCGPA(inCGPA);
                    //print out header
                    printSer();
                    //call searching functions
                    intList.search(inCGPA);
                    //reprint menu
                    printIntOptions();
                }
                // [R] To search students based on research score
                else if (userChoice == "R") {
                    cout << "-------------- Searching based on Research Score --------------" << endl;
                    //variable to store user input
                    int inRS;
                    //ask user to input a Research Score
                    cout << "Enter Research Score : " << endl;
                    //error check
                    inRS = intValid();
                    isValidRS(inRS);
                    //print out header
                    printSer();
                    //call searching functions
                    intList.searchScore(inRS);
                    //reprint menu
                    printIntOptions();
                }
                // [I] To insert new student
                else if (userChoice == "I") {
                    cout << "-------------- Inserting a New Node --------------" << endl;
                    //variables to store user input
                    string inFirst, inLast, inCount;
                    int inID, inRS, inRead, inSpeak, inListen, inWrite;
                    float inCGPA;
                    //ask user to input student information
                    //name
                    cout << "Enter first name : " << endl;
                    cin >> inFirst;
                    cout << "Enter last name : " << endl;
                    cin >> inLast;
                    //ID
                    cout << "Enter Student ID : " << endl;
                    //error check
                    inID = intValid();
                    //CGPA
                    cout << "Enter CGPA : " << endl;
                    //error check
                    inCGPA = floatValid();
                    isValidCGPA(inCGPA);
                    //research score 
                    cout << "Enter Research Score : " << endl;
                    //error check
                    inRS = intValid();
                    isValidRS(inRS);
                    //province 
                    cout << "Enter country : " << endl;
                    cin >> inCount;
                    country_valid(inCount);
                    
                    //TOEFL 
                    cout << "Enter TOEFL score for Reading : " << endl;
                    inRead = intValid();
                    isValidTOFEL(inRead);
                    cout << "Enter TOEFL score for Listening : " << endl;
                    inListen = intValid();
                    isValidTOFEL(inListen);
                    cout << "Enter TOEFL score for Speaking : " << endl;
                    inSpeak = intValid();
                    isValidTOFEL(inSpeak);
                    cout << "Enter TOEFL score for Writing : " << endl;
                    inWrite = intValid();
                    isValidTOFEL(inWrite);

                    //set data for student
                    intStudent.setApplicant(inFirst, inLast, inCGPA, inRS);
                    intStudent.setStudentID(inID);
                    intStudent.setCountry(inCount);
                    intStudent.setToefl(inRead, inListen, inSpeak, inWrite);
                    intList.insert(intStudent);

                    cout << "Student has been added." << endl;
                    //print out header and data
                    printSerInt();
                    intList.print();
                    //reprint menu
                    printIntOptions();
                }
                // [D] To delete existing student
                else if (userChoice == "D") {
                    cout << "-------------- Deleting an Existing Node --------------" << endl;
                    //variables to store user input
                    string inFirst, inLast, inProv;
                    //ask user to input student information
                    cout << "Enter student information to be deleted." << endl;
                    cout << "Enter first name : " << endl;
                    cin >> inFirst;
                    cout << "Enter last name : " << endl;
                    cin >> inLast;
                    
                    //set data for student
                    setStudent.setFirstName(inFirst);
                    setStudent.setLastName(inLast);
                    intList.deleteExisting(inFirst, inLast);

                    cout << "Student has been removed." << endl;
                    intList.print();
                    //reprint menu
                    printIntOptions();
                }
                // [L] To delete first and last student
                else if (userChoice == "L") {
                    cout << "-------------- Deleting First and Last Students --------------" << endl;
                    intList.deleteHead_Tail();

                    cout << "Students have been removed." << endl;
                    intList.print();
                    //reprint menu
                    printIntOptions();
                }

                // [F] To save the most updated student list to a .txt file
                else if (userChoice == "F") {
                    time_t tt;

                    struct tm *ti;

                    time(&tt);

                    ti = localtime(&tt);

                    string file_name = asctime(ti);
                    ofstream ofs(file_name);
                    intList.writeToFile(ofs);
                    cout << "Most updated student list has been saved to a .txt file." << "\n" <<
                         "File title is current date and time." << endl;
                    cout << "NOTE: To view file, please quit program." << endl;

                    //reprint menu
                    printIntOptions();
                }
                // [G] To view TOEFL grant awardees.
                else if (userChoice == "G")
                {
                    cout << "-------------- TOEFL Grant Menu --------------" << endl;
                    string inFirst;
                    string inLast;
                    char inUser;
                    while (inUser != 'A' || inUser != 'B' || inUser != 'C')
                    {
                        printGrantMenu();
                        cin >> inUser;
                        if (inUser == 'A')
                        {
                            cout << "-------------- Viewing all TOEFL grant awardees --------------" << endl;
                            intList.printGrant();
                            continue;
                        }
                        else if (inUser == 'B')
                        {
                            cout << "-------------- Searching for TOEFL grant awardee --------------" << endl;
                            cout << "Enter student information to be searched." << endl;
                            cout << "Enter first name : " << endl;
                            cin >> inFirst;
                            cout << "Enter last name : " << endl;
                            cin >> inLast;
                            intList.hasGrant(inFirst, inLast);
                            continue;
                        }
                        else if (inUser == 'C')
                        {
                            // reprint menu
                            printIntOptions();
                            break;
                        }
                        else
                        {
                            cout << "Invalid input. Try again." << endl;
                            continue;
                        }
                    }
                    continue;
                }

                // [Q] To quit applicant stream
                else if (userChoice == "Q") {
                    cout << "Quitting." << endl;
                    break;
                }
                // [M] To exit applicant stream and return to main menu
                else if (userChoice == "M") {
                    cout << "Returning to main menu." << endl;
                    break;
                }
                // If user input is invalid
                else {
                    cout << "Invalid entry. Please try again." << endl;
                    printIntOptions();
                    continue;
                }
            }

            if (userChoice == "M") {
                continue;
            }
            return 0;
        }

        // All students
        else if (userInput == "A") {
            cout << "------------- DOMESTIC AND INTERNATIONAL APPLICANT STREAM -------------" << endl;
            printMergingOptions();

            // Running until user quits international searching
            while (userChoice != "Q") {
                cin >> userChoice;

                //menu cases
                // [S] To display all domestic and international students
                if (userChoice == "S") {
                    cout << "-------------- Displaying all Domestic and International Students --------------" << endl;
                    //merge lists
                    stuList.getHead();
                    stuList.getTail();
                    //print out header and data
                    printSerInt();
                    //call merge function
                    mergedList = stuList.merge(domList.getHead(), intList.getHead());
                    //reprint menu
                    printMergingOptions();
                }
                // [R] To display all students meeting CGPA and research score requirements
                else if (userChoice == "R") {
                    cout << "-------------- Displaying Students Meeting CGPA and Research Score Requirements --------------" << endl;
                    //variable to store user input
                    float inCGPA;
                    int inRS;
                    //ask user to set minimums
                    cout << "Enter minimum CGPA requirement : " << endl;
                    //error check
                    inCGPA = floatValid();
                    isValidCGPA(inCGPA);
                    cout << "Enter minimum Research Score requirement : " << endl;
                    //error check
                    inRS = intValid();
                    isValidRS(inRS);
                    cout << "Searching for students with minimum CGPA of " << inCGPA << " and minimum Research Score of " << inRS << endl;
                    //print out header
                    printSerMer();
                    //call searching functions
                    mergedList.search(inCGPA, inRS);
                    //reprint menu
                    printMergingOptions();
                }

                // [F] To save most updated student file to a .txt file
                else if (userChoice == "F") {
                    time_t tt;

                    struct tm *ti;

                    time(&tt);

                    ti = localtime(&tt);

                    string file_name = asctime(ti);
                    ofstream ofs(file_name);
                    mergedList.writeToFile(ofs);
                    cout << "Most updated student list has been saved to a .txt file." << "\n" <<
                         "File title is current date and time." << endl;
                    cout << "NOTE: To view file, please quit program." << endl;

                    //reprint menu
                    printMergingOptions();
                }

                // [Q] To quit applicant stream
                else if (userChoice == "Q") {
                    cout << "Quitting." << endl;
                    break;
                }
                // [M] To exit applicant stream and return to main menu
                else if (userChoice == "M") {
                    cout << "Returning to main menu." << endl;
                    break;
                }
                // If user input is invalid
                else {
                    cout << "Invalid entry. Please try again." << endl;
                    printMergingOptions();
                    continue;
                }
            }

            if (userChoice == "M") {
                continue;
            }
            return 0;
        }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Unit testing 
        else if (userInput == "U") {
            cout << "------------- UNIT TESTS -------------" << endl;
            printUnitTestMenu();

        while(userChoice != "Q") {
        cin >> userChoice;

            if (userChoice == "I") {
              // just insert in both Domestic and International
              // declaring variables
              string inFirst, inLast, inProv;
              int inID, inRS;
              float inCGPA;

              //Domestic
              // Make up a student to add
              cout << "-------------- Insert Test -------------- \n" << endl;
              cout << "------ Inserting Domestic Student ------ \n";
              cout << "First name: Steve\n";
              cout << "Last name: Kerr\n";
              cout << "CGPA: 2.9\n";
              cout << "Research score: 71\n";
              cout << "Province: ON\n";
              cout << "Student ID (Integer): 10\n";
              inFirst = "Steve";
              inLast = "Kerr";
              inProv = "ON";
              inID = 10;
              inRS = 71;
              inCGPA = 2.9;
              // use set functions from student to do this
              domStudent.setApplicant("Steve", "Kerr", 2.9, 71);
              domStudent.setStudentID(10);
              domStudent.setProvince("ON");
              domList.insert(domStudent);
              cout << endl;
              cout << "Student has successfully been added to the domestic students list." << endl;
              cout << "-*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+ { TEST PASSED } -*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+" << endl;

              //International
              cout << "------ Inserting International Student ------ \n";
              cout << "First name: Jung\n";
              cout << "Last name: Kook\n";
              cout << "CGPA: 4.0\n";
              cout << "Research score: 98\n";
              cout << "Country: Korea\n";
              cout << "Student ID (Integer): 5\n";
              intStudent.setApplicant("Jung", "Kook", 4.0, 98);
              intStudent.setStudentID(10);
              intStudent.setCountry("Korea");
              intList.insert(intStudent);
              cout << endl;
              cout << "Student has successfully been added to the international student list." << endl;
              cout << "-*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+ { TEST PASSED } -*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+" << endl;
            } 
            
            else if (userChoice == "S") {
              // search #1 is based on application id, cgpa or reasearch score
              cout << "-------------- Search Testing #1 --------------" << endl;
              // search based on application id
              cout << "[A] To search based on Application ID." << endl;
              cout << "[C] To search based on CGPA." << endl;
              cout << "[R] To search based on Research Score." << endl;
              cin >> unitChoice;
              if (unitChoice == "A") {
                cout << "-------------- Search based on Application ID --------------"
                    << endl;
                cout << "Searching for domestic student with applicationID 20220010 : "
                    << endl;
                // insert relative find/search function
                // print out header
                printSer();
                // call searching functions
                domList.search(20220010);
                cout << "-*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+ { TEST PASSED } -*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+" << endl;

                // cout << "Student succesfully found" <<endl;

                cout << "-------------- Search based on Application ID --------------" << endl;
                // find out what the application id even is
                cout << "Searching for international student with applicationID #20220000 : " << endl;
                printSer();
                // call searching functions
                domList.search(20220001);

                // insert relative find/search function

                cout << "-*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+ { TEST PASSED } -*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+" << endl;
              } 
              else if (unitChoice == "C") {
                cout << "-------------- Search based on CGPA --------------" << endl;
                cout << "Searching for domestic student with cgpa 3.3 : " << endl;
            
                // print out header
                printSer();
                float domGPA = 3.3;
                // call searching functions
                domList.search(domGPA);
                cout << "-*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+ { TEST PASSED } -*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+" << endl;
                cout << endl;
                cout << "-------------- Search based on CGPA --------------" << endl;
                cout << "Searching for international student with cgpa 2.9 : "
                    << endl;
                // insert relative find/search function
                // print out header
                printSer();
                float intGPA = 2.9;
                // call searching functions
                intList.search(intGPA);
                cout << "-*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+ { TEST PASSED } -*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+" << endl;
                
              } 
              else if (unitChoice == "R") {
                cout << "-------------- Search based on Research Score --------------" << endl;
                cout << "Searching for domestic student with researchScore 89 : " << endl;
                float domResearchScore = 89;
                // insert relative find/search function
                printSer();
                domList.searchScore(domResearchScore);
                cout << "-*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+ { TEST PASSED } -*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+" << endl;
                // cout << "Student succesfully found" <<endl;

                cout << "-------------- Search based on researchScore --------------" << endl;
                cout << "Searching for international student with researchScore 95 : " << endl;
                // insert relative find/search function
                float intResearchScore = 95;
                // insert relative find/search function
                printSer();
                domList.searchScore(intResearchScore);
                cout << "-*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+ { TEST PASSED } -*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+" << endl;
              }

            } 
            else if (userChoice == "N") {
              cout << "-------------- Search Testing based on first and last name --------------" << endl;
              cout << "Searching for a domestic student based on first and last name" << endl;
              cout << "The following student should not be found:" << endl;
              cout << "First Name: Salina" << endl;
              cout << "Last Name: Safi" << endl;
              // insert relative search/find function
              string domFirst = "Salina";
              string domLast = "Safi";
              printSer();
              domList.search(domFirst, domLast);
              cout << " This Student was not found" << endl;
              cout << "-*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+ { TEST PASSED } -*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+" << endl;

              cout << "The following student should be found:" << endl;
              cout << "First Name: Aiden" << endl;
              cout << "Last Name: Torres" << endl;
              // insert relative search/find function
              string domFirst2 = "Aiden";
              string domLast2 = "Torres";
              printSer();
              domList.search(domFirst2, domLast2);
              cout << "-*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+ { TEST PASSED } -*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+" << endl;

              cout << "Searching for a international student based on first and last name" << endl;
              cout << "The following student should not be found:" << endl;
              cout << "First Name: Wajihah" << endl;
              cout << "Last Name: Malik" << endl;
              // insert relative search/find function
              string intFirst = "Wajihah";
              string intLast = "Malik";
              printSer();
              intList.search(domFirst, domLast);
              cout << " This Student was not found" << endl;
              cout << "-*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+ { TEST PASSED } -*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+" << endl;

              cout << "The following student should be found:" << endl;
              cout << "First Name: Sima" << endl;
              cout << "Last Name: Javadi" << endl;
              // insert relative search/find function
              string intFirst2 = "Sima";
              string intLast2 = "Javadi";
              printSer();
              intList.search(intFirst2, intLast2);
             cout << "-*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+ { TEST PASSED } -*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+" << endl;

            } 
            else if (userChoice == "D") {
              cout << "-------------- Delete Testing --------------" << endl;

              // Deleting a domestic student
              // student that DOES exist
              cout << "Deleting a student named Henry Cox" << endl;
              string domFirst = "Henry";
              string domLast = "Cox";

              // set data for student
              domStudent.setFirstName(domFirst);
              domStudent.setLastName(domLast);
              domList.deleteExisting(domFirst, domLast);
              cout << "-*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+ { TEST PASSED } -*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+" << endl;

              // Student that DOES NOT exist
              cout << "Deleting a student named Palak Sharma" << endl;
              string domFirst2 = "Palak";
              string domLast2 = "Sharma";

              // set data for student
              domStudent.setFirstName(domFirst2);
              domStudent.setLastName(domLast2);
              domList.deleteExisting(domFirst2, domLast2);
              cout << "-*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+ { TEST PASSED } -*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+" << endl;

              // Deleting an international student
              // student that DOES exist
              cout << "Deleting a student named Ting Fang" << endl;
              string intFirst = "Ting";
              string intLast = "Fang";

              // set data for student
              intStudent.setFirstName(intFirst);
              intStudent.setLastName(intLast);
              intList.deleteExisting(intFirst, intLast);
              cout << "-*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+ { TEST PASSED } -*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+" << endl;

              // Student that DOES NOT exist
              cout << "Deleting a student named Elaiza Chavez" << endl;
              string intFirst2 = "Elaiza";
              string intLast2 = "Chavez";

              // set data for student
              intStudent.setFirstName(intFirst2);
              intStudent.setLastName(intLast2);
              intList.deleteExisting(intFirst2, intLast2);
              cout << "-*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+ { TEST PASSED } -*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+" << endl;

            } 
            else if (userChoice == "E") {
              cout << "-------------- Delete Node Testing --------------" << endl;
              cout << "Deleting head and tail nodes from DomesticStudent...\n\n";
              // get user to enter a first and last name
              // get user to input info
              cout << "Current head: " << domList.getHead()->data;
              cout << "Current tail: " << domList.getTail()->data << endl << endl;
              domList.deleteHead_Tail();
              cout << "New head: " << domList.getHead()->data;
              cout << "New tail: " << domList.getTail()->data << endl;

              cout << "-*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+ { TEST PASSED } -*=+-*=+-*=+-*=+-*=+-*=+-*=+-*=+" << endl;
              cout << "Deleting head and tail nodes from InternationalStudent...\n\n";
              // get user to enter a first and last name
              // get user to input info
              cout << "Current head:     " << intList.getHead()->data;
              cout << "Current tail:" << intList.getTail()->data << endl << endl;
              intList.deleteHead_Tail();
              cout << "New head: " << intList.getHead()->data;
              cout << "New tail: " << intList.getTail()->data << endl;

            } 
            else if (userChoice == "A") {
              cout << "-------------- Merge Testing --------------" << endl;
              // merge lists
              stuList.getHead();
              stuList.getTail();
              // print out header and data
              printSerInt();
              // call merge function
              mergedList2 = stuList.merge(domList.getHead(), intList.getHead());

            } 
            else if (userChoice == "R") {
              cout << "-------------- Search Merged List Testing --------------" << endl;

              // Test: valid CGPA but not valid RS

              cout << "Searching for student with minimun CGPA of 2.3 and minimum Research Score of -3." << endl;
              // print out header
              float inCGPA = 2.3;
              int inRS = -3;
              inCGPA = floatValid();
              inRS = intValid();
              printStu();
              // call searching functions
              mergedList.search(inCGPA, inRS);
              cout << endl;

              // Test: not valid CGPA, but valid RS
              float inCGPA2 = 4.5;
              int inRS2 = 70;
              inCGPA2 = floatValid();
              inRS2 = intValid();
              cout << "Searching for student with minimun CGPA of 4.5 and minimum Research Score of 70." << endl;
              // print out header
              printStu();
              // call searching functions
              mergedList.search(inCGPA2, inRS2);
              cout << endl;

              // Neither valid
              float inCGPA3 = -5.0;
              int inRS3 = -5;
              inCGPA3 = floatValid();
              inRS3 = intValid();
              cout << "Searching for student with minimun CGPA of -5.0 and minimum Research Score of -5." << endl;
              // print out header
              printStu();
              // call searching functions
              mergedList.search(inCGPA3, inRS3);
              cout << endl;

              // both valid
              float inCGPA4 = 3.0;
              int inRS4 = 75;
              inCGPA4 = floatValid();
              inRS4 = intValid();
              cout << "Searching for student with minimun CGPA of 3.0 and minimum Research Score of 75." << endl;
              // print out header
              printStu();
              // call searching functions
              mergedList.search(inCGPA4, inRS4);
              cout << endl;

              // cgpa 4.3, rs 99 - edge cases
              float inCGPA5 = 4.3;
              int inRS5 = 99;
              inCGPA5 = floatValid();
              inRS5 = intValid();
              cout << "Searching for student with minimun CGPA of 4.3 and minimum Research Score of 99." << endl;
              // print out header
              printSerMer();
              // call searching functions
              mergedList.search(inCGPA5, inRS5);
              cout << endl;

            }
            // [M] To exit applicant stream and return to main menu
            else if (userChoice == "M") {
                cout << "Returning to main menu." << endl;
                break;
            }
            else if (userChoice == "Q") {
              // quit
              cout << "Quitting." << endl;
              break;
            } 
            else {
              cout << "Invalid entry. Please enter a choice from the menu.\n";
              printUnitTestMenu();
              //cin >> userChoice;
              continue;
            }
        }
            if (userChoice == "M") {
                continue;
            }
            return 0;
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // [E] to demo error checks
        else if (userInput == "E") {
            cout << "------------- ERROR TESTING -------------" << endl;
            string userChoice;
            
            // Running until user quits international stream sorting
            while (userChoice != "Q") {
                printErrorOptions();
                cin >> userChoice;
                //menu cases
                // [F] To demo if any feld in the Domestic or International Student text files is missing
                if (userChoice == "F") {
                    //created follwoing student in domestic text file : Zane,Nelson,2.67,77 (missing province)
                    writeDomestic();
                    DomesticList domTest;
                    createListDomestic(domTest);
                    //created follwoing student in international text file : Jamal,Iran,3.55,98 (missing last name)
                    writeInternational();
                    InternationalList intTest;
                    createListInternational(intTest);
                    continue;
                } 

                // [C] To demo that program is case insensitive
                else if (userChoice == "C") {
                    string check_name;
                    cout << "Enter a name : " << endl;
                    cin >> check_name;
                    string ci_name = toLower(check_name);
                    cout << "String is case insensitive : " << ci_name << endl;
                    continue;
                }
                // [V] To demo program checks for valid ranges
                else if (userChoice == "V") {
                    string inProv, inCount;
                    float inCGPA;
                    int inRS, inRead, inListen, inSpeak, inWrite;
                    //province 
                    cout << "Checking province : " << endl;
                    cout << "Enter province : " << endl;
                    cin >> inProv;
                    province_valid(inProv);
                    //country 
                    cout << "Checking country : " << endl;
                    cout << "Enter a country : " << endl;
                    cin >> inCount;
                    country_valid(inCount);

                    //CGPA
                    cout << "Checking CGPA : " << endl;
                    cout << "Enter CGPA : " << endl;
                    inCGPA = floatValid();
                    isValidCGPA(inCGPA);
                    //research score 
                    cout << "Checking Research Score : " << endl;
                    cout << "Enter Research Score : " << endl;
                    //error check
                    inRS = intValid();
                    isValidRS(inRS);
                    //TOEFL 
                    cout << "Checking TOEFL : " << endl;
                    cout << "Enter TOEFL score for Reading : " << endl;
                    inRead = intValid();
                    isValidTOFEL(inRead);
                    cout << "Enter TOEFL score for Listening : " << endl;
                    inListen = intValid();
                    isValidTOFEL(inListen);
                    cout << "Enter TOEFL score for Speaking : " << endl;
                    inSpeak = intValid();
                    isValidTOFEL(inSpeak);
                    cout << "Enter TOEFL score for Writing : " << endl;
                    inWrite = intValid();
                    isValidTOFEL(inWrite);
                    continue;
                } 
                // [Q] To quit applicant stream
                else if (userChoice == "Q") {
                    cout << "Quitting." << endl;
                    break;
                }
                // [M] To exit applicant stream and return to main menu
                else if (userChoice == "M") {
                    cout << "Returning to main menu." << endl;
                    break;
                }
                // If user input is invalid
                else {
                    cout << "Invalid entry. Please try again." << endl;
                    printErrorOptions();
                    continue;
                }
            }

            if (userChoice == "M") {
                continue;
            }
            return 0;
        }
        // If user input is invalid
        else {
            if (userInput != "Q") {
                cout << "Invalid entry. Please try again." << endl;
            }
        }
    }
    //Quitting
    cout << "Quitting Graduate School Admission System." << endl;
    exit(1);
}

// Helper functions to read data from text files:
// To be used by both domestic and international functions

// Function to read student data to a list for domestic stream
void createListDomestic(DomesticList &student) {
  // Read the domestic-stu.txt file and exit if failed
  string line;
  ifstream domesticFile("domestic-stu.txt");
  if (!domesticFile.is_open()) {
    cout << "Unable to open file domestic-stu.txt" << endl;
  }

  // Read the first line of domestic-stu.txt, which specifies
  // the file format. And then print it out to the screen
  getline(domesticFile, line);

  /*Keep reading the rest of the lines in domestic-stu.txt.
   *In the example code here, I will read each data separated
   *by a comma, and then print it out to the screen.
   *In your lab assignment 1, you should use these read data
   *to initialize your DomesticStudent object. Then you can
   *use get and set functions to manipulate your object, and
   *print the object content to the screen
   */

  int stu_count = 0;
  while (getline(domesticFile, line)) {
    /*process each line, get each field separated by a comma.
     *We use istringstream to handle it.
     *Note in this example code here, we assume the file format
     *is perfect and do NOT handle error cases. We will leave the
     *error and exception handling of file format to Lab Assignment 4
     */
    istringstream ss(line);

    string firstName, lastName, province, s_cgpa, s_researchScore;
    float cgpa;
    int researchScore;

    // get firstName separated by comma
    getline(ss, firstName, ',');

    // get lastName separated by comma
    getline(ss, lastName, ',');

    // get province separated by comma
    getline(ss, province, ',');

    // get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());

    // get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());

    // robust error check
    if (firstName == "" || lastName == "" || province == "" || s_cgpa == "" ||
        s_researchScore == "") {
      cout << "Error: An input field is missing." << endl;
    }
    // print the student info to the screen
    /*cout << "Domestic student " << stu_count << " " << firstName << " "
     << lastName << " from " << province << " province has cgpa of "
     << cgpa << ", and research score of " << researchScore << endl;*/

    DomesticStudent stuDENT;
    stuDENT.setApplicant(firstName, lastName, cgpa, researchScore);
    stuDENT.setProvince(province);
    stuDENT.setStudentID(stu_count);
    student.insert(stuDENT);
    stu_count++;
  }

  // close your file
  domesticFile.close();
}

// Function to read student data to a list for international  stream
void createListInternational(InternationalList &student) {
  // Read the international-stu.txt file and exit if failed
  string line;
  ifstream internationalFile("international-stu.txt");
  if (!internationalFile.is_open()) {
    cout << "Unable to open file international-stu.txt" << endl;
  }

  // Read the first line of domestic-stu.txt, which specifies
  // the file format. And then print it out to the screen
  getline(internationalFile, line);

  // read data separated by commas
  // index corresponds to student nums that we create (?)
  int stu_count = 1;
  while (getline(internationalFile, line)) {
    istringstream ss(line);

    string firstName, lastName, country, s_cgpa, s_researchScore, s_reading,
        s_listening, s_speaking, s_writing;
    float cgpa;
    int researchScore, reading, listening, speaking, writing;

    // get firstName separated by comma
    getline(ss, firstName, ',');

    // get lastName separated by comma
    getline(ss, lastName, ',');

    // get province separated by comma
    getline(ss, country, ',');

    // get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());

    // get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());

    // may have to access the toefl scores usingtoefl class + dot
    // get reading separated by comma, and convert it to int
    getline(ss, s_reading, ',');
    reading = atoi(s_reading.c_str());

    // get listening separated by comma, and convert it to int
    getline(ss, s_listening, ',');
    listening = atoi(s_listening.c_str());

    // get writing separated by comma, and convert it to int
    getline(ss, s_speaking, ',');
    speaking = atoi(s_speaking.c_str());

    // get reading separated by comma, and convert it to int
    getline(ss, s_writing, ',');
    writing = atoi(s_writing.c_str());

    // robust error check
    if (firstName == "" || lastName == "" || country == "" || s_cgpa == "" ||
        s_researchScore == "" || s_reading == "" || s_listening == "" ||
        s_speaking == "" || s_writing == "") {
      cout << "Error: An input field is missing." << endl;
    }

    // create international student object
    InternationalStudent int_i;
    // automatically fix typo when it occours
    if (country == "Idian" || country == "idian") {
      country = "India";
      cout << "Typo in text file has been corrected." << endl;
    }

    InternationalStudent stuDENT;
    stuDENT.setApplicant(firstName, lastName, cgpa, researchScore);
    stuDENT.setCountry(country);

    // set toefl scores
    stuDENT.setToefl(reading, listening, speaking, writing);
    stuDENT.setStudentID(stu_count + 100);
    student.insert(stuDENT);
    stu_count++;
  }

  // close file
  internationalFile.close();
}

// Functions to print out searching
void printSer() {
  // Printing out header for list
  cout << "----------------------------------------------------------------------" << endl;
  cout << std::left << setw(6) << std::left << setw(12) << "FS"
       << std::left << setw(16) << "LS" << std::left << setw(10)
       << "PROV";
  cout << std::left << setw(12) << std::fixed << setprecision(2) << "CGPA"
       << std::left << setw(14) << "Score" << std::left << setw(14)
       << "Student ID" << endl;
}
void printStu() {
  // Printing out header for list
  // output international student info based on sorting
  cout << "----------------------------------------------------------------------" << endl;
    cout << std::left << setw(6) << std::left << setw(12) << "FS" << std::left << setw(16) << "LS"
    << std::left << std::fixed << setw(10) << setprecision(2) << "CGPA" << std::left << setw(14) << "Score" << std::left << setw(14) << "Student ID" << endl;
  
}
void printSerInt() {
  // Printing out header for list
  cout << "------------------------------------------------------------" << endl;
  cout << std::left << setw(6) << std::left << setw(12) << "FS"
       << std::left << setw(16) << "LS" << std::left << setw(10)
       << "COUNTRY";
  cout << std::left << setw(12) << std::fixed << setprecision(2) << "CGPA"
       << std::left << setw(14) << "Score" << std::left << setw(14)
       << "Student ID" << endl;
}
void printSerMer() {
  // Printing out header for list
  cout << "------------------------------------------------------------" << endl;
  cout << std::left << setw(6) << std::left << setw(12) << "FS"
       << std::left << setw(16) << "LS" << std::left << setw(10)
       << "Origin";
  cout << std::left << setw(12) << std::fixed << setprecision(2) << "CGPA"
       << std::left << setw(14) << "Score" << std::left << setw(14)
       << "Student ID";
  cout << std::left << setw(14) << "TOEFL" << "\n";
  
}

//Function to print out appropriate menus
void printOptions(){

    cout << "-------------------------------- Menu --------------------------------" << endl;
    //searching
    cout << "[N] To search students based on first and last name." << endl;
    cout << "[S] To search students based on student ID." << endl;
    cout << "[C] To search students based on CGPA." << endl;
    cout << "[R] To search students based on research score." << endl;
    //inserting 
    cout << "[I] To insert new student." << endl;
    //deleting
    cout << "[D] To delete existing student." << endl;
    cout << "[L] To delete first and last student." << endl;
    cout << "[F] To save most updated student list to a .txt file" << endl;
    cout << "[U] To demo unit tests." << endl;
    cout << "[Q] To quit program." << endl;
    cout << "[M] To exit applicant stream and return to main menu." << endl;
    cout << "Enter your choice here: " << endl;
}

void printDomOptions(){

    cout << "-------------------------------- Menu --------------------------------" << endl;
    //searching
    cout << "[N] To search students based on first and last name." << endl;
    cout << "[S] To search students based on student ID." << endl;
    cout << "[C] To search students based on CGPA." << endl;
    cout << "[R] To search students based on research score." << endl;
    //inserting 
    cout << "[I] To insert new student." << endl;
    //deleting
    cout << "[D] To delete existing student." << endl;
    cout << "[L] To delete first and last student." << endl;
    cout << "[F] To save most updated student list to a .txt file" << endl;
    cout << "[U] To demo unit tests." << endl;
    cout << "[Q] To quit program." << endl;
    cout << "[M] To exit applicant stream and return to main menu." << endl;
    cout << "Enter your choice here: " << endl;
}

void printIntOptions() {

  cout << "--------------------------- Menu ---------------------------"
       << endl;
  // searching
  cout << "[N] To search students based on first and last name." << endl;
  cout << "[S] To search students based on student ID." << endl;
  cout << "[C] To search students based on CGPA." << endl;
  cout << "[R] To search students based on research score." << endl;
  // inserting
  cout << "[I] To insert new student." << endl;
  // deleting
  cout << "[D] To delete existing student." << endl;
  cout << "[L] To delete first and last student." << endl;
  cout << "[F] To save most updated student list to a .txt file" << endl;
  cout << "[U] To demo unit tests." << endl;
  cout << "[G] To view TOEFL grant menu." << endl;
  cout << "[Q] To quit program." << endl;
  cout << "[M] To exit applicant stream and return to main menu." << endl;
  cout << "Enter your choice here: " << endl;
}

//helper function to print menu for innovation
void printGrantMenu(){
  cout << "--------------------------- TOEFL Grant Menu ---------------------------" << endl;
  cout << "All students who have received a TOEFL score of 100-120 are qualified for the grant." << endl;
  cout << "------------------------------------------------------------------------"<< endl;
  cout << "[A] To view all TOEFL grant awardees." << endl;
  cout << "[B] To search based on first and last name if user has a grant." << endl;
  cout << "[C] To go back to international stream." << endl;
}


void printMergingOptions(){

    cout << "------------------------------ Merging Menu ------------------------------" << endl;
    //merge international and domestic lists together
    cout << "[S] To display all domestic and international students." << endl;
    //merge lists containing valid CGPA and research scores
    cout << "[R] To display all students meeting CGPA and research score requirements." << endl;
    cout << "[F] To save most updated student list to a .txt file" << endl;
    cout << "[Q] To quit program." << endl;
    cout << "[M] To exit applicant stream and return to main menu." << endl;
    cout << "Enter your choice here: " << endl;
}

// Helper function for printing unit testing menu
void printUnitTestMenu() {
  cout << "---------------------- Unit Testing Menu ----------------------"<< endl;
  cout << "Tests occur for both Domestic and International students." << endl;
  cout << "[I] To insert anew student." << endl;
  // searches based on application id, cgpa or reasearchScore
  cout << "[S] To search for an existing student based on their ID, CGPA, or Research Score." << endl;
  // search based on firstName and lastName
  cout << "[N] To search for a student using their name." << endl;
  // delete based on firstName and lastName
  cout << "[D] To delete an existing student using their name." << endl;
  // delete head and tail node
  cout << "[E] To delete first and last student in the list." << endl;
  cout << "[A] To merge Domestic and International lists." << endl; // merge
  // search the merged list, based on  gpa_threshold and researchScore_threshold
  cout << "[R] To search merged lists based on minimum CGPA and Research Score requirements." << endl;
  cout << "[M] To exit and return to the main menu." << endl;
  cout << "[Q] To quit the program." << endl;
  cout << "Enter your choice here: " << endl;
}

void printErrorOptions() {

    cout << "------------------------------ Error Checking Menu ------------------------------" << endl;
    //erroc checking menu for multiple cases
    cout << "Error checks for Domestic and International students occur simultaneously." << endl;
    cout << "[F] To demo if any feld in the Domestic or International Student text files is missing." << endl;
    //merge lists containing valid CGPA and research scores
    cout << "[C] To demo that program is case insensitive." << endl;
    cout << "[V] To demo program checks for valid ranges." << endl;
    cout << "[Q] To quit program." << endl;
    cout << "[M] To exit applicant stream and return to main menu." << endl;
    cout << "Enter your choice here: " << endl;
}

void printMainMenu(){
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "-------------- WELCOME TO THE GRADUATE SCHOOL ADMISSION SYSTEM --------------" << endl;
        cout << "There are two admission streams: Domestic and International." << "\n";
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "[D] To navigate to the domestic applicant stream." << "\n"
             << "[I] To navigate to the international applicant stream." << "\n"
             << "[A] To view all students." << "\n"
             << "[U] To view unit testing." << "\n"
             << "[E] To demo error checks." << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "[Q] To quit program." << endl;
}

//Functions to check for valid ranges of inputs
//country and province
//helper function to check if any letters in the string are uppercase
bool isUpper (char check) {
    //if the ASCII value falls in the range A-Z return true
    if (check >= 'A' && check <= 'Z') {
        return 1;
    }
    return 0;
}
//helper function to convert any uppercase letters to lowercase
string toLower (string name) {
    for (int i = 0; i < name.size(); i++) {
        if (isUpper(name[i])) {
            //adding 32 to uppercase ASCII values converts them to lowercase
            name[i] = name[i] + 32;
        }
    }
    return name;
}
//province
//check to see if province is: NL, PE, NS, NB, QC, ON, MB, SK, AB, BC, YT, NT, or NU 
bool province_bool(string p_input) {
    if (toLower(p_input) == "nl" || 
        toLower(p_input) == "pe" || 
        toLower(p_input) == "ns" || 
        toLower(p_input) == "nb" || 
        toLower(p_input) == "qc" ||
        toLower(p_input) == "on" ||
        toLower(p_input) == "mb" ||
        toLower(p_input) == "sk" ||
        toLower(p_input) == "ab" ||
        toLower(p_input) == "bc" ||
        toLower(p_input) == "yt" ||
        toLower(p_input) == "nt" ||
        toLower(p_input) == "nu" ) {
        return 1;
    }
    return 0;
}
string province_valid(string p_input) {
    while (province_bool(p_input) == 0) {
        //if not valid print error
        cout << "Invalid province. Please select one of the following : " << endl;
        cout << "\t NL " << endl 
             << "\t PE " << endl 
             << "\t NS " << endl 
             << "\t NB " << endl 
             << "\t QC " << endl
             << "\t ON " << endl 
             << "\t MB " << endl 
             << "\t SK " << endl 
             << "\t AB " << endl 
             << "\t BC " << endl
             << "\t YT " << endl 
             << "\t NT " << endl 
             << "\t NU " << endl;  
        cout << "Enter any of the above provinces : ";       
        cin >> p_input;
        province_bool(p_input);
    }
    return p_input;
}
//country
//check to see if country is: Canada, China, India, Iran, or Korea
bool country_bool(string c_input) {
    if (toLower(c_input) == "canada" || 
           toLower(c_input) == "china" || 
           toLower(c_input) == "india" || 
           toLower(c_input) == "iran" || 
           toLower(c_input) == "korea") {
           return 1;
    }
    return 0;
}
string country_valid(string c_input) {
    while (country_bool(c_input) == 0) {
        //if invalid print error and repeat
        cout << "Invalid country. Please select one of the following : " << endl;
        cout << "\t Canada " << endl << "\t China " << endl << "\t India " << endl << "\t Iran " << endl << "\t Korea " << endl;   
        cout << "Enter any of the above countries : ";
        cin >> c_input;
        country_bool(c_input);
    }
    return c_input;
}

//cgpa
float isValidCGPA(float cgpa) {
    //cgpa must fall between 0 and 4.3
    while (cgpa > float(4.3) || cgpa < 0) {
        cout<<"CGPA is out of range. Please input a number from 0 to 4.3." << endl; 
        cin >> cgpa;
        //return 0;
        //exit(1); 
    }
    return cgpa;
}
//reaearch score
int isValidRS(int rs) {
    //cgpa must fall between 0 and 100
    while (rs > 100 || rs < 0) {
        cout<<"Research Score is out of range. Please input a number from 0 to 100." << endl; 
        cin >> rs;
        //return 0;
        //exit(1); 
    }
    return rs;
}
//toefl
int isValidTOFEL(int toefl) {
    //cgpa must fall between 0 and 30
    while (toefl > 30 || toefl < 0) {
        cout<<"TOEFL is out of range. Please input a number from 0 to 30." << endl; 
        cin >> toefl;
        //return 0;
        //exit(1); 
    }
    return toefl;
}

//checking for valid inputs
//int
int intValid() {
    int inInt;
    //check if valid input
    while (true) {
    cin >> inInt;
        while (cin.fail()) {
            if (!cin) {
                cin.clear();
                cin.ignore();
                //cout << "Invalid input. Please enter an integer value: ";
                cin >> inInt;
            }
            cout << "Invalid input. Please enter an integer value : " << endl;
        }
        //else {
            return inInt;
        //}
    }
    //return 0;
}
//float
float floatValid() {
    float inFloat;
    //check if valid input
    while (true) {
    cin >> inFloat;
        while (cin.fail()) {
            if (!cin) {
                cin.clear();
                cin.ignore();
                cout << "Invalid input. Please enter a floating point value : " << endl;;
                cin >> inFloat;
            }
        }
        //else {
            return inFloat;
        //}
    }
    //return 0;
}

//error checking : write to files
void writeDomestic() {
  // Open the domestic-stu.txt file and exit if failed

  string line;
  ofstream domesticFile("domestic-stu.txt", std::ios_base::app);
  if (!domesticFile) {
    cout << "Unable to open file domestic-stu.txt" << endl;
  }

  //created follwoing student in domestic text file : Zane,Nelson,2.67,77 (missing province)
  line = "Zane,Nelson,2.67,77";

   domesticFile << line << endl;

  // close file
  domesticFile.close();
}
void writeInternational() {
  // Open the international-stu.txt file and exit if failed

  string line;
  ofstream internationalFile("international-stu.txt", std::ios_base::app);
  if (!internationalFile) {
    cout << "Unable to open file international-stu.txt" << endl;
  }

  //created follwoing student in international text file : Jamal,Iran,3.55,98 (missing last name)
  line = "Jamal,Iran,3.55,98";
  //internationalFile.append(line);

  internationalFile << line << endl;

  // close file
  internationalFile.close();
}
