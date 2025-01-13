#include "Student.h"
#include <iostream>

int Student::nStudents = 0;

Student::Student(string lastName, string firstName, string phoneNumber)
    : name(lastName), firstName(firstName), phoneNumber(phoneNumber) {
  nStudents++;
  id = nStudents;
}

int Student::getNStudents() { return nStudents; }

void Student::getInfo() {
  cout << id << " " << name << " " << firstName << " " << phoneNumber << endl;
}

string Student::getLastName() { return name; }

string Student::getFirstName() { return firstName; }

string Student::getPhoneNumber() { return phoneNumber; }

int Student::getID() { return id; }

bool operator<(const Student &s1, const Student &s2) {
  return s1.name < s2.name;
}

void Student::addGrade(Course*stCourse, int stGrade) {

  stGrades.push_back(Grade(stCourse, stGrade));
}

void Student::printGrades() {
  //cout<<stGrades.size()<<endl;
  for (auto element : stGrades)
    element.getInfo();
}

// https://cplusplus.com/reference/algorithm/find_if/
// https://www.geeksforgeeks.org/find-if-in-cpp/