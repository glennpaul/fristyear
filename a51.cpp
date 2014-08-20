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

bool isSqr(int value) {
	if (isInt(pow(value,0.5))) { //check if positive
		return 1; //reveal its possitive
	} else {
		return 0; //reveal it isn't positive
	}
}

double cubeRoot (int value) {
	if (value>0) {
		return pow((fabs(value)),(1.0/3.0)); //calculate cuberoot if positive value
	} else {
		return -1*pow((fabs(value)),(1.0/3.0)); //calculate cuberoot if non-positive value
	}//endif
}

int nChooseR (int valueN, int valueK) {
	double result=1,//answer
		i;//counter
	if (valueK>valueN) {
		return 0;//error checking if not possible to calculate
	} else {
		for (i=2; i<=valueN;i++) {
			//calculate answer for N!
			result=result*i;
		}
		for (i=2;i<=valueK;i++) {
			//calculate answer for 1/k!
			result = result/i;
		}
		for (i=2;i<=(valueN-valueK);i++) {
			//calculate answer for (n-k)!
			result=result/i;
		}
		return result; //return answer
	}
}

int getInt(int minimum, int maximum) {
	int value;	//input value
	cin >> value; //take in value
	for (;;) {
		if (value>maximum||value<minimum) { //check if value is within parameters
			cout << "Input must be an integer between " << minimum << " and " << maximum << " inclusive, try again!: ";
			cin >> value; //take in new one if it isn't
		} else {
			break;
		}
	}
	return value; //return allowable value
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
    	
    	//prompt user for starting value and check for parameter validity
		cout << "Enter start value (repeat previous valid number to exit): ";
    	startvalue = getInt(-999,999); //take in value and check if within parameters
    	if (startvalue>=900) {
    		rowlimit = 1000-startvalue;
    	} else {
    		rowlimit=100;
    	}
    	
    	//check to see if first time and also check for sentinel value
    	if (firstTime) {    		
			firstTime = false; //start to check for sentinel value after first time
    		sentinel = startvalue;    	
		} else if (startvalue == sentinel) {    	
			break; //break to finish program when sentinel value appears    	
		} //endif
		
    	//propt for number of rows to display in table and check for parameter validity
    	cout << "Enter number of rows (1 to " << rowlimit << "): ";
    	rows = getInt(1,rowlimit);//take in value and check if within parameters


    	//propmt user for decimal places to show for cuberoot and output error if needed
    	cout << "Enter number of decimal places (2 to 6): ";
    	decimals=getInt(2,6);  //take in value and check if within parameters
    		
    		
    	//display the headings for the columns in the table with their alloted space in the table
    	cout << setw(10) << "Value" << setw(15) << "ValueChoose3" << setw(15) << "Cube Root" << setw(15) << "Perfect Square" << endl;
    
    	//forloop to display values for each row in the table progressively
		for (; rows!=0; rows--) {
    	
    		//calculate the number of ways to get 3, cuberoot, and see if the value is a perfect square
    		number=nChooseR(startvalue,3);
    		cuberoot=cubeRoot(startvalue);    	
    		
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
