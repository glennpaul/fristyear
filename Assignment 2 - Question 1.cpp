// Glenn Paul B. Sumido 100933901
// Program to Calculate Pie

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
    double N, // Nth term to execute infinite series
           Result; // Pie when infinite series is executed to N'th Term

    // Prompting user for value of N
    cout << "Input N-Value: ";
    cin >> N;

    // gives user option to terminate program
    while (N>0) {

        // ensures N-value is an integer
        if (isInt(N)) {
            // initializes result value and resets it when given a new N-value
            Result = 4;

            // loop to keep program running until desired terms have been calculated
            while (N>0) {

                if (isInt(N/2)) {
                    // Subtract Even Term
                    Result = Result + 4*(1/(2*N +1));
                } else {
                    // Add Odd Term
                    Result = Result - 4*(1/(2*N +1));
                } // end if

                // Advance to following term in series
                N = N-1;
            } // end while

            // Show Result to User
            cout << "Result: " << Result << endl;
        } else {
            cout << "Error. Input value was not an integer." << endl;
        } // end if

        // Prompt User for New N-Value
        cout << "Input New N-value:";
        cin >> N;

    } // end while

    system("PAUSE"); return 0;

}
