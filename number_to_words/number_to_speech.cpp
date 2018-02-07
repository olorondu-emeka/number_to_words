#include <iostream>
#include "number-speech.h"
#include <string>

using namespace std;

int main(){
	  char numbers[6];
	   int tracker, doubleNumTest;
	  string words;
	
	//get input from user in string format(character array)
	cout << "Enter numbers: ";
	cin >> numbers;

	//convert string input to an integer
	doubleNumTest = atoi(numbers);
	
	//get the number of digits the user entered
	for(int i = 0; i < 6; i++){
			if (numbers[i] == '\0')
				tracker = i;
		}
	
	//interprete the result based on the number of digits the user entered
	if(tracker == 1)
		words = singleDigit(numbers[0]);

	if(tracker == 2){
			if(doubleNumTest > 19)
				words = twoDigitsBig(numbers[0], numbers[1]);
			else
				words = twoDigitsSmall(numbers[0], numbers[1]);	
		}

	if(tracker == 3)
		words = threeDigits(numbers[0], numbers[1], numbers[2]);
	if(tracker == 4)
		words = fourDigits(numbers[0], numbers[1], numbers[2], numbers[3]);
	if(tracker == 5)
		words = fiveDigits(numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
	
	cout << "\nIn words: " << words << endl;

	system("pause");	
}


