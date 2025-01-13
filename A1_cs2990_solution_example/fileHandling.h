#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
typedef vector<string> row;
typedef vector<row> db;

vector<string> split(string text, char delim) {
    string line;
    vector<string> vec;
    stringstream ss(text);
    while(getline(ss, line, delim)) {
        vec.push_back(line);
    }
    return vec;
}

void readFromFile(db & Data, string fileName)
{
  ifstream fin(fileName);
  string line, delim=";";
    
  if (!fin.is_open())
  {
    cout<<"I can't open file!\n";
  }
  else
  {
    while(fin)
      {
        fin>>line;
        if (!line.empty())
        {
          row r =split(line, ';');
          Data.push_back(r);
          line.clear();
          }
      }

  }
  
  fin.close();
  

}

