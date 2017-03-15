#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H

#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class StudentRecord {
 public:
  StudentRecord();
  ~StudentRecord(){}

  string classname() const;
  string firstname() const;
  string lastname() const;
  double score() const;


  virtual void print (ostream & out = cout ) const = 0;

  virtual bool input ( istream & in ) = 0;

  bool operator>( StudentRecord const & right ) const;
  bool operator<( StudentRecord const & right ) const;
  bool operator>=( StudentRecord const & right ) const;
  bool operator<=( StudentRecord const & right ) const;
  void compute_physics_score(void);
  void compute_literature_score(void);
  void compute_history_score(void); 
  double score_;                       // average score
  
  void compute_score(void);
 protected:
  string classname_;              // name of class
  string firstname_;              // first name of student
  string lastname_;               // last name of student
  vector<double> scores_;         // set of scores for the student
                        // average score
  
             // protected function to compute the score

};

#endif
