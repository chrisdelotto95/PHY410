#ifndef StudentRecord_h
#define StudentRecord_h
#include <iostream>
#include <string>

class StudentRecord
{
   
public:
  StudentRecord( std::string fn, std::string ln, double sc); 
  ~StudentRecord();

  void print() const;
  

  std::string fn() const;
  std::string ln() const;
  double sc() const;
	

	 
  private:
  std::string firstname_, lastname_;
  double score_;



}
#endif
