// Program to produce tables of integer values, the number of unique ways to choose three items from this value, its cube root, 
// and an indication of whether the number is a perfect square or not. */  

// Name: Glenn Paul B. Sumido
// Student Number: 100933901

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

    int rows, //number of rows in table
		decimals, //number of decimal places in cuberoot answer
		number, //number of ways to get 3 from value
		startvalue, //inputed value to be calculated for each row in table
		rowlimit; //maximum number of rows
		
    double cuberoot, //cuberoot of inputed value
		sentinel; //previous inputed number used as sentinel
		
    bool perfectsquare, //true or false if value is a perfect square
		firstTime = true; //true or false whether its the first time going into forloop to calculate values
    
    //forloop for sentinel value
    for (;;) {
    	
    	//forloop to check if starting value is correct
    	for (;;) {
    		
    		//prompt user for starting value
			cout << "Enter start value (repeat previous valid number to exit): ";
    		cin >> startvalue;
    		
    		//check for when starting value is correct and determine he limit for number of rows and output error if needed
    		if (startvalue<1000 && startvalue>-1000) {
    			
    			if (startvalue>900) {
    				
    				rowlimit = 1000 - startvalue; //calculae row limit if needed
    				
    			} else {
    				
    				rowlimit = 100;
    			
				}
    			
				break; //break to get out of check forloop   		
    		
			} else {
			
				cout << "Value must be between -999 and 999, try again!" << endl;
			
			} //endif
    		
    	} //end of startvalue check forloop
    	
    	//check to see if first time and also check for sentinel value
    	if (firstTime) {
    		
			firstTime = false; //start to check for sentinel value after first time
    		sentinel = startvalue;
    	
		} else if (startvalue == sentinel) {
    	
			break; //break to finish program when sentinel value appears
    	
		} //endif
    	
    	//store inputed value as sentinel value for next loop
    	sentinel = startvalue;
    	
    	//forloop for check if number of rows is valid
    	for (;;) {
    		
    		//propt for number of rows to display in table
    		cout << "Enter number of rows (1 to " << rowlimit << "): ";
    		cin >> rows;
    		
    		//check if row number inputed is valid and output error if needed
    		if (rows<=rowlimit && rows>0) {
    	
				break; //break to get out of forloop check if inputed value IS valid
    	
			} else {
		
				cout << "Rows must be between 1 and " << rowlimit << ", try again!" << endl;
		
			} //endif
    	
    	} //end of row check forloop
    	
    	//forloop to check for 
    	for (;;) {
    		
    		//propmt user for decimal places to show for cuberoot and output error if needed
    		cout << "Enter number of decimal places (2 to 6): ";
    		cin >> decimals;    
    	
    		//check if decimal value is valid
			if (decimals>1 && decimals<7) {
    	
				break;
    	
			} else {
		
				cout << "Decimals must be between 2 and 6, try again!" << endl;
		
			}//endif
    		
    	} //end of check for decimal forloop
    	
    	//display the headings for the columns in the table with their alloted space in the table
    	cout << setw(10) << "Value" << setw(15) << "ValueChoose3" << setw(15) << "Cube Root" << setw(15) << "Perfect Square" << endl;
    
    	//forloop to display values for each row in the table progressively
		for (; rows!=0; rows--) {
    	
    		//calculate the number of ways to get 3, cuberoot, and see if the value is a perfect square
			number = (((startvalue)*(startvalue-1)*(startvalue-2))/6);
    		cuberoot = pow((fabs(startvalue)),(1.0/3.0));
    		
    		//make sure cuberoot is negative if the original value was negative
    		if (startvalue<0) {
    	
				cuberoot = cuberoot*(-1);
    	
			} //endif
    		
    		//see if value is perfect square
    		perfectsquare = isInt(sqrt(startvalue));
    		
    		//display value in correct place
    		cout << setw(10) << startvalue;
    	
			//see if it is possible to get number of ways to get 3
			if (startvalue<3) {
		
				cout << setw(15) << "N/A"; //display N/A if not valid
		
			} else {
		
				cout << setw(15) << std::fixed << number; //display number of ways if valid in correct place
		
			} //endif
		
			// display the cuberoot to the specified decimal place and in right place
			cout << setprecision(decimals) << setw(15) << cuberoot;
    	
			// see if value is a perfect square
			if (perfectsquare && startvalue>0) {
    	
				cout << setw(15) << "yes" << endl; // display yes in correct place if it is perfect square
    	
			} else {
		
				cout << setw(15) << "no" << endl; // display no in correct place if value isn't a perfect square
		
			} //endif
		
    		//increment value for next row of table 
			startvalue++;
    
		} //end of row forloop
		cout << endl;

    } // end of sentinel forloop
	
	system("PAUSE"); return 0;	
}
