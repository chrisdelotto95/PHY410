//Programmer: Chris DeLotto
//Program:    Smallest Magnitude
//Purpose:    Find the smallest magnitude out of a set of pairs
#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

int main(void) {

float xi=0., yi =0., xmin = 0., ymin = 0.;

float SmallMag = numeric_limits<float>::max();


cout<< endl <<"enter x1 y1 xn yn components with a space between them " << endl << endl;

  while(cin >> xi >> yi) {
    cout << "Vector "<< "(" << xi <<","<< yi << ")" << endl << endl; //<---- this will set up the (xi,yi) format

    //-----------------^-----------^--------INPUT----------^-------------^-------------------
	
    float Mag = sqrt(xi*xi+yi*yi);//<----this sets the Magnitude equation


  cout <<"The magnitude is = "<< "(" << Mag << ")" << endl << endl;
  cout <<"                                      ^  vector"<< endl;
  cout <<"-------------------------------------------------"<< endl << endl;
 
 if (Mag < SmallMag) {

  xmin = xi;

  ymin = yi;

  SmallMag = Mag;
}

  }

  //------------------^-----------^--------FUNCTION-----------^-------------^----------------
 

  cout <<"The smallest magnitude is = "<< "(" << SmallMag << ")" << endl << endl;
  cout <<"The vector pair it was for was = "<< "(" << xmin << "," << ymin << ")" << endl << endl;

 cout <<"                                      ^  RESULT"<< endl;
  cout <<"-------------------------------------------------"<< endl;

  return 0;
  }

//------------------^-----------^---------OUTPUT------------^-------------^-----------------
