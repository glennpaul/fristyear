// Program to arrange dates in number of occunrances
//
// Name: Glenn Paul B. Sumido
// Student Number: 100933901

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

void swap (int &v1, int &v2) {
 int temp; 
 temp = v1; v1 = v2; v2 = temp; 
} 

int main (void) {

	int day[100], //array for days that appears on list
		occurances[100], //array number of times a day occurs in list
		value, //day that appears on list
		count, //count for countdowns
		stop, //when to stop search to increase efficiency
		j, //used for countdowns
		total=0; //total number of valid dates inputed
		
	char input[60], output[60]; //declares space for names of files
				
	ifstream fin; //declares input file object
	ofstream fout; //dfeclares output file object
	
	bool first=true, //first time in loop
		swapped; //whether or not a swap occured in loop
		
	cout << "Enter name of input file: "; //prompt for input file name
	cin >> input; //input name
	cout << "Enter name of output file: "; //prompt for output file name
	cin >> output; //input name
	
	fin.open (input); //open file
	if (fin.fail()) { //error check if file couldn't be opened
		
		cout << "Unable to open " << output << " file.\n"; //tell user file couldn't be opened
		system("PAUSE"); return 0; //finish program
		
	}
	
	fout.open (output); //make an output file
    if (fout.fail()) { //if output file could not be made...
    	cout << "Unable to open the output file.\n"; //tell user output file couldn't be made
    	system("PAUSE");return 0; //stop program
    }
	
	for (;;) {
		
		if (fin.eof()) {
			break; //finish reading file when end of file
		}
		
		fin >> value; //input from file		
		while (fin.fail()) { //error check if inputing a value from file failed
			cout << "Unrecognizable day number ignored.\n"; //tell user a garbage value was ignored
			fin.clear(); //delete the garbage value
			fin.ignore(101,'\n'); //ignore values until next line comes
			fin >> value; //input new value
		}
		while ((value>366)||(value<1)) { //see if value is within the desired range
			cout << "Invalid day number (" << value << ") ignored.\n"; //tell user valyue was not within range
			fin.clear(); //delete ignored value
			fin.ignore(101,'\n'); //ignore values till next line
			fin >> value; //input new value
		}		
		
		if (first) { //if first value entered
			
			day[total]=value; //enter value into first slot
			occurances[total]=1; //first occurance for this day
			first=false; //tell program it is done with first entry
			
		} else {
			
			for (count=total-1;count>=0;count--) { //keep reading values
				
				if (value==day[count]) {
					occurances[count]++; //if the value has apeared already increase occurance count
				} else {//if first time for that value
					day[total]=value; //input that day into new slot
					occurances[total]=1; //input the occurance for that day as one
				}
				
			}
			
		}	
		total++; //increase total count
				
	}

    stop = total - 1; // on the first pass "i" must be < "n - 1"
    do {
    	
        // make a pass
        swapped = false; // no interchanges so far on this pass
        for (count = 0; count < stop; count++) { //keep going around values intil all values are sorted
        	
            if ((occurances[count])<(occurances[count+1])) { //if the day has more occurances than the next day in the list
				
				swap(day[count],day[count+1]);//swap days
				swap(occurances[count],occurances[count+1]);//swap number of occurances
				swapped=true; //tell a swap occured in this loop
			}
			
        }
        stop--; // on the next pass, stop one comparison sooner
        
    } while (swapped); //stop when no more swaps occur
    
    fout << endl << setw(12) << "Day of Year" << setw(10) << "Events" << setw(13) << "%Events\n"; //output headings for file
	fout << "-------------------------------------\n"; //create first line under headings
	for (count=0;count<total;count++) { 
		
		if (first==false) { //check if first value in list (swapped because same variable is used earlier which is already at false)
			
			fout << setw(10) << day[count] << setw(10) << occurances[count] << setw(12) << setprecision(3) << (occurances[count]/(total*1.0))*100 << endl;	 //output statistics		
			first=true; //change to true which will tell program it isn't first value anymore
			
		} else {
			
			for (j=count-1;j>=0;j--) { //check already printed list for a previous instance of the date (there are multiples of the same day with different instanceds
				
				if (day[count]==day[j]) { //if the same day as a previous day, skip to next day output
					break;
				} else if (j==0) { //if the last check and there are no previous instances of the day
					fout << setw(10) << day[count] << setw(10) << occurances[count] << setw(12) << setprecision(3) << (occurances[count]/(total*1.0))*100 << endl; //output statistics
				}
				
			}
			
		}
		
	}
	
	cout << "\nThe results have been written to the output file.\n"; //tell user file with statistics has been created successfully
	system("PAUSE"); return 0;//finish program
		
}
