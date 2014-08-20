// Glenn Paul B. Sumido 100933901
// Program to ensure the legality of lots and houses

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
    double LengthHouse = 1, // Length of House
           WidthHouse = 1, // Width of House
           LengthLot = 1, // Length of Lot
           WidthLot = 1, // Width of Lot
           Temp = 1; // Temporary Variable for rearranging lengths and widths

    cout << "Length and Width of Lot: ";
    cin >> LengthLot >> WidthLot;

    if (WidthLot>LengthLot) {
        Temp = LengthLot;
        LengthLot = WidthLot;
        WidthLot = Temp;
    } // end if

    while (LengthHouse!=0) {

        while (WidthHouse!=0) {

            cout << "Length and Width of House (0 0 to stop) : ";
            cin >> LengthHouse >> WidthHouse;


            if (WidthHouse>LengthHouse) {
                Temp = LengthHouse;
                LengthHouse = WidthHouse;
                WidthHouse = Temp;
            } // end if

            if (1<LengthHouse+WidthHouse) {

                if (LengthHouse+4 <= LengthLot) {

                    if (WidthHouse+4<=WidthLot) {

                        if (LengthHouse*WidthHouse >= 0.25*LengthLot*WidthLot) {

                            if (LengthHouse*WidthHouse<=0.4*LengthLot*WidthLot) {
                                cout << "The house fits the lot." << endl;
                            } else {
                                cout << "The house is too big." << endl;
                            } // end if

                        } else {
                            cout << "The house is too small." << endl;
                        } // end if

                    } else {
                        cout << "The house does not allow for the lot line clearance." << endl;
                    } // end if

                } else {
                    cout << "The house does not allow for the lot line clearance." << endl;
                } // end if

            } else {
                cout << "Error. House dimensions are impossible. Enter New Values." << endl;
            } // end if

        } // end while

    } // end while

    system("PAUSE"); return 0;

}
