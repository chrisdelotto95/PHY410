//Programmer: Chris DeLotto
//Program:    Factorial
//Purpose:    Get the factorial of a positive integer
#include <iostream>
using namespace std;

int main()
{
    cout<< endl << endl;

    unsigned int n;
    unsigned long long factorial = 1;

    cout << "Enter a positive integer smaller then 20: ";
    cin >> n;

    for(int i = 1; i <=n; ++i)
    {
        factorial *= i;
    }

    cout << endl << endl << "Factorial of " << n << " = " << factorial << endl << endl;    
    return 0;
}
