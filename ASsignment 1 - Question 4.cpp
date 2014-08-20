// Program to to execute Pie's Infinite Series to the N'th term.

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

bool isInt (double value) {
    double dummy;
    return bool(modf(value, &dummy) == 0);
}

int main (void) {

    // Variables
    double N, // Nth term to execute infinite series
           Result; // Pie when infinite series is executed to N'th Term

    // Prompting user for value of N
    cout << "Input N-Value: ";
    cin >> N;

    while (N>0) {
        Result = 4;

        while (N>0) {

            if (isInt(N/2)) {
                // Subtract Even Term
                Result = Result + 4*(1/(2*N +1));
            } else {
                // Add Odd Term
                Result = Result - 4*(1/(2*N +1));
            } // end if

            // Advance to previous term in series
            N = N-1;
        } // end while

        // Show Result to User
        cout << "Result: ";
        cout << Result;
        cout << endl;
        // Prompt User for New N-Value
        cout << "Input New N-value:";
        cin >> N;

    } // end while

    system("PAUSE"); return 0;

}
