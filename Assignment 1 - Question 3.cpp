// Program to find location of a point on Cartesian Plane

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
    double X, // X-coordinate value
           Y; // Y-coordinate value

    // Prompt User for Coordinate Values
    cout << "Input X-Coordinate Value: ";
    cin >> X;
    cout << "Input Y-Coordinate Value: ";
    cin >> Y;

    if (Y==0) {

        if (X==0) {
            cout << "Point is the Origin.";
        } else {
            cout << "Point is on the X-Axis.";
        } // end if

    } else {

        if (X==0) {
            cout << "Point is on the Y-Axis";
        } else {

            if (X>0) {

                if (Y>0) {
                    cout << "Point is in Quadrant 1.";
                } else {
                    cout << "Point is in Quadrant 4.";
                } // end if

            } else {

                if (Y>0) {
                    cout << "Point is in Quadrant 2.";
                } else {
                    cout << "Point is in Quadrant 3.";

                } // end if

            } // end if

        } // end if

    } // end if

    system("PAUSE"); return 0;

}
