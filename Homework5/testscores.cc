#include <iostream>
#include <fstream>
#include <vector>
#include "StudentRecord.h"
#include "StudentRecordPhysics.h"
#include "StudentRecordLiterature.h"
#include "StudentRecordHistory.h"
using namespace std;



int main(int argc, char ** argv){
  vector<StudentRecord *> records; 
   
  double PhyAvg=0.0;
  double HisAvg=0.0;
  double LitAvg=0.0;


  string line;
  ifstream in("records.txt");

//  bool valid = true;
  while( !in.eof() ) {           
      StudentRecordPhysics p1;
      StudentRecordLiterature p2;
      StudentRecordHistory p3;

      getline (in, line, ',');  
      cout << line << endl;      
      if (line == "Physics"){         
        p1.input(in);
        records.push_back(&p1);      
        p1.print();}

      else if (line == "Literature"){
        p2.input(in);
        records.push_back(&p2);
        p2.print();}

      else if (line == "History"){
        p3.input(in);
        records.push_back(&p3);
        p3.print();} 
   
}        
  
    
double totalavg = 0.;
 double litavg=0.;
  for ( vector<StudentRecord *>::const_iterator i = records.begin();i != records.end(); ++i) { 
  
 
     totalavg += (*i)->score();
  

    }
  totalavg /= records.size();
 ;
  cout << "Total GPA for this class is " << totalavg << endl;

  return 0; 
}

