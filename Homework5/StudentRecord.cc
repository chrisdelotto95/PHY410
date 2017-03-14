#include "StudentRecord.h"
#include <float.h>
using namespace std;

StudentRecord::StudentRecord(){}

string StudentRecord::classname() const { return classname_; }
string StudentRecord::firstname() const { return firstname_; }
string StudentRecord::lastname() const { return lastname_; }
double StudentRecord::score() const { return score_; }


bool StudentRecord::operator>( StudentRecord const & right ) const {
  return this->score() > right.score();
};

bool StudentRecord::operator>=( StudentRecord const & right ) const {
  return this->score() >= right.score();
};

bool StudentRecord::operator<( StudentRecord const & right ) const {
  return this->score() < right.score();
};

bool StudentRecord::operator<=( StudentRecord const & right ) const {
  return this->score() <= right.score();
};

void StudentRecord::compute_score(void) {

  if ( scores_.size() == 0 ) {
    return ; 
  }

  score_ = 0.0;
  for ( unsigned int i = 0; i < scores_.size(); ++i ) {
    double iscore = scores_[i];
    score_ += iscore;
  }
  score_ /= scores_.size(); 
  
}

void StudentRecord::compute_physics_score(void) {

  if ( scores_.size() == 0 ) {
    return ;
  }
 double  PScore1,PScore2,Ptotal;
  
  score_ = 0.0;
  for ( unsigned int i = 0; i < scores_.size(); ++i ) {
    if (i == 0){
    PScore1 = 0.8*scores_[i];}          
    else if (i == 1) {
   PScore2 = 0.2*scores_[i];}
}
  
   Ptotal = (PScore1 + PScore2);
  
  score_ = Ptotal;

}


void StudentRecord::compute_literature_score(void) {

  if ( scores_.size() == 0 ) {
    return ;
  }
  
  double LScore1, LScore2, LScore3,Ltotal;
  score_ = 0.0;
  for ( unsigned int i = 0; i < scores_.size(); ++i ) {
    if (i == 0){
    LScore1 = 0.4*scores_[i];}
    else if (i == 1) {
    LScore2 = 0.4*scores_[i];}
    else if (i == 2) {
    LScore3 = 0.2*scores_[i];}
}
  Ltotal = (LScore1 +LScore2 + LScore3);

  score_ = Ltotal;

}


void StudentRecord::compute_history_score(void) {

  if (scores_.size() == 0 ) {
     return ;
  }
  double HScore1, HScore2,New, Old;
  double Max = FLT_MAX;
  score_ = 0.0;
  for (unsigned int i = 0; i < scores_.size(); i++) {
      HScore1 = scores_[i];
      if (HScore1 < Max) {
          Max = HScore1;}
      New = (0.4*Max);

  for (unsigned int i = 0; i < scores_.size(); i++) {
  HScore1 = scores_[i];
      if (HScore1> HScore2){
          HScore2= HScore1;}
      Old = (0.6*HScore2);

}
      score_ = (New + Old);
      
}
}
