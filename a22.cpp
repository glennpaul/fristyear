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

    // Prompt user for lot dimensions
    cout << "Length and Width of Lot: ";
    cin >> LengthLot >> WidthLot;

    // ensure correct dimensions and promt for new ones if not
    if (LengthLot<=0||WidthLot<=0) {

        while (LengthLot<=0||WidthLot<=0) {
            cout << "Error: Length and Width of Lot must be greater than zero." << endl;
            cout << "Length and Width of Lot: ";
            cin >> LengthLot >> WidthLot;
        } // end while

    } // end if

    // rearrange dimensions so bigger ones are first
    if (WidthLot>LengthLot) {
        Temp = LengthLot;
        LengthLot = WidthLot;
        WidthLot = Temp;
    } // end if

    // promt for house dimensions
    while (LengthHouse!=0&&WidthHouse!=0) {

        cout << "Length and Width of House (0 0 to stop) : ";
        cin >> LengthHouse >> WidthHouse;


        // rearrange house dimensions
        if (WidthHouse>LengthHouse) {
            Temp = LengthHouse;
            LengthHouse = WidthHouse;
            WidthHouse = Temp;
        } // end if

        // check for sentinel values, loop if not
        if (LengthHouse>0&&WidthHouse>0) {

            // check for lot line allowance
            if (LengthHouse+4 <= LengthLot&&WidthHouse+4<=WidthLot) {

                // check if house is too small
                if (LengthHouse*WidthHouse >= 0.25*LengthLot*WidthLot) {

                    // check if house is too big
                    if (LengthHouse*WidthHouse<=0.4*LengthLot*WidthLot) {
                        // show user house is good
                        cout << "The house fits the lot." << endl;
                    } else {
                        // show user house too big
                        cout << "The house is too big." << endl;
                    } // end if

                } else {
                    // show user house too small
                    cout << "The house is too small." << endl;
                } // end if

            } else {
                // show user lot clearance not met
                cout << "The house does not allow for the lot line clearance." << endl;
            } // end if

        } else {
            // show user values need to be positive
            cout << "Error. House dimensions are impossible. Enter New Values." << endl;
        } // end if


    } // end while

    system("PAUSE"); return 0;

}
