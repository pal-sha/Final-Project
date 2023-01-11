// header file international.cpp to declare InternationalStudent classes
#include "international.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// international student constructor
InternationalStudent::InternationalStudent() {
  // default : intentionally left blank
}

// setters
void InternationalStudent::setCountry(string count) { country = count; }
void InternationalStudent::setToefl(int read, int listen, int speak,
                                    int write) {
  toefl.setReading(read);
  toefl.setListening(listen);
  toefl.setSpeaking(speak);
  toefl.setWriting(write);
}

// getters
string InternationalStudent::getCountry() const { return country; }
int InternationalStudent::getToefl() const { return toefl.total(); }

// friend functions international
// country in ascending order
int compareCountry(const InternationalStudent &stu1,
                   const InternationalStudent &stu2) {
  // return 0 = less
  // return 1 = equal
  // return 2 = greater
  int StrLen1 = stu1.country.length();
  int StrLen2 = stu2.country.length();
  // case 0 : provinces are the same
  if (stu1.country == stu2.country) {
    return 1;
  }
  // all other cases : compare
  // case 1 : length of string 1 less than or equal to length of string 2
  if (StrLen1 < StrLen2 || StrLen1 == StrLen2) {
    for (int i = 0; i < StrLen1; i++) {
      // equal index
      if (stu1.country[i] == stu2.country[i]) {
        if (i == (StrLen1 - 1))
          // when reach end index
          return 1;
      }
      // index stu1 less than than index stu2 ASCII
      else if (stu1.country[i] < stu2.country[i]) {
        return 0;
      }
      // index stu1 greater than than index stu2 ASCII
      else if (stu1.country[i] > stu2.country[i]) {
        return 2;
      }
    }
  }
  // case 2 : length of string 1 greater than length of string 2
  else if (StrLen1 > StrLen2) {
    for (int i = 0; i < StrLen2; i++) {
      // equal index
      if (stu1.country[i] == stu2.country[i]) {
        if (i == (StrLen2 - 1))
          // when reach end index
          return 1;
      }
      // index stu1 less than than index stu2 ASCII
      else if (stu1.country[i] < stu2.country[i]) {
        return 0;
      }
      // index stu1 greater than than index stu2 ASCII
      else if (stu1.country[i] > stu2.country[i]) {
        return 2;
      }
    }
  }
  return 0;
}

// valid TOEFL score
int ValidToefl(InternationalStudent &student) {
  // minimum total score of 93
  if (student.toefl.total() >= 93) {
    // minimum score of 20 in all sub-categories
    if (student.toefl.getReading() >= 20 &&
        student.toefl.getListening() >= 20 &&
        student.toefl.getSpeaking() >= 20 && student.toefl.getWriting() >= 20) {
      return 1;
    } else {
      return 0;
    }
  }
  return 0;
}

// overloading << operator
ostream &operator<<(ostream &outs, InternationalStudent &student) {
  student.print(outs);
  return outs;
}

// Print function
void InternationalStudent::print(ostream &outs) {
  // output international student info based on sorting
  outs << std::left << setw(6) << std::left << setw(12) << getFirstName()
       << std::left << setw(16) << getLastName() << std::left << setw(10)
       << getCountry();
  outs << std::left << setw(12) << std::fixed << setprecision(1) << getCGPA()
       << std::left << setw(14) << getResearchScore() << std::left << setw(14)
       << getStudentID();
  outs << std::left << setw(14) << toefl.total() << "\n";
}