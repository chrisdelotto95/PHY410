#include "StudentRecordPhysics.h"
using namespace std;

StudentRecordPhysics::StudentRecordPhysics(){};
StudentRecordPhysics::~StudentRecordPhysics() {};

void StudentRecordPhysics::print( ostream & out  ) const  {
  out << endl ;
  out << "Physics" << "," << lastname_ << "," << firstname_ << ", " << scores_[0] << ", " << scores_[1] << endl<<endl;
  out << "total: " << score() << endl;
  out << "---------------------------------------------------" << endl << endl;
}

bool StudentRecordPhysics::input( istream & in )  {

  // First add name (last,first)

  double PScore1;
  double PScore2;

  string line;

  //getline( in, line, ',');
  //classname_ = line;

  getline( in, line, ',');
  lastname_ = line;

  getline( in, line, ',');
  firstname_ = line;

  // Now get each score. Physics has getline( in, line, ',' );
     scores_.push_back( atof( line.c_str() ) );
     getline( in, line );

     scores_.push_back( atof( line.c_str() ) );
     if ( line == "") 
     return false;
     else {      
     compute_physics_score();                     // Make sure to call compute_score in input!
     return true;
}
}
