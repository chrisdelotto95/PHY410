#ifndef STUDENTRECORDLITERATURE_H
#define STUDENTRECORDLITERATURE_H

#include "StudentRecord.h"
using namespace std;

class StudentRecordLiterature : public StudentRecord {
  
 public:

  StudentRecordLiterature(){};
  ~StudentRecordLiterature() {};

  virtual void print( ostream & out = cout ) const  {
    out << lastname_ << "," << firstname_ << "," << scores_[0] << "," << scores_[1] << "," << scores_[2] << "," << score() << endl;
  }

  virtual bool input( istream & in )  {

    string line;

    getline( in, line, ',');
    lastname_ = line;

    getline( in, line, ',');
    firstname_ = line;

    getline( in, line, ',' );
    scores_.push_back( atof( line.c_str() ) );
    weights_.push_back( 0.4 );

    getline( in, line, ',' );
    scores_.push_back( atof( line.c_str() ) );
    weights_.push_back( 0.4 );

    getline( in, line );
    scores_.push_back( atof( line.c_str() ) );
    weights_.push_back( 0.2 );
    if ( line == "") 
      return false;
    else {
      compute_score();
      return true;
    }
  }
};

#endif
