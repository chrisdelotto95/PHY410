#include "StudentRecordPhysics.h"
#include "StudentRecordHistory.h"
#include "StudentRecordLiterature.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

float calulate_average( vector<shared_ptr<StudentRecord> > const & records ) {
  float avg = 0.0;
  if ( records.size() == 0 ) {
    cout << "this did not work silly goose" << endl;
    return avg;
  }
  for ( vector< shared_ptr<StudentRecord> >::const_iterator a = records.begin(); a != records.end(); ++a ){
      (*a)->print(cout);
      avg +=(*a)->score();
  }
  
  avg /= records.size();
  return avg; 
}

bool lessthan( shared_ptr<StudentRecord> const &left, shared_ptr<StudentRecord> const & right) { return *left < *right;}

int main(int argc, char * argv[]){

  if ( argc < 2 ) {
    cout << "filename: " << argv[0] << " filename.txt" << endl;
    return 0;
  }
  ifstream fin( argv[1] );


  vector<shared_ptr<StudentRecord> > records, physics, literature, history;
  bool valid = true;
  while( valid ) {
    string line;
    getline( fin, line, ',');
    if ( line == "" ) 
      break;

    if ( line == "Physics" ) {
      shared_ptr<StudentRecord> irecord( new StudentRecordPhysics() );
      valid = irecord->input(fin);
      if ( valid ) {
	records.push_back( irecord );
	physics.push_back( irecord );
      }
      else
	break;
    } else if ( line == "Literature" ) {
      shared_ptr<StudentRecord> irecord( new StudentRecordLiterature() );
      valid = irecord->input(fin);
      if ( valid ) {
	records.push_back( irecord );
	literature.push_back( irecord );
      }
      else
	break;
    } else if ( line == "History" ) {
      shared_ptr<StudentRecord> irecord( new StudentRecordHistory() );
      valid = irecord->input(fin);
      if ( valid ) {
	records.push_back( irecord );
	history.push_back( irecord );
      }
      else
	break;
    } else {
      cout << "this did not work" << endl;
      continue;
    }

  }


 cout <<  endl;

  sort( records.begin(), records.end(), lessthan );
  sort( physics.begin(), physics.end(), lessthan );
  sort( literature.begin(), literature.end(), lessthan );
  sort( history.begin(), history.end(), lessthan );

 cout << "i am computing..." << endl;

 for ( vector< shared_ptr<StudentRecord> >::const_iterator a = records.begin(); a != records.end(); ++a ){
     (*a)->print(cout);
 }

  cout << endl;

  cout << "Tot average : " << calulate_average( records ) << endl;
  cout << "Physics average : " << calulate_average( physics ) << endl;
  cout << "literature average : " << calulate_average( literature ) << endl;
  cout << "History average : " << calulate_average( history ) << endl;
}
