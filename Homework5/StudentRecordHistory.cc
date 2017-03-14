#include "StudentRecordHistory.h"
using namespace std;

StudentRecordHistory::StudentRecordHistory(){};
StudentRecordHistory::~StudentRecordHistory() {};

void StudentRecordHistory::print( ostream & out ) const  {
  out << endl;
  out <<"History" << "," << lastname_ << "," << firstname_<< ", " << scores_[0] << ", " << scores_[1] << endl << endl; 
  out  << " total: " << score() << endl;
  out << "-------------------------------------------------------" << endl << endl;
}

bool StudentRecordHistory::input( istream & in )  {



  string line;



  getline( in, line, ',');
  lastname_ = line;

  getline( in, line, ',');
  firstname_ = line;

  getline( in, line, ',' );
  scores_.push_back( atof( line.c_str() ) );

  getline( in, line );
  scores_.push_back( atof( line.c_str() ) );
  if ( line == "")
     return false;
  else {
  compute_history_score();                     // Make sure to call compute_score in input!
  return true;
}
}
