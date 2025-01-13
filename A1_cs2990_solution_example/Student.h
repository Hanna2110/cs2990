#pragma once

#include <string>
#include <algorithm>    // std::find_if std::sort
#include <vector>       // std::vector
#include "Grade.h"

using namespace std;

class Student {

private:
  string name;
  string firstName;
  string phoneNumber;
  int id;

  static int nStudents;

  vector< Grade > stGrades;

public:
  Student(string, string, string);
  //~Student();

  static int getNStudents();

  void getInfo();
  string getLastName();
  string getFirstName();
  string getPhoneNumber();
  int getID();

  //std::vector<Student> students
  //std::sort(students.begin(), cars.end()); // requires an overloaded operator<

  friend bool operator< (const Student&, const Student&);

  void addGrade(Course*, int);
  void printGrades();
};