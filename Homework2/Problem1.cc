//Programmer: Chris DeLotto
//Program:    Midpoint-Slope
//Purpose:    Get Midpoint,slope, y-intercept,perpendicular line,line function

#include <iostream>
using namespace std;
//---------------------------PROMP's------------------------------------------------
int main()
{
  float  x1,x2,y1,y2,midpoint1,midpoint2,slope,top,bottom,intercept,perp_line_slope,y_inter_perp;


  cout << "This program will calculate the Midpoint & Slope of a line." << endl<<endl;

  cout << "Please input the value of the first point, x1 & y1 with a space in between: ";
  cin >> x1 >> y1;

  cout << "Thank you, please input the value of the second point: ";
  cin >> x2 >> y2;
  //-------------------------FUNCTIONS-------------------------------------------
  midpoint1 = (x1 + x2) / 2; 
  midpoint2 = (y1 + y2) / 2;

  top =       (y2 - y1);
  bottom =    (x2 - x1);//<------THIS CAN NOT BE ZERO!!!!!
  
  slope = top / bottom;

  intercept = y1 - slope * x1;

  perp_line_slope = slope * (-1);

  y_inter_perp = y1 - (perp_line_slope * x1);

  cout << endl<<endl;
  //------------------------OUTCOMES-----------------------------------------
  if(bottom == 0){

  cout << "YO HOMIE YOUR DENOMINATOR CAN'T BE ZERO!!! ";

  }

  else{

  cout << "The midpoint of the line is (" << midpoint1 << ", " << midpoint2 << ")." << endl << endl;
  cout << "The slope of the line is ( " << slope << "  ) .  " << endl << endl;
  cout << "The Y-intercept is ( " << intercept << "  ) .  " << endl << endl;

  cout << "The equation of the slope intercept is: " << "Y= ";
  cout << slope << "x" << " + " << intercept << endl << endl;

  cout << "The purpendicular line is: " << "Y= ";
  cout << perp_line_slope << "x" << " + " << y_inter_perp << endl << endl;

  cout << "Thanks for using this program ;)." << endl<<endl;

  }
  //----------------------------END------------------------------------------------------
}
