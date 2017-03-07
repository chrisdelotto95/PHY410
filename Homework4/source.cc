#include "StudentRecord.h"
#include <string>
#include <iostream>




StudentRecord::StudentRecord( std::string fn, std::string ln, double sc){
  firstname_= fn; lastname_ = ln; score_=sc;
  
}

bool StudentRecord::input(std::istream & in) {
  std::string line;
  std::getline( in, line, ',');
  firstname_ = std::(line.c_str());
  std::getline( in, line, ',');
  lastname_ = std::(line.c_str());
  std::getline( in, line);
  score_ = std::(line.c_str());
  if( line == ""){
    return false;
  }
  else {
    return true;
  }
}
