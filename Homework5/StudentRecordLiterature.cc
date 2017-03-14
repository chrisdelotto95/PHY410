#include "StudentRecordLiterature.h"
using namespace std;

StudentRecordLiterature::StudentRecordLiterature(){};
StudentRecordLiterature::~StudentRecordLiterature() {};

void StudentRecordLiterature::print( ostream & out ) const  {
  out << endl;
  out << "Literature"<<"," << lastname_ << "," << firstname_ << ", " << scores_[0] << ", " << scores_[1] <<  ", " << scores_[2]<< endl << endl;
  out << " total:" << score() << endl;
  out << "------------------------------------------------" << endl << endl;
}

bool StudentRecordLiterature::input( istream & in )  {

  // First add name (last,first)

  double LScore1=0.0;
  double LScore2=0.0;
  double LScore3=0.0;


  string line;

  getline( in, line, ',');
  lastname_ = line;

  getline( in, line, ',');
  firstname_ = line;

  // Now get each score. Literature has three, with weights 0.4, 0.4, 0.2

     getline( in, line, ',' );
     scores_.push_back( atof( line.c_str() ) );
     getline( in, line, ',' );
     scores_.push_back( atof( line.c_str() ) );
     getline( in, line );
     scores_.push_back( atof( line.c_str() ) );
     if ( line == "") 
     return false;
     else {
     compute_literature_score();
     return true;
     }
}
