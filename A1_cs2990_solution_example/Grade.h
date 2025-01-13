#pragma once
#include "Course.h"

class Grade
{
private:
  Course* course;
  int grade;

public:
  Grade(Course*, int);
  int getGrade();
  void getInfo();
  
};
  