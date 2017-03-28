#ifndef STUDENTRECORDHISTORY_H
#define STUDENTRECORDHISTORY_H

#include "StudentRecord.h"
using namespace std;

class StudentRecordHistory : public StudentRecord {
  
 public:

  StudentRecordHistory(){};
  ~StudentRecordHistory() {};

  virtual void print( ostream & out = cout ) const  {
    out << lastname_ << "," << firstname_ << "," << scores_[0] << "," << scores_[1] << "," << score() << endl;
  }

  virtual bool input( istream & in )  {
   
    string line;

    getline( in, line, ',');
    lastname_ = line;

    getline( in, line, ',');
    firstname_ = line;

    getline( in, line, ',' );
    double score1 = atof( line.c_str() );

    getline( in, line );
    double score2 = atof( line.c_str() );
    
    if ( score1 > score2 ) {
      scores_.push_back( score1 ); weights_.push_back( 0.6 );
      scores_.push_back( score2 ); weights_.push_back( 0.4 );
    } else {
      scores_.push_back( score2 ); weights_.push_back( 0.6 );
      scores_.push_back( score1 ); weights_.push_back( 0.4 );
    }
    if ( line == "") 
      return false;
    else {
      compute_score();
      return true;
    }
  }
};

#endif
