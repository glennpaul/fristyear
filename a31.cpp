// Glenn Paul B. Sumido 100933901
// Program to ensure the legality of lots and houses and to give user statistics for dimensions entered

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
    double LengthHouse, // Length of House
           WidthHouse, // Width of House
           LengthLot, // Length of Lot
           WidthLot, // Width of Lot
           Temp = 0, // Temporary Variable for rearranging lengths and widths
           LotTries = 0, // Tries to get valid lot size
           HouseTries = 0, // Total amount of house dimensions entered
           InvalidHouseTries = 0, // Number of house dimensions entered which were invalid
           HousesThatFit = 0, // House dimensions entered that fit the lot
           HouseLineClearance = 0, // Number of house dimensions entered that didn't fit due to line clearance of lot
           HouseTooBig = 0, // Number of house dimensions entered that were too big for lot
           HouseTooSmall = 0, // Number of house dimensions entered that were too small for lot
           SumFit = 0, // sum of areas of houses that fit the lot
           LargestFit = 0, // Area of largest house that fit the lot
           SmallestFit = 1000000; // Area of smallest house that fit lot

    // Prompt user for lot dimensions
    cout << "Length and Width of Lot: ";
    cin >> LengthLot >> WidthLot;
    // count for lot dimensions entered
    LotTries = LotTries+1;

    // check for valid dimensions
    while (LengthLot<=0||WidthLot<=0) {
        cout << "Length and Width of Lot (positive values): ";
        cin >> LengthLot >> WidthLot;
        // count for dimensions entered
        LotTries = LotTries+1;
    } // end while

    // Dimension arrangement correction
    if (WidthLot>LengthLot) {
        Temp = LengthLot;
        LengthLot = WidthLot;
        WidthLot = Temp;
    } // end if

    // Prompt user for house dimensions
    cout << "Length and Width of House(0 0 stats/ negative to stop): ";
    cin >> LengthHouse >> WidthHouse;
    // count for house dimensions entered
    HouseTries = HouseTries+1;

    // Dimension arrangement correction
    if (WidthHouse>LengthHouse) {
        Temp = LengthHouse;
        LengthHouse = WidthHouse;
        WidthHouse = Temp;
    } // end if

    // Setting benchmarks for largest and smallest area
    LargestFit = LengthHouse*WidthHouse;
    SmallestFit = LengthHouse*WidthHouse;

    // Loop to continue prompting user and giving decision if house fit lot or not
    while (LengthHouse!=0&&WidthHouse!=0) {

        // loop for when user inputs valid dimensions
        while (LengthHouse>0&&WidthHouse>0) {

            // check for line clearance
            if (LengthHouse+4 <= LengthLot&&WidthHouse+4<=WidthLot) {

                // check for too small
                if (LengthHouse*WidthHouse >= 0.25*LengthLot*WidthLot) {

                    // check for too big
                    if (LengthHouse*WidthHouse<=0.4*LengthLot*WidthLot) {

                        // house fits
                        cout << "The house fits the lot." << endl;
                        // increase numbercount of houses that fit
                        HousesThatFit = HousesThatFit+1;
                        // add area of entered dimensions to sum of areas that fit for later calculation of average
                        SumFit = SumFit + (LengthHouse*WidthHouse);
                        // check for largest fit
                        if ((LengthHouse*WidthHouse)>LargestFit) {
                            LargestFit = LengthHouse*WidthHouse;
                        } // end if
                        // check for smallest fit
                        if ((LengthHouse*WidthHouse)<SmallestFit) {
                            SmallestFit = LengthHouse*WidthHouse;
                        } // end if

                    } else {
                        // house too big
                        cout << "The house is too big." << endl;
                        // increase count for houses that are too big
                        HouseTooBig = HouseTooBig+1;
                    } // end if

                } else {
                    // house too small
                    cout << "The house is too small." << endl;
                    // increase count for houses too small
                    HouseTooSmall = HouseTooSmall+1;
                } // end if

            } else {
                // house does not allow for line clearance
                cout << "The house does not allow for the lot line clearance." << endl;
                // increase count for houses that don't fit line clearance
                HouseLineClearance = HouseLineClearance+1;
            } // end if

            // prompt user for new house dimensions
            cout << "Length and Width of House(0 0 stats/ negative to stop): ";
            cin >> LengthHouse >> WidthHouse;
            // increase count for house dimensions entered
            HouseTries = HouseTries+1;

            // Dimension arrangement correction
            if (WidthHouse>LengthHouse) {
                Temp = LengthHouse;
                LengthHouse = WidthHouse;
                WidthHouse = Temp;
            } // end if

        } // end while

        // loop for invalid entered dimensions
        while ((LengthHouse>0&&WidthHouse==0)||(LengthHouse==0&&WidthHouse>0)||LengthHouse<0||WidthHouse<0) {

            // initializing invalid house tries with assumption user must have entered invalid dimensions to get into this loop
            InvalidHouseTries = InvalidHouseTries+1;
            cout << "Values must be positive." << endl;
            // prompt user for new dimensions
            cout << "Length and Width of House(0 0 to see stats): ";
            cin >> LengthHouse >> WidthHouse;
            // increase count for invalid dimensions

            // Dimension arrangement correction
            if (WidthHouse>LengthHouse) {
                Temp = LengthHouse;
                LengthHouse = WidthHouse;
                WidthHouse = Temp;
            } // end if

        } // end while

    } // end while

    // if program reaches here, 0 0 has been entered. Therefore, it's time to show the statistics.
    cout << "Statistics: " << endl;
    cout << endl;

    // statistics for total numbers tried
    cout << "Tries to get valid Lot size: " << LotTries << endl;
    cout << "Number of House sizes entered: " << HouseTries << endl;
    cout << "Number of invalid House sizes entered: " << InvalidHouseTries << endl;
    cout << "Number of valid House sizes entered: " << HousesThatFit << endl;
    cout << endl;

    // statistics for ones that fit or didn't fit (pure numbers)
    cout << "Houses that fit: " << HousesThatFit << endl;
    cout << "Houses that violate line clearance: " << HouseLineClearance << endl;
    cout << "Houses that are too small: " << HouseTooSmall << endl;
    cout << "Houses that are too big: " << HouseTooBig << endl;
    cout << endl;

    // percent statistics for houses that fit and didn't fit
    cout << "Percent of Houses that fit: " << (HousesThatFit/HouseTries)*100 << endl;
    cout << "Percent of houses that don't fit: " << ((HouseLineClearance+HouseTooBig+HouseTooSmall)/HouseTries)*100 << endl;
    cout << "Percent that don't fit due to Line Clearance: " << (HouseLineClearance/HouseTries)*100 << endl;
    cout << "Percent that are too small: " << (HouseTooSmall/HouseTries)*100 << endl;
    cout << "Percent that are too big: " << (HouseTooBig/HouseTries)*100 << endl;
    cout << endl;

    // area statistics
    cout << "Average Area of Houses that fit: " << ((SumFit)/HousesThatFit) << endl;
    cout << "Area of Largest House that fit Lot: " << LargestFit << endl;
    cout << "Area of Smallest House that fit Lot: " << SmallestFit << endl;

    system("PAUSE"); return 0;

}
