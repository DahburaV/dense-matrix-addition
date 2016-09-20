//----------------------------------------------------- //
//		COSC 2430 - HW1							 		//
//		by Viktor Dahbura								//
//		PS: 1230508										//
//      Submitted: 08/31/2016							//
//------------------------------------------------------//	
													
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

int main(void) {
	
	//VARIABLE DECLARATIONS
	
	ifstream inStream;
	ofstream outStream;
	int const MAX_ROW = 20;
	int const MAX_COL = 20;
	int n = 0;
	int count = 0;
	int size = sqrt(count);
	int meh = 0;
	string line;
	float numSum = 0;
	float array[MAX_ROW][MAX_COL];
	float copyArray[MAX_ROW][MAX_COL];
	float multArray[MAX_ROW][MAX_COL];
	float num[400];
		
	//OPENING .txt FILES AND CHECKING FOR LOADING ERRORS
	
	inStream.open("A.txt");
	if(inStream.fail()) {
		cout <<"File A.txt does not exist. Terminating program.";
		return 0;
	}
	
	outStream.open("C.txt");
	if(outStream.fail()) {
		cout <<"Output file C.txt does not exist. Terminating program.";
		return 0;
	}
	
	//SETTING num[] MATRIX TO = 0
	
	for(int i = 0; i < 400; i++) {
		num[i] = 0;
	}
	
	//ADDING NUMBERS TO THE DATA ARRAY, count IS THE TOTAL NUMBER OF FLOATS IN ARRAY
		
	while (getline(inStream, line)) {
        if(line[0] != '#' || line.length()!=0) {
            istringstream fn(line);
            while(fn >> num[count]) { 
				count++;
			}
        }
        else if(line[0] == '#' || line.length()==0) {
            	while (line[0] == '#' || line.length()== 0) {
					break;
				}
		}
    }
    
    //ERROR MSG: NO DATA
    
    for(int i = 0; i < 400; i++) {
    	numSum = numSum + num[i];
	}
	if(numSum == 0) {
		cout << "CRITICAL ERROR: no data in the matrix!" << endl;
		return 0;
	}
	
	
	//DISPLAY THE ABOVE CODE ON CONSOLE (TEMPORARY, FOR TESTING)
	
	cout << count << " <- count" << endl;
	cout << num[0] << endl;
	if(sqrt(count) != floor(sqrt(count)) || count == 1) {
		return 0;
	}

	//ADDING THE DATA FROM DATA ARRAY INTO THE n x n MATRIX
	//I TOOK THE SQUARE ROOT OF count TO GET THE DIMENSIONS OF THE ARRAY
	
	for(int i = 0; i < MAX_ROW && i < sqrt(count); i++) {
		for(int j = 0; j < MAX_COL && j < sqrt(count); j++) {
			array[i][j] = num[n];
			n++;
		}
	}
	
	//DISPLAY THE ABOVE CODE ON CONSOLE (TEMPORARY, FOR TESTING)
	
	cout << array[0][0] << endl;
	
	//COPYING array DATA INTO copyArray TO LATER DO: (array)*(copyArray) = multArray
	
	for(int i = 0; i < MAX_ROW && i < sqrt(count); i++ ) {
		for(int j = 0; j < MAX_COL && j < sqrt(count); j++) {
			copyArray[i][j] = array[i][j];
		}
	}
	
	//DISPLAY THE ABOVE CODE ON CONSOLE (TEMPORARY, FOR TESTING)
	
	cout << copyArray[0][0] << endl;
	
	//SETTING multArray TO VALUES OF 0
	
	for(int i = 0; i < MAX_ROW && i < sqrt(count); i++ ) {
		for(int j = 0; j < MAX_COL && j < sqrt(count); j++) {
			multArray[i][j] = 0;
		}
	}

	//DISPLAY THE ABOVE CODE ON CONSOLE (TEMPORARY, FOR TESTING)
	
	cout << multArray[0][0] << endl;
	
	//MATRIX MULTIPLICATION OF (array)*(copyArray) TO GO INTO multArray

	for(int i = 0; i < MAX_ROW && i < sqrt(count); i++ ) {
		for(int j = 0; j < MAX_COL && j < sqrt(count); j++) {
			for(int k = 0; k < MAX_COL && k < sqrt(count); k++) {
				multArray[i][j] += array[i][k] * copyArray[k][j];
			}
		}
	}
	
	//DISPLAY THE ABOVE CODE ON CONSOLE (TEMPORARY, FOR TESTING)
	
	for(int i = 0; i < MAX_ROW && i < sqrt(count); i++ ) {
		for(int j = 0; j < MAX_COL && j < sqrt(count); j++) {
			cout << multArray[i][j] << ' '; 
			if(j == sqrt(count) - 1) {
				cout << endl;
			}
		}
	}

	//SETTING PRECISION TO 2 DECIMAL SPACES 

	outStream.setf(ios::fixed);
	outStream.setf(ios::showpoint);
	outStream.precision(2);

	//SENDING multArray TO OUTPUT .txt FILE
	
	for(int i = 0; i < MAX_ROW && i < sqrt(count); i++ ) {
		for(int j = 0; j < MAX_COL && j < sqrt(count); j++) {
			outStream << multArray[i][j] << ' '; 
			if(j == sqrt(count) - 1) {
				outStream << endl;
			}
		}
	}
			
	inStream.close();
	outStream.close();
	
	return 0;
}

