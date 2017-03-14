#ifndef STUDENTRECORDLITERATURE_H
#define STUDENTRECORDLITERATURE_H

#include "StudentRecord.h"
using namespace std;


class StudentRecordLiterature : public StudentRecord {
  
 public:

  StudentRecordLiterature();
  ~StudentRecordLiterature();

  virtual void print( ostream & out = cout ) const;

  virtual bool input( istream & in );
};

#endif
