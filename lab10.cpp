//Glenn Paul B. SUmido 100933901
//function to input, output and solve polynomials and its derivative


#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;


// Complete function readPolynomial below.
//
// This function starts by asking the user for the order of the polynomial.  
// If the order entered is not between 1 and maxOrder, it will continue to ask 
// for the order, until a valid order is obtained.
// Then it asks the user for the coefficient for the order (which cannot be 0),
// followed by the coefficient for each power of x, down to 0.
// It puts the coefficients in the polynomial array and returns the order
// of the polynomial.
int readPolynomial (int maxOrder, double polynomial[]) {
	
	int order, //order of the polynomial
		i; //counter
	
	cout << "Enter order of polynomial: "; //propmt for input
    cin >> order; //takr in input for order
    if (order>maxOrder||order<1) { //check if within parameters
    	for (;;) {
    		if (order<=maxOrder&&order>1) {
    			break;
    		}
        	cout << "The value of the polynomial must be >=1 and <=8." << endl << "Enter order of polynomial: "; //ask for new of not valid
        	cin >> order;
    	}
	}
	
	for (i=order;i>=0;i--) { //prompt for and input coefficients
        cout << "Enter coefficient for x^" << i << ": ";
        cin >> polynomial[i];
        if (i==order&&polynomial[i]==0) { //error check forst coefficient
            cout << "The first coefficient cannot be zero.";
        }
    }
    return order; //return the order of the polynomial
}


// Complete function displayPolynomial below.
//
// This function outputs the polynomial of order n in a nice format (as per
// the sample executable).
void displayPolynomial (int order, double polynomial[]) {
	int i;//counter
	
	for (i=order;i>=0;i--) {
    	if (polynomial[i]!=0) {//check if coefficient is positive 
    		if (i==1) {
    			if (i==order) {
    				cout << polynomial[i]; //if first part of polynomial, the sign is needed
    			} else {
    				cout << fabs(polynomial[i]); //if not first part of polynomial, sign is not needed	
    			}
				cout << "x ";//if first order part of polynomial, only output x
    			if ((polynomial[i-1])>0&&i!=0) {
            		cout << "+ "; //add a plus if next part of polynomial is positive
            	} else if (polynomial[i-1]<0&&i!=0){
            		cout << "- "; //add negative if next part of polynomial is negative
            	}
    		} else {
            	if (i==order) {
    				cout << polynomial[i];//if first part of polynomial, the sign is needed
    			} else {
    				cout << fabs(polynomial[i]); //if not first part of polynomial, sign is not needed	
    			}
    			if (i!=0) {//check if final part of polynomial to see if order is needed
					cout << "x^" << i << " "; //if not 0th or 1st order part of polynomial, indivate whichth part
            		if ((polynomial[i-1])>0&&i!=0) {
            			cout << "+ ";//add a plus if next part of polynomial is positive
            		} else if (polynomial[i-1]<0&&i!=0){
            			cout << "- ";//add a plus if next part of polynomial is positive
            		}
            	}
            }
        } else {
            if ((polynomial[i-1])>0&&i!=0) {
            	cout << "+ ";//add a plus if next part of polynomial is positive
            } else if (polynomial[i-1]<0&&i!=0){
            	cout << "- ";//add a plus if next part of polynomial is positive
            }        	
        }
	}
	cout << endl;//insert space
	return;
}

double evaluatePolynomial (int order, double polynomial[], double x) {
	
	int answer=0, //answer to polynomial at x
		i; //counter
	
	for (i=order;i>=0;i--) {
		answer+=pow(x,i)*polynomial[i]; //calculat each part of polynomial a x
	}
	return answer; //return answer
}

int differentiate (int order, double polynomial[], double derivative[]) {
	int i; //counter
	
	for(i=order;i>0;i--) {
		derivative[i-1]=polynomial[i]*i; //calculate derivative of each part of the polynomial
	}
	return order-1;	//return order of derivative
}

int main () {

	const int MAXN = 8; // maximum order (a constant)
	double polynomial[MAXN + 1], //polynomial array
		derivative[MAXN+1], //derivative array
		x; //input value into polynomials to solve for answer
	int polynomialN, //order of polynomial
		D=-1; //order of derivative

	// read in the polynomial
	polynomialN = readPolynomial (MAXN, polynomial);

	// output message
	cout << "\nThe polynomial (order = " << polynomialN << ") is\n";
	// followed by the polynomial
	displayPolynomial (polynomialN, polynomial);

	cout << endl; //output space
	
	for (;;) {
		cout << "Enter x (zero to terminate): "; //propt for input x
		cin >> x; //input x
		if (x==0) { //if zero, calculate derivative
			cout << endl; //output space
			D=differentiate(polynomialN,polynomial,derivative); //calculate derivative order and derivative coefficients
			cout << "The derivative (order = " << D << ") is" << endl; //output derivative order
			displayPolynomial (D,derivative); //display derivative
			cout << endl; //output space
			for (;;) {
				cout << "Enter x (zero to terminate): "; //prompt for x
				cin >> x; //input x
				if (x==0) {
					break; //finish when sentinel value entered
				}
				cout << "The value of the derivative at x = " << x << " is " << evaluatePolynomial(D,derivative,x) << endl;	//evaluate derivative at x and output answer	
			}
		}
		if (D==-1) { //check if derivative has been evaluated yet
			cout << "The value of the polynomial at x = " << x << " is " << evaluatePolynomial(polynomialN,polynomial,x) << endl; //evaluate polynomial at x and output answer
		} else { //derivative has already been calculated, finish program
			break;
		}
	}
	
	system("PAUSE"); return 0;

}
