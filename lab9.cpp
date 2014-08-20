// Lab 9 this program outputs a table with the pressure drop across different pipe diameters
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

// This function calculates and returns the friction factor using
// successive approximations to an accuracy of 0.000001.  
// The parameters are:
// R - Reynolds number
// D - diameter (in metres)
// epsilon - roughness (in metres)
double calcFrictionFactor(double R, double D, double epsilon) {
	
    const double BlasiusCoefficient = 0.3164;
    double f_old, f_new;

    f_new =  BlasiusCoefficient * pow(R, -0.25);

	// loop until our two values are within 0.000001 of each other
    do {
		  f_old = f_new; // previous guess is now the old one
		  
	      // plug guess into the right hand side of the ColeBrook formula
	      f_new = 0.25 * pow(log10((epsilon/D)/3.7 + 2.51 / (R*sqrt(f_old))), -2);

    } while (fabs(f_new - f_old) > 0.000001);

    return f_new;
}

//program to calculate reynolds number
//rho - fluid density (in kg/m^3)
//V - fluid velocity (in metres per second)
//D - pipe diameter (metres)
//mu is the viscosity of the fluid (in Newton seconds per square metre). 
double calcReynolds (double rho, double V, double D, double mu) {
	double R;//reynolds number
	R = rho*V*D/mu;//calculate reynolds number
	return R;//return reynolds number
}

//program to calculate the drop in pressure
//f - friction factor
//L - distance between two points (metres)
//D - pipe diameter (metres)
//rho - fluid density (in kg/m^3)
//V - fluid velocity (metres per second)
double calcPressureLoss(double V, double L, double D, double rho, double mu, double epsilon) {
	double pressureloss, //drop in pressure
		R,//reynolds number
		f;//friction factor
	
	R = calcReynolds(rho,V,D,mu); //calculate reynolds number
	f = calcFrictionFactor(R,D,epsilon); // calculate friction factor
	
	pressureloss = f*L*rho*pow(V,2)/D/2; //calculate drop in pressure
	
	if (R>=3500) { //error check for reynolds number if too low
		return pressureloss; //reynolds number high enough, return drop i pressure
	} else {
		return -1; //reynold number is too low, output -1 error
	}//endif
	
}

//program to output a table for the drops in pressure of different pipe diameters
//V - fluid velocity (in metres per second)
//L - distance between two points (metres)
//rho - fluid density (in kg/m^3)
//mu is the viscosity of the fluid (in Newton seconds per square metre). 
//epsilon - pipe roughness
void printTable(double V, double L, double rho, double mu, double epsilon) {
	
	double x,//pipe diameter
		pressureloss; //drop in pressure
	
	int i;//counter to calculate pipe diameter
	
	//output headings
	cout << setw(15) << "Diameter (m)" << setw(25) << "Pressure Drop (Pa)" << endl << setw(44) << setfill('-') << "-" << endl;
	
	//loop to create tables until sentinel values are inputed
	for (i=0;i<15;i++) {
		
		x=(i+1)*0.05;//calculate diameter of pipe
		pressureloss= calcPressureLoss(V,L,x,rho,mu,epsilon);//calculate pressure drop across pipe
		//output pipe diameter and formatting
		cout << setw(8) << setfill(' ') << " " << setw(4) << fixed << setprecision(2) << x << setw(24) << setfill(' ');
		//check if pressure drop can be calculated
		if (pressureloss==-1) {//pressure drop can't be calculated
			cout << "********" << endl;//output star because of error
		} else {//pressure drop can be calculated
			cout << setprecision(1) << pressureloss << endl;//output pressure drop
		}//endif
		
	}//endfor
	
}



int main (void) {
	
	const double rho=998.2, //rho - fluid density (in kg/m^3)
		mu=1.002e-3,//mu is the viscosity of the fluid (in Newton seconds per square metre). 
		epsilon=4.5e-5;// epsilon - roughness (in metres)

    double V, //fluid velocity in metres per second
    	L; //distance between two points in the pipe in metres
    
    for (;;) {//loop till sentinel values are given
    	
    	cout << "Enter flow velocity and distance (-1 -1 to terminate): "; //prompt user for inputs
		cin >> V >> L; //input data
		
		if (V!=-1&&L!=-1) { //check for sentinel values
			if (V>0&&L>0) { //check for valid data
				printTable(V,L,rho,mu,epsilon); //calculate pressure drop and create table
				cout << endl;//endline
			} else {
				cout << "Invalid date ignored." << endl; //tell user data is invalid			
			}//endif
		} else {
			break; //finish program when sentinel values appear
		}//endif
	
	}//endwhile
	
	
	
	/*
	//check if calcReynolds function works
	while (rho!=0 && V!=0 && D!=0 && mu!=0) { //loop till sentinel values are inputed
	
		cout << "Enter values for rho, V, D, and mu (0 0 0 0 is entered): "; //prompt user for inputs
		cin >>  rho >> V >> D >> mu; //inout values
		cout << calcReynolds (rho,V,D,mu) << endl; //calculate and output reynolds number result
		
	}//endwhile*/
	
	/*
	// check if calcPressureLoss function works
	while (rho!=0 && V!=0 && D!=0 && mu!=0) { //loop till sentinel values are inputed
	
		cout << "Enter values for V, L, D, rho, mu and epsilon (0 0 0 0 0 0 to exit): "; //prompt user for input values
		cin >>  V >> L >> D >> rho >> mu >> epsilon; //inpur values
		
		cout << calcPressureLoss(V,L,D,rho,mu,epsilon) << endl; //calculate and output pressure drop
		
	}//endwhile*/  

    system("PAUSE"); return 0;

}
