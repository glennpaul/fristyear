//Glenn Paul. B Sumido 100933901
//program to calculate the gaps inbetween social engagements

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
    int Year, //user input for year (numerical)
        Month, //user input for month (numerical)
        Day, //user input for day (numerical)
        Total = 723631, //previous date converted to number of days
        NewTotal, //secondary date converted to days
        ValidDates = 0, //number of valid dates entered by user
        TotalDates = 0, // total number of dates entered by user
        ShortestGap = 1000000000, //shortest gap between dates in days
        LongestGap = 0, //longest gap between dates in days
        TotalGap = 0, //total length of all gaps
        CurrentGap = 0; //intermediary gape between most recent dates

	// Prompt user for input dates
    cout << "Enter date as year month day (0 0 0 to stop): ";
    cin >> Year >> Month >> Day;
    TotalDates = TotalDates+1; //count of all dates entered

    while (Year!=0 && Month!=0 && Day!=0) {

        // calculate date in days
        NewTotal = (Year*360) + (Month*30) + (Day);

        // make sure date is later on than previous date
        if (NewTotal>Total) { //make sure all dates are entered in correct order e.g. most recent last

            if (Year>2009 && Month>0 && Month<13 && Day>0 && Day<31) { //make sure dates are valid numerically and make sense

                if (TotalDates<2) { //get initial date

                    Total = NewTotal;
                    ValidDates = ValidDates+1; //number of valid dates entered

                } else { //all dates after first inital date entered

                    ValidDates = ValidDates+1; //increase valid date count
                    CurrentGap = NewTotal - Total; //calculate current gap between most recent dates
                    TotalGap = TotalGap + CurrentGap; //add current gap to total gap between dates
                    Total = NewTotal; //store most recent date the older date to be ready for next inputed date

                    //check if current gap is shortest or longest gap and store number if they are
                    if (CurrentGap < ShortestGap) {
                        ShortestGap = CurrentGap;
                    } // end if
                    if (CurrentGap > LongestGap) {
                        LongestGap = CurrentGap;
                    } // end if

                } // end if

            } else {

                 //tell user date is invalid for numerical parameters
                cout << "** Date ignored - date invalid. **" << endl;

            } // end if

        } else {
         
            //tell user date is not after previous date
            cout << "** Date ignored - not >= previous date. **" << endl;

        } // end if

		// Prompt user for input dates
        cout << "Enter date as year month day (0 0 0 to stop): ";
        cin >> Year >> Month >> Day;
        TotalDates = TotalDates+1; //count of all dates entered

    } //endwhile
    
    //output statistics if capable
    if (ValidDates>=2) {
    	
    cout << ValidDates << " valid dates and " << (TotalDates - ValidDates) << " invalid dates were entered." << endl;
    cout << "The shortest gap was " << ShortestGap << " days." << endl;
    cout << "The longest gap was " << LongestGap << " days." << endl;
    cout << "The average gap length was " << (TotalGap/(ValidDates-1.0)) << " days." << endl; 
	  	
    } else { //output for when less than two dates have been inputed before the sentinel value is inputed
    
    cout << "0 valid dates and 0 invalid dates were entered." << endl;
    cout << "No gap information to calculate." << endl;
    
    }
    
    system("PAUSE"); return 0;
}
