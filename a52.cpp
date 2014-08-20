//Glenn Paul B. SUmido 100933901
//used sample solution from assignment 4
//program to calculate the number of days since a social engagement

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

bool isLeap(int year) { //check if leapyear

	if (year<2010) {
		return false; //error checking for years before 2010
	} else if ((year%4==0&&year%100!=0)||(year%4==0&&year%100==0&&year%400==0)) { //calculate if leap year or not
		return true; //return true if it is leap year
	} else {
		return false; //return false if not leap year
	}
	
}

int daysInMonth (int month, int year) { //calculate days in month

	int days; //days
	
	if (month>12||month<1||year<2010) { //check for month validity and year validity
		return 0; //return error
	} else if (month==1) {
		days= 31;
	} else if (month==2) {
		if (isLeap(year)==true) { //edit number for leap years
			days= 29;
		} else {
			days= 28;
		}//endif
	} else if (month==3) {
		days= 31;
	} else if (month==4) {
		days= 30;
	} else if (month==5) {
		days= 31;
	} else if (month==6) {
		days= 30;
	} else if (month==7) {
		days= 31;
	} else if (month==8) {
		days= 31;
	} else if (month==9) {
		days= 30;
	} else if (month==10) {
		days= 31;
	} else if (month==11) {
		days= 30;
	} else if (month==12) {
		days= 31;
	} //endif
	
	return days; //output days in month
	
}//endif

int dayNumber (int day, int month, int year) { //calculate days in year

	int total;
	
	if ((isLeap(year)==true&&day>366)||(isLeap(year)==false&&day>365)) { //check if leap year
		return 0;
	} else if (month>12||month<1) { //check for month valididty
		return 0;
	} else if (year>=2010) { //check for year validity
		return 0;
	}//endif
	
	total = day; //start calculations with number of days
	
	for (;month>1;month--) { //calculate day in year till given months
		total+= daysInMonth(month,year);
	} //endfor
	
	return total; //return total
	
}

int daysInPreviousYearsSince2010 (int year) {
	
	int days;
	
	if (year<=2010) { //error check for year
		return 0;
	}//endif
	
	for (;year>2010;year--) { //calculate number of days in year with leap year check
		if (isLeap(year)==true) {
			days+=366;
		} else {
			days+=365;
		}
	}
	
	return days; //output number of days
	
}

int projectDayNumber (int day, int month, int year) { //calculate days since start of project
	
	int projectday; //number of says since project start
	
	if ((isLeap(year)==true&&day>366)||(isLeap(year)==false&&day>365)) { //error check for number of days
		return 0;
	} else if (month>12||month<1) { //error check for months
		return 0;
	} else if (year>=2010) { //error check for yeas
		return 0;
	}//endif
	
	projectday= daysInPreviousYearsSince2010(year) + dayNumber(day,month,year); //calculate days since project start
	
	return projectday; //output answer
	
}




int main (void) {

    // Constants (optional)
    const int HOURSPERDAY = 24,
              MINSPERHOUR = 60,
              SECSPERMIN = 60;
    
    // Variables
	int	newYear, //input year
		newMonth, //input month
		newDay, //input day
		newDaysFromStart, //new days since start of project
		prevDaysFromStart=0, // last days since start of project
		numValidDates=0, //number of valid dates inputed
		numInvalidDates=0, //invalid dates inputed
		longestGap=0, //largest gap
		shortestGap=0, //smallest gap
		tempGap, //gap temporary value
		totalGap=0, //total of all gaps
		numDays, // number of days in the current month
		tempYear,
		tempMonth,
		intDays, //integer value for days in gap
		intHours, //integer value for hours in gap leftover
		intMins, //integer value for mins in gap leftover
		roundSecs; //integer value for mins in gap leftover
	bool leapFlag; // is the current year a leap year?
	double avgGap, // average gap length (in days)
	       hours,
	       mins;	     
		     
	// loop until 0 0 0 entered
	for(;;) { 
    	// Get date
    	cout << "Enter date as year month day (0 0 0 to stop): ";
    	cin >> newYear >> newMonth >> newDay;
    
    	// check for sentinel values
    	if (newYear==0 && newMonth==0 && newDay==0){
			break;
		}
		
		// Set leap year flag as it will help later
		if ((newYear%4==0 && newYear%100!=0) || newYear%400==0) {
			leapFlag=true;
		} else {
			leapFlag=false;
		}
		
		// Check for valid date entry 
		if (daysInMonth(newMonth,newYear)==0 || newDay<1){
			// bad date 
			cout << "** Date ignored - date invalid. **" << endl;
			numInvalidDates++;
		} else { // still need to check maximum valid value for newDay
			// Calculate number of days in this month
			if (newMonth==2) { // February has 28 or 29 days
				// is it a leap year (flag set above)?
				if (leapFlag) {
					numDays=29;
				} else {
					numDays=28;
				}
			} else if (newMonth==4 || newMonth==6 || newMonth==9 || newMonth==11) {
				numDays=30; // April, June, September, and November have 30 days
			} else {
				numDays=31; // the rest have 31
			}//endif
			if (newDay>numDays) {
				// bad date 
				cout << "** Date ignored - date invalid. **" << endl;
				numInvalidDates++;

			} else { 
				// calculate the number of days since the start of the project
				
				// newDaysFromStart is initialized the the day
				newDaysFromStart=newDay;
				
				// now for every previous year, add on the appropriate number of days (365 or 366)
				for (tempYear=newYear-1; tempYear>=2010; tempYear--) {
					// if it's a leap year, add 366
					if ((tempYear%4==0&&tempYear%100!=0) || tempYear%400==0) {
						newDaysFromStart+=366;
					} else { // add 365
						newDaysFromStart+=365;
					}
				}//endfor
				
				// alternatively you could do something like this (assume all years have 365 and adjust
				// for the leap years, and this code uses a while instead of a for, just for illustration
				// purposes
				/*
				// Convert to days since start of project: start with: 365*prev years + day
				newDaysFromStart=newDay + 365*(newYear-2010); 
				
				// add 1 for every leap year between newYear-1 and 2010
				tempYear = newYear-1;
				while(tempYear>=2010) {
					// if it's a leap year, add 1
					if ((tempYear%4==0&&tempYear%100!=0) || tempYear%400==0) {
						newDaysFromStart++;
					}
					tempYear--;
				}//endwhile
				*/
					
				// add on the previous months in the current year
				for (tempMonth = newMonth-1; tempMonth>=1; tempMonth--) {
					// figure out the number of days
					if (tempMonth==2) { // February has 28 or 29 days
						// is it a leap year (flag set above)?
						if (leapFlag) {
							numDays=29;
						} else {
							numDays=28;
						}
					} else if (tempMonth==4 || tempMonth==6 || tempMonth==9 || tempMonth==11) {
						numDays=30; // April, June, September, and November have 30 days
					} else {
						numDays=31; // the rest have 31
					}//endif
					newDaysFromStart+=numDays;
				}//endfor
									
				// Now to check if date after previous date
				if (newDaysFromStart<prevDaysFromStart){
					// not date after previous date
					cout << "** Date ignored - not >= previous date. **" << endl;
					numInvalidDates=numInvalidDates+1;
				} else {
					// have a new date to process
					
					// output date in dd-mmm-yyyy format
					cout << setw(65) << "Valid date: " 
					     << setfill('0') // set fill to 0s
						 << setw(2) << newDay // output in 2 spaces with leading 0s
					     << "-" << setw(2) << newMonth // ditto
					     << "-" << setw(2) << newYear%100  
					                   // and last 2 digits of year with leading 0s
					     << setfill(' ') << endl; // reset fill back to blank
					
					numValidDates=numValidDates+1;
					if (numValidDates>1){
						// have 2 or more dates
						tempGap=newDaysFromStart-prevDaysFromStart;	
						totalGap+=tempGap;			// keep running total for average
						
						// output the gap in days
						cout << setw(65) << "The gap is: " << tempGap << " days." << endl;
						
						// check for longest / shortest gaps
						if (numValidDates==2 || longestGap<tempGap){ // first gap or largest
							longestGap=tempGap;		// set new max
						} //endif
						if (numValidDates==2 || shortestGap>tempGap){ // first gap or shortest
							shortestGap=tempGap;	// set new min
						} //endif
						
					} //endif
					
					prevDaysFromStart=newDaysFromStart;	// set for next time
				} //endif
			} //endif	
		} //endif

	} //endfor
	
	// output date info
    cout << numValidDates << " valid dates and " << numInvalidDates << " invalid dates were entered." << endl;
    
    // output gap info
	if (numValidDates>1) { // we have gap info
		cout << "The shortest gap was " << shortestGap << " days." << endl;
		cout << "The longest gap was " << longestGap << " days." << endl;
		
		// do the calculations for the average to break into days, hours,
		// minutes and (rounded) seconds
		avgGap = double(projectDayNumber(newDay,newMonth,newYear))/(numValidDates-1);
		intDays = int(avgGap);
		hours = (avgGap-intDays)*HOURSPERDAY; // convert leftover to hours
		intHours = int(hours);
		mins = (hours-intHours)*MINSPERHOUR; // convert leftover to minutes
		intMins = int(mins);
		roundSecs = int((mins-intMins)*SECSPERMIN+0.5);// round leftover to seconds
		if (roundSecs==60) {
			roundSecs=0;
			intMins++;
			if(intMins==60){
				intMins=0;
				intHours++;
				if(intHours==24){
					intHours=0;
					intDays++;
				} // end if
			} // end if
		} // end if
		
		// output the gap in days, hours, minutes, and (rounded) seconds
		cout << "The average gap length was " << intDays << " days, " <<  intHours 
		     << " hours, " << intMins << " minutes, and " << roundSecs << " seconds.\n"; 
	} else {
		cout << "No gap information to calculate." << endl;
	} //endif
	
    system("PAUSE"); return 0;

} 
