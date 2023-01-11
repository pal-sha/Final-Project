// header file domestic.cpp to declare DomesticStudent classes
#include "domestic.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// domestic student constructor
DomesticStudent::DomesticStudent() {
  // default : intentionally left blank
}

// setter
void DomesticStudent::setProvince(string prov) { this->province = prov; }

// getter
string DomesticStudent::getProvince() const { return this->province; }

// friend function domestic
// province in ascending order
int compareProvince(const DomesticStudent &stu1, const DomesticStudent &stu2) {
  // return 0 = less
  // return 1 = equal
  // return 2 = greater
  int StrLen1 = stu1.province.length();
  int StrLen2 = stu2.province.length();
  // case 0 : provinces are the same
  if (stu1.province == stu2.province) {
    return 1;
  }
  // all other cases : compare
  // case 1 : length of string 1 less than or equal to length of string 2
  if (StrLen1 < StrLen2 || StrLen1 == StrLen2) {
    for (int i = 0; i < StrLen1; i++) {
      // equal index
      if (stu1.province[i] == stu2.province[i]) {
        if (i == (StrLen1 - 1))
          // when reach end index
          return 1;
      }
      // index stu1 less than than index stu2 ASCII
      else if (stu1.province[i] < stu2.province[i]) {
        return 0;
      }
      // index stu1 greater than than index stu2 ASCII
      else if (stu1.province[i] > stu2.province[i]) {
        return 2;
      }
    }
  }
  // case 2 : length of string 1 greater than length of string 2
  else if (StrLen1 > StrLen2) {
    for (int i = 0; i < StrLen2; i++) {
      // equal index
      if (stu1.province[i] == stu2.province[i]) {
        if (i == (StrLen2 - 1))
          // when reach end index
          return 1;
      }
      // index stu1 less than than index stu2 ASCII
      else if (stu1.province[i] < stu2.province[i]) {
        return 0;
      }
      // index stu1 greater than than index stu2 ASCII
      else if (stu1.province[i] > stu2.province[i]) {
        return 2;
      }
    }
  }
  return 0;
}

// overloading << operator
ostream &operator<<(ostream &outs, DomesticStudent &student) {
  student.print(outs);
  return outs;
}

// Print function
void DomesticStudent::print(ostream &outs) {
  outs << std::left << setw(6) << std::left << setw(12) << getFirstName()
       << std::left << setw(16) << getLastName() << std::left << setw(10)
       << getProvince();
  outs << std::left << setw(12) << std::fixed << setprecision(1) << getCGPA()
       << std::left << setw(14) << getResearchScore() << std::left << setw(14)
       << getStudentID() << "\n";
}
