// "Lab 5: This program converts integers between 1 and 3999 into roman numerals
//
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

    int value; // input value
    int thousands,
    	hundreds,
    	tens,
    	ones,
    	remainder;
    
    //loop till sentinel value is entered
    while (value!=0) {
	cout << "Input value: ";//prompt for value to change to Roman numeral
    cin >> value ;
    
    	
    	if (value<0||value>=4000) { //make sure value is within limits
    		cout << "Invalid value ignored."; //error display if value is not inside limits
    	} else {
			// divide values into thousands, hundreds, tens, and ones to be seperately turned intp roman numerals later           
    		thousands = (value/1000);
    		remainder = (value%1000);
    		hundreds = (remainder/100);
    		remainder = (remainder%100);
    		tens = (remainder/10);
    		ones = (remainder%10);
    		
    		cout << value << " in Roman numerals is "; // start of output
    	
			// convert thousands into letters
   			while (thousands!=0) {
    			cout << "M";
    			thousands = thousands - 1;
    		} // endwhile
    		
    		// convert hundreds into leters
    		if (hundreds == 9) {
    			cout << "CM";
    		} else if (hundreds == 4) {
    			cout << "CD";
    		} else {
    			if (hundreds >= 5) {
    				cout << "D";
    				hundreds = hundreds - 5;
    			} //endif
    			while(hundreds!=0) {
    				cout << "C";
    				hundreds = hundreds -1;
    			} //endwhile    			
    		} //endif
    		
    		//convert tens into letters
    		if (tens == 9) {
    			cout << "XC";
    		} else if (tens == 4) {
    			cout << "XL";
    		} else {
    			if (tens >= 5) {
    				cout << "L";
    				tens = tens - 5;
    			} //endif
    			while(tens!=0) {
    				cout << "X";
    				tens = tens -1;
    			} //endwhile    			
    		} //endif
    		
    		//convert ones into letters
    		if (ones == 9) {
    			cout << "IX";
    		} else if (ones == 4) {
    			cout << "IV";
    		} else {
    			if (ones >= 5) {
    				cout << "V";
    				ones = ones - 5;
    			} //endif
    			while(ones!=0) {
    				cout << "I";
    				ones = ones -1;
    			} //endwhile							
    		} //endif
    		
    	} //endif
    	
    	cout << endl;
    	
    	} //endif
    
	system("PAUSE"); return 0;
		
} //endmain
