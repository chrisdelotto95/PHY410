#include <iostream>
#include "StudentRecord.h"
#include <vector>
#include <fstream>
using namespace std;
StudentRecord rec;
vector<StudentRecord> vec;

int main(int argc, char * argv[]) {

  ifstream in( argv[1] );

  while(rec.input(in)){
    vec.push_back(rec);
  }

  int index = atoi(argv[2]);
  if ( index > vec.size()) {
    cout << "this is to large! " << vec.size() << endl;
  } else {
  cout << "Full name: " << vec[index].first() << " " <<  vec[index].last() << "Score: " << vec[index].score()  << endl; 
  }

}
