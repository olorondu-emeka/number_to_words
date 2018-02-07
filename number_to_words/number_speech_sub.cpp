#include <iostream>
#include "number-speech.h"
#include <string>

using namespace std;
string one = "one", two = "two", three = "three", four = "four", five = "five";
string six = "six", seven = "seven", eight = "eight", nine = "nine";

string suffixDet(char num){
	string prefix;
		switch(num){
					case '1':
						prefix = one;
						break;
					case '2':
						prefix = two;
						break;
					case '3':
						prefix = three;
						break;
					case '4':
						prefix = four;
						break;
					case '5':
						prefix = five;
						break;
					case '6':
						prefix = six;
						break;
					case '7':
						prefix = seven;
						break;
					case '8':
						prefix = eight;
						break;
					case '9':
						prefix = nine;
						break;
					default:
						prefix = "";
						break;
				}	
		return prefix;
	}


string singleDigit(char num){
		string name;
		if(num == '0')
			name = "zero";
		else if(num == '1')
			name = "one";
		else if (num == '2')
			name = "two";
		else if (num == '3')
			name = "three";
		else if (num == '4')
			name = "four";
		else if(num == '5')
			name = "five";
		else if(num == '6')
			name = "six";
		else if (num == '7')
			name = "seven";
		else if (num == '8')
			name = "eight";
		else
			name = "nine";	

		return name;
	}


string twoDigitsSmall(char num1, char num2){
		string name, prefix, suffix;
		if(num1 == '1'){
				if(num2 == '0')
					name = "ten";
				else if(num2 == '1')
					name = "eleven";
				else if (num2 == '2')
					name = "twelve";
				else if (num2 == '3')
					name = "thirteen";
				else if (num2 == '4')
					name = "fourteen";
				else if(num2 == '5')
					name = "fifteen";
				else if(num2 == '6')
					name = "sixteen";
				else if (num2 == '7')
					name = "seventeen";
				else if (num2 == '8')
					name = "eighteen";
				else
					name = "nineteen";
			}
		return name;
	}


string twoDigitsBig(char num1, char num2){
	string prefix, suffix = "" , name;
		 if(num1 == '2')
			{
				prefix = "twenty";
				suffix = suffixDet(num2);
				name = prefix + " "	+ suffix;	
			}
		 if(num1 == '3')
			{
				prefix = "thirty";
				suffix = suffixDet(num2);
				name = prefix + " "	+ suffix;	
			}
		if(num1 == '4')
			{
				prefix = "fourty";
				suffix = suffixDet(num2);
				name = prefix + " "	+ suffix;	
			}
		if(num1 == '5')
			{
				prefix = "fifty";
				suffix = suffixDet(num2);
				name = prefix + " "	+ suffix;	
			}
		 if(num1 == '6')
			{
				prefix = "sixty";
				suffix = suffixDet(num2);
				name = prefix + " "	+ suffix;	
			}
		if(num1 == '7')
			{
				prefix = "seventy";
				suffix = suffixDet(num2);
				name = prefix + " "	+ suffix;	
			}
		if(num1 == '8')
			{
				prefix = "eighty";
				suffix = suffixDet(num2);
				name = prefix + " "	+ suffix;	
			}
		if(num1 == '9')
			{
				prefix = "ninety";
				suffix = suffixDet(num2);
				name = prefix + " " + suffix;	
			}
	
		return name;

	}


string threeDigits(char num1, char num2, char num3){
		string name, prefix, suffix;
		int numTest;
		char temp[2];
		temp[0] = num2;
		temp[1] = num3;
		numTest = atoi(temp);

		if((numTest >= 10) && numTest <= 19)
			suffix = twoDigitsSmall(num2, num3);
		else if((numTest >= 1) && numTest <= 9)
			suffix = suffixDet(num3);
		else
			suffix = twoDigitsBig(num2, num3);

		prefix = suffixDet(num1);
		if(num2 =='0' && num3 == '0')
			name = prefix + " hundred";
		else
			name = prefix + " hundred and " + suffix;
		

		return name;

	}


string fourDigits(char num1, char num2, char num3, char num4){
		string name, prefix, suffix;
		prefix = suffixDet(num1);
		suffix = threeDigits(num2, num3, num4);
		
		if(num2 =='0' && num3 == '0' && num4 == '0')
			name = prefix + " thousand";
		else if((num2 == '0' && num3 == '0') || (num2 == '0')){
				int numTest;
				char temp[2];
				temp[0] = num3;
				temp[1] = num4;
				numTest = atoi(temp);
				
				if(numTest >= 1 && numTest < 10)
					suffix = suffixDet(num4);
				else if(numTest >= 10 && numTest <= 19)
					suffix = twoDigitsSmall(num3, num4);
				else
					suffix = twoDigitsBig(num3, num4);
				name = prefix + " thousand and " + suffix;
			}
			
		else
			name = prefix + " thousand, " + suffix;
		return name;
	}

string fiveDigits(char num1, char num2, char num3, char num4, char num5){
		string name, prefix, suffix;
		int numTest;
		char temp[2];
		temp[0] = num1;
		temp[1] = num2;
		numTest = atoi(temp);

		if(numTest > 19)
			prefix = twoDigitsBig(num1, num2);
		else
			prefix = twoDigitsSmall(num1, num2);

		suffix = threeDigits(num3, num4, num5);

		if(num2 =='0' && num3 == '0' && num4 == '0' && num5 == '0')
			name = prefix + " thousand";
		else if((num2 == '0' && num3 == '0' && num4 == '0') || (num2 == '0' && num3 == '0')){
				int numTest2;
				char temp2[2];
				temp[0] = num4;
				temp[1] = num5;
				numTest2 = atoi(temp2);
				
				if(numTest2 >= 1 && numTest2 < 10)
					suffix = suffixDet(num5);
				else if(numTest2 >= 10 && numTest2 <= 19)
					suffix = twoDigitsSmall(num4, num5);
				else
					suffix = twoDigitsBig(num4, num5);

				name = prefix + " thousand and " + suffix;
			}
		else
			name = prefix + " thousand, " + suffix;
		return name;
	}