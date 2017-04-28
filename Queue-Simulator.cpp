// ConsoleApplication7.cpp : Defines the entry point for the console application.
//
//March 27, 2017
//Lucas Kellner
//MSE 410
//Instructor: Dr. Ding
//Mon-Wed 3:25-5:30
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;

// function declarations
int scale(int[], int);
int readFile(string, char);
int processFile();
int getNInput();
bool askAboutScaling();
int* getNUserInputs(int[], int, int, int, string);
int sumArray(int[], int);
int calculateValues(int[], int[], int);
int writeToFile(int[], int[], int[], double[], int[], int);
int manualEntry();
int autoEntry();
int mainMenu();


int scale(int inputArr[], int scaleType) {
	int scaledValue = 0;
	if (scaleType == 1) {
		// constant scaling factor
		getScaleFactor();
		// do the scaling


	}
	else if (scaleType == 2) {
		// discrete values
		getDiscreteValues();
		// do the scaling



	}
	else {
		// something is wrong
		goto endoffunc;
	}
	
	
endoffunc:
	return scaledValue;
	}





int readFile(string nameOfFile, char delimitingChar) {

	return 0;
}

int processFile() {

	return 0;
}

int getNInput() {
	int N;
enterN:
	cout << "Enter a value for N: ";
	cin >> N;
	// check to see if the user input a valid value type
	if (!std::cin || N < 0) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		goto badInput;
	}
	return N;
badInput:
	cout << "Please enter a positive integer for N" << endl;

}

int getScaleFactor() {
	double scalingFactor;
	std::cout << "Enter the scaling factor to divide by: ";
	std::cin >> scalingFactor;
	// need some error checking here
	return scalingFactor;
}

int getScaleType() {
	int scaleType;
	std::cout << "Scale by (1) a constant factor or (2) two discrete values? (1/2): ";
inputScaleType:
	std::cin >> scaleType;
	if (!scaleType == 1 && !scaleType == 2) {	
		cout << "Please make a valid selection: ";
		goto inputScaleType;
	}
	return scaleType;
}

int getDiscreteValues() {
	int i;
	struct binaryReturn {
		int discrete[21];
		int upperBound[21];
	};
	pair <int[], int[]> discreteValueParams(discrete[], upperBound[]);


	int quantityDiscreteValues;
	std::cout << "How many discrete values?: ";
	std::cin >> quantityDiscreteValues;
	for (i = 1; i <= quantityDiscreteValues; i++) {
		cout << "Enter discrete value number " << i << ": ";
		cin >> discrete[i];
		cout << "Enter the time below which to convert to this discrete value: ";
		cin >> upperBound[i];
	}
}

bool askAboutScaling() {
	std::string needsScaling;
	bool willScale;
	std::cout << "Do the A values need to be scaled? (Y/N): " << std::endl;
inputNeedsScaling:
	std::getline(std::cin, needsScaling);
	if (needsScaling == "Y") {
		willScale = true;
	}
	else if (needsScaling == "N") {
		willScale = false;
	}
	else {
		std::cout << "Please enter either Y or N: ";
		goto inputNeedsScaling;
	}
	return willScale;
}

int* getNUserInputs(int arr[], int N, int minVal, int maxVal, string inputID) {
	int i;
	if (askAboutScaling() == true) {
		for (i = 1; i <= N; i++) {
			scale(arr[i], getScaleType(), getDiscreteValues());
		}
	}

	for (i = 1; i <= N; i++) {
	input:
		std::cout << "Input the " << inputID << " number" << i << ": ";
		std::cin >> arr[i];
		// check to see if the user input a valid value type
		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			goto badInput;
		}
		if (arr[i] <= maxVal && arr[i] >= minVal) {
			// good input			
		}
		else {
			goto badInput;
		}
	}
	return 0;
badInput:
	std::cout << "***** Please enter a " << inputID << " that is between " << minVal << " and " << maxVal << " *****" << std::endl;
	goto input;
}

int sumArray(int arr[], int N) {
	int i;
	int arraySum = 0;
	for (i = 1; i <= N; i++) {
		arraySum += arr[i];
	}
	return arraySum;
}


int calculateValues(int arrA[], int arrS[], int N) {
	int W[21];
	W[0] = 0;
	double Wavg[21];
	Wavg[0] = 0;
	int D[21];
	D[0] = 0;
	D[1] = 0;
	int i;

	// calculate waits
	W[1] = arrS[1];
	Wavg[1] = arrS[1];
	double Wsum = 0;
	Wsum += W[1];
	for (i = 2; i <= N; i++) {
		// calculate values of d
		if (W[i - 1] - arrA[i] >= 0) {
			D[i] = W[i - 1] - arrA[i];
		}
		else {
			D[i] = 0;
		}
		W[i] = D[i] + arrS[i];
		// calculate average wait times
		Wsum += W[i];
		Wavg[i] = Wsum / i;
	}

	return 0;
}


int writeToFile(int arrA[], int arrS[], int arrW[], double arrWavg[], int arrD[], int N) {
	int i;
	string fileName;
	cout << "Enter a file name: ";
	cin >> fileName;
	std::ofstream fout(fileName);
	if (fout.is_open()) {
		fout.precision(2);
		// print interarrival time, processing times, W and Wavg
		fout << "Part number\tA\tS\tW\tW(Average)" << std::endl;
		for (i = 1; i <= N; i++) {
			fout << "\t" << i << "\t" << arrA[i] << "\t" << arrS[i] << "\t" << arrW[i] << "\t " << arrWavg[i] << std::endl;
		}
	}
	fout.close();
	return 0;
}

int manualEntry() {
	int N;
	N = getNInput();
	int a[21];
	int *A;
	A = getNUserInputs(a, N, 0, 99, "Interarrival Time");
	int s[21];
	int *S;
	S = getNUserInputs(s, N, 0, 99, "Service Time");
	




	return 0;
}

int autoEntry() {
	// get N from first line

	// get As from second line

	// get Ss from third line

	// append to that file? or create a new file?

	return 0;
}

int mainMenu() {
	std::cout << "/========================================================\\" << std::endl;
	std::cout << "|             Queue Simulator 3000 v0.01                 |" << std::endl;
	std::cout << "X========================================================X" << std::endl;
	std::cout << "|  Options:                                              |" << std::endl;
	std::cout << "|  1. Manually Enter Interarrival and Service Times      |" << std::endl;
	std::cout << "|  2. Select a File of Interarrival and Service Times    |" << std::endl;
	std::cout << "|  3. Quit                                               |" << std::endl;
	std::cout << "|                                                        |" << std::endl;
	std::cout << "\\========================================================/" << std::endl << std::endl;
MenuInput:
	std::cout << "Select option:  ";
	int selection = 0;
	std::cin >> selection;
	switch (selection) {
	case 1:
		manualEntry();
		break;
	case 2:
		autoEntry();
		break;
	case 3:

		break;
	default:
		goto badMenuInput;

	}
	return 0;
badMenuInput:
	cout << "Please make a valid menu selection" << endl;
	goto MenuInput;
}
int main() {
	mainMenu();
	return 0;	
}

// "Made with <3 by Lucas Kellner" << endl;
// "Student Id: 106425642" << endl;
