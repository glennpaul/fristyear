// Program for calculating Infinite Series Equation to Calculate Pie

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

bool isInt (double value) {
    double dummy;
    return bool(modf(value, &dummy) == 0);
}

double sqr(double value) {
    return value * value;
}

int main (void) {

    // Variables
    double Result,
           N,
           Q,
           P;

    // Promt for N-Value
    cout << "Input N-Value: ";
    cin >> N;

    while (N>0) {

        // Initialize Result
        Result = 4;

        while (N>0) {
            // Initialize Q and P
            Q = 1;
            P = N;

            // Determining Even or Odd Term in Sequence
            while (P>0) {
                Q = Q*(-1);
                P = P-1;
            } // end while

            // Calculating Term in Sequence
            Result = Result + Q*4*(1/((N*2)+1));
            // Proceeding to next term in sequence
            N = N-1;

        } // end while

        // Show User Result
        cout << "Result: " << Result << endl;
        // Extra Line for Readability
        cout << endl;
        // Prompt for New N-Value
        cout << "Input New N-Value: ";
        cin >> N;
    } // end while


    system("PAUSE"); return 0;

}
