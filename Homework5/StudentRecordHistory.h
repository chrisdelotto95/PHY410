#ifndef STUDENTRECORDHISTORY_H
#define STUDENTRECORDHISTORY_H

#include "StudentRecord.h"
using namespace std;


class StudentRecordHistory : public StudentRecord {
  
 public:

  StudentRecordHistory();
  ~StudentRecordHistory();

  virtual void print( ostream & out = cout ) const;

  virtual bool input( istream & in );
};

#endif
