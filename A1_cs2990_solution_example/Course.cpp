#include <iostream>
#include "Course.h"

int Course::nCourses = 0;

Course::Course(string courseName, string term)
    : name(courseName), term(term){
    nCourses++;
    courseId = nCourses;
}


void Course::getInfo()
{
  cout<<courseId<<" "<<name<<" "<<term<<" "<<endl;
}

string Course::getCourseName()
{
  return name;
}


string Course::getCourseTerm()
{
  return term;
}

int Course::getCourseId()
{
  return courseId;
}

int Course::getNCourse()
{
  return nCourses;
}

bool operator<(const Course&c1, const Course&c2)
{
  return c1.name < c2.name;  
}

