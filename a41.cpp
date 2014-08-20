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

bool isLeap(int year) {
	if (Year<2010) {
		return false;
	} else if ((Year%4==0&&Year%100!=0)||(Year%4==0&&Year%100==0&&Year%400==0)) {
		return true;
	} else {
		return false;
	}
}

int main (void) {

    // Variables
    int Year, //user input for year (numerical)
        Month, //user input for month (numerical)
        Day, //user input for day (numerical)
        Total = 734137, //previous date converted to number of days
        NewTotal, //secondary date converted to days
        TotalDates = 0, // total number of dates entered by user
        ShortestGap = 1000000000, //shortest gap between dates in days
        LongestGap = 0, //longest gap between dates in days
        CurrentGap = 0, //intermediary gape between most recent dates
        Adays, //gap seperated for days
    	Ahours, //gap seperated for hours
    	Aminutes, //gap seperated for minutes
    	Aseconds; //gap seperated for seconds
        
    double TotalGap = 0, //total length of all gaps
    	ValidDates = 0; //number of valid dates entered by user


	// Prompt user for input dates and show date in dd/mm/yy
    cout << "Enter date as year month day (0 0 0 to stop): ";
    cin >> Year >> Month >> Day;
    TotalDates++; //count of all dates entered


    for (;;){

        // calculate date in days with leap year,
        NewTotal = ((Year-1)*365) + (Day) + (Year)/4 -(Year)/100 + (Year)/400;
        
        // fix for if not after february, do not add day for leap year
        if (!(Month>2 && Year%4==0 && Year%100!=0) || !(Month>2 && Year%100==0 && Year%400==0)) {
        	NewTotal--;
        } //endif

		//calculate days of past months in the current year
		if (Month==4||Month==6||Month==9||Month==11) {
			
			if (Day>31) {
				
				 //tell user date is invalid for numerical parameters
                cout << "** Date ignored - date invalid. **" << endl;
                
			} //endif
			
		} else if (Month==2) {
			
			if ((Year%4==0&&Year%100==0)||(Year%100!=0&&Year%400==0)) {
				
				if (Day>29) {
					//tell user date is invalid for numerical parameters
                	cout << "** Date ignored - date invalid. **" << endl;                
				}
				
			} else {
				
				if (Day>28)				
				//tell user date is invalid for numerical parameters
                cout << "** Date ignored - date invalid. **" << endl; 
				               
			}//endif
			
		} else if (Month==1||Month==3||Month==5||Month==7||Month==8||Month==10||Month==12) {
			if (Day>30) {
				
				 //tell user date is invalid for numerical parameters
                cout << "** Date ignored - date invalid. **" << endl;
                
			}//endif
		} else {		
		
		
	        if (Month==2) {
        	
        		NewTotal += 31;
        	
        	} else if (Month==3) {
        	
        		NewTotal += 59;
        	
        	} else if (Month==4) {
        	
        		NewTotal +=90;
        	
        	} else if (Month==5) {
        	
        		NewTotal +=120;
        	
        	} else if (Month==6) {
        	
        		NewTotal += 151;
        	
        	} else if (Month==7) {
        	
        		NewTotal += 181;
        	
        	} else if (Month==8) {
        	
        		NewTotal +=212;
        	
        	} else if (Month==9) {
        	
        		NewTotal +=243;
        	
        	} else if (Month==10) {
        	
        		NewTotal +=273;
        	
        	} else if (Month==11) {
        	
        		NewTotal +=304;
        	
        	} else if (Month==12) {
        	
        		NewTotal +=334;
        	
        	} //endif

        	// make sure date is later on than previous date
        	if (NewTotal>=Total) { //make sure all dates are entered in correct order e.g. most recent last

            	if (Year>2009 && Month>0 && Month<13 && Day>0)  { //make sure dates are valid numerically and make sense
				
					//display date in dd/mm/yy form
					cout << setw(65) << "Valid Date: " << setw(2) << setfill('0') << Day << "-" << setw(2) << setfill('0') << Month << "-" << setw(2) << Year%100 << setfill(' ')<< endl;
                	if (TotalDates<2) { //get initial date

                    	Total = NewTotal; // store total value as old total value
                    	ValidDates++; //number of valid dates entered

                	} else { //all dates after first inital date entered

                    	ValidDates++; //increase valid date count
                    	CurrentGap = NewTotal - Total; //calculate current gap between most recent dates
                    	TotalGap += CurrentGap; //add current gap to total gap between dates
                    	Total = NewTotal; //store most recent date the older date to be ready for next inputed date

                    	//check if current gap is shortest or longest gap and store number if they are
                    	if (CurrentGap < ShortestGap) {
                        	ShortestGap = CurrentGap;
                    	} // end if
                    	if (CurrentGap > LongestGap) {
                        	LongestGap = CurrentGap;
                    	} // end if

                	} // end if
                
                	//Show gap
					if (TotalDates>1) {
						cout << setw(65) << "The gap is: " << CurrentGap << " days." << endl;
					}

            	} else {

                	 //tell user date is invalid for numerical parameters
                	cout << "** Date ignored - date invalid. **" << endl;

            	} // end if

        	} else {
         
            	//tell user date is not after previous date
            	cout << "** Date ignored - not >= previous date. **" << endl;

        	} // end if
        
    	}//endif

		// Prompt user for input dates
        cout << "Enter date as year month day (0 0 0 to stop): ";
        cin >> Year >> Month >> Day;
        if (Year==0 && Month==0 && Day==0) {
        	break;
        }
        TotalDates++; //count of all dates entered

	} //endwhile
    
    //output statistics if capable
    if (ValidDates>=2) {
    	
    cout << ValidDates << " valid dates and " << (TotalDates - ValidDates) << " invalid dates were entered." << endl;
    cout << "The shortest gap was " << ShortestGap << " days." << endl;
    cout << "The longest gap was " << LongestGap << " days." << endl;
    
    //calculate divisions of average gap and display them
    Adays = TotalGap / (ValidDates-1.0) ;
    Ahours = ( (TotalGap/(ValidDates-1.0)) - Adays ) * 24;
    Aminutes = ((( (TotalGap/(ValidDates-1.0)) - Adays ) * 24) - Ahours) * 60 ;
    Aseconds = ((((( (TotalGap/(ValidDates-1.0)) - Adays ) * 24) - Ahours) * 60) - Aminutes) * 60 ;
    cout << "The average gap length was " << Adays << " days, " << Ahours << " hours, " << Aminutes << " minutes, and " << Aseconds << " seconds." << endl;
	  	
    } else { 
	
	//output for when less than two dates have been inputed before the sentinel value is inputed
    cout << "0 valid dates and 0 invalid dates were entered." << endl;
    cout << "No gap information to calculate." << endl;
    
    }
    
    system("PAUSE"); return 0;
}
