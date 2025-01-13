#include <iostream>
#include <vector>  
#include <algorithm> 

#include "Course.h"
#include "fileHandling.h"
#include "Student.h"


using namespace std;

// template <typename T>
// bool sortAZ(const T&o1, const T&o2) {
//   return o1.name<o2.name; 
// }

// template <typename T>
// bool sortZA(const T&o1, const T&o2) {
//   return o1.name>o2.name; 
// }



// bool sortAZ(const Course&c1, const Course&c2)
// {
//   return c1.name<c2.name; 
// }

// bool sortZA(const Course& c1, const Course& c2)
// {
//   return c1.courseName>c2.courseName; 
// }



int main() {
  db data;
  vector<Course> courses;
  vector<Student> students;

  //populate the courses vector
  cout<<"...loading courses\n";
  readFromFile(data,"courses.csv");
  for (auto row : data) {
    courses.push_back(Course(row[0],row[1]));
  } 

  data.clear();

  
  //populate the students 
  cout<<"...loading students\n";
  readFromFile(data, "students.csv");
  for (auto row : data) {
      students.push_back(Student(row[1],row[2], row[3]));
  } 
  data.clear();

  //populate the grades
  
  cout<<"...loading grades\n";
  int number, courseNum;
  readFromFile(data, "grades.csv");
  
  for (auto row : data) {
    for (auto &student : students)
      {
        if ((student.getLastName() == row[1])&&(student.getFirstName()== row[2]))
        {
          //student.getInfo();
          //cout<<row.size();
          courseNum=3;
          for (auto c=courses.begin(); c!=courses.end();c++)
            {
              //cout<<&(*c)<<endl;
             // cout<<row[courseNum]<<" "<<courseNum<<endl;
              if((row[courseNum]!="na")&&(courseNum<row.size()))
              {
                istringstream(row[courseNum]) >> number;
                //cout<<c->getCourseName()<<"added to student "<<student.getFirstName()<<" "<<student.getLastName()<<endl;
                student.addGrade(&(*c), number);
              }
              else{
                //cout<<c->getCourseName()<<"added to student "<<student.getFirstName()<<" "<<student.getLastName()<<endl;
                student.addGrade(&(*c), -1);//-1==na
              }
              
              courseNum++;
              //student.printGrades();
            }
          //student.printGrades();
         //cout<<"________________\n";
          
        }
      }
      //students.push_back(Student(row[1],row[2], row[3]));
  }

  for (auto student : students)
    {
      student.getInfo();
      student.printGrades();
    }
  
  

  cout<<"Requests:\n";
  
  cout<<"1. output original list of all students:\n";
  for (auto s : students) {
    s.getInfo();
  }

  cout<<"2. output list of all students sorted by name (in alphabetic order and vice versa):\n";
  vector<Student> studentView;
  for (auto s: students)
  {
      studentView.push_back(s);
  }
  
  sort(studentView.begin(), studentView.end());
  for (auto s : studentView) {
    s.getInfo();
  }
  studentView.clear();
  
  for (auto s: students)
  {
      studentView.push_back(s);
  }
    // Sort the vector in descending order
  sort(studentView.rbegin(), studentView.rend());
  for (auto s : studentView) {
    s.getInfo();
  }
  studentView.clear();

  cout<<"3. output original list of all courses\n";
  for (auto c: courses)
    {
      c.getInfo();
    }
  cout<<"4. output list of all courses for the specific semester (specified by the user)\n";
  cout<<"Term? ";
  string termData;
  cin>>termData;

  vector<Course> resCourse;

  for (auto c: courses)
  {
    if (c.getCourseTerm()==termData)
    {
      resCourse.push_back(c);
    }
  }
  for (auto c: resCourse)
  {
    cout<<c.getCourseName()<<endl;
  }
  resCourse.clear();

  cout<<"5. output list of all courses for the specific semester sorted by course name (in alphabetic order)\n";
  cout<<"Term? ";
  cin>>termData;
  for (auto c: courses)
  {
    if (c.getCourseTerm()==termData)
    {
      resCourse.push_back(c);
    }
  }
  

  sort(resCourse.begin(), resCourse.end());
  for (auto c: resCourse)
  {
    cout<<c.getCourseName()<<endl;
  }

  cout<<"...and vice versa\n";

  sort(resCourse.rbegin(), resCourse.rend());
  for (auto c: resCourse)
  {
    cout<<c.getCourseName()<<endl;
  }
  resCourse.clear();

  cout<<"8. search for course by name (successful result: full course info);\n";
  cout<<"Course name? ";
  string courseName;
  cin>>courseName;

  auto it = std::find_if(courses.begin(),courses.end(),[courseName](Course& obj){return obj.getCourseName() == courseName;});
  if (it!= courses.end())
  {
    it->getInfo();
  }
  else
  {
    cout << "No, there is no course with name "<<courseName<<endl;
  }

  cout<<"10+13.output list of all courses taken by student (user enters student last name) and grades\n";
  cout<<"Student's last name? ";
  string stName;
  cin>>stName;
  auto it1 = std::find_if(students.begin(),students.end(),[stName](Student& obj){return obj.getLastName() == stName;});
  if (it1!= students.end())
  {
    it1->getInfo();
    it1->printGrades();
  }
  else
  {
    cout << "No, there is no student with name "<<stName<<endl;
  }

  

  
  
  }

  
  
