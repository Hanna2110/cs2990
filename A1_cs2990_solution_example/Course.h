#pragma once

#include <string>

using namespace std;

class Course{

private:
  string name;
  string term;
  int courseId;

  static int nCourses;

public:
    Course(string, string);
    //~Course();

    static int getNCourse();

    void getInfo();
    string getCourseName();
    string getCourseTerm();
    int getCourseId();

    friend bool operator<(const Course&, const Course&);


    // friend bool sortAZ(const Course&, const Course&);
    // friend bool sortZA(const Course&, const Course&);
};