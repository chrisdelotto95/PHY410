#include <cmath>
#include <istream>
#include <iomanip>
using namespace std;

#include "nonlin.hpp"
using namespace cpt;

const double pi = 4* atan(1.0);

double f(Matrix<double,1>& p) {
    double x = p[0], y = p[1];
    return .25*x*x*x*x+.25*y*y*y*y+.5*x*x*y*y-.5*x*x-.5*y*y;
    }

void df(Matrix<double,1>& p, Matrix<double,1>& dp) {
    double x = p[0], y = p[1];
    dp[0] = x*x*x+x*y*y-x;
    dp[1] = y*y*y+x*x*y-y;
    return;
}

int main()
{
    cout << " Minimization using Broyden-Fletcher-Goldfarb-Shanno Algorithm\n"
         << " Finding minimum of 2-d Higgs equation with inputted I.C."
         << " Enter starting point coordinates x y: ";
    Matrix<double,1> p(2);
    cin >> p[0] >> p[1];
    double gtol = 0.0001;
    double f_min;
    int iterations;
    minimize_BFGS(p, gtol, iterations, f_min, f, df);
    cout << " f(" << p[0] << ", " << p[1] << ") = " << f_min
         << " in " << iterations << " iterations" << endl;
}
