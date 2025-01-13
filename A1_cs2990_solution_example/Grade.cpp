#include "Grade.h"
#include <iostream>
#include <string>

using namespace std;

Grade::Grade(Course *course, int grade) : grade(grade) { this->course = course; }

int Grade::getGrade() { return grade; }
void Grade::getInfo() {
  cout << course->getCourseName() << " " << grade << endl;
}