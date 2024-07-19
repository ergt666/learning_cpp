#include <algorithm> 
#include <iostream>
#include <string>

using namespace std; 

int main()
{
	string Rnum = "MCMXCV";
	char I = 'I', X = 'X', V = 'V', L = 'L', C = 'C', D = 'D', M = 'M';	
	string x = "";
	bool click = false;
	int res = 0;
	
	cout << "Конвертер чисел з римьких на арабські" << endl;
	cout << "Римські: "<< Rnum << endl;
	
	for (char letter : Rnum) {
		
		if (click) {
			
			// тут (перший символ + другий) і шукаємо серед них чи є збіг 
			x += letter;	
			if (x == "IV" || x == "IX") res -= 2;
			if (x == "XL" || x == "XC") res -= 20;
			if (x == "CD" || x == "CM") res -= 200;
			
			x = ""; // очистити
			click = false;
			}
		
		if (letter == I || letter == X || letter == C) {
			// якщо попадається I, X або С то ми його записуєм і вмикаємо 2-гу перевірку
			x += letter;
			click = true;			
			}		
		if (letter == I) res += 1;
		if (letter == V) res += 5;
		if (letter == X) res += 10;
		if (letter == L) res += 50;
		if (letter == C) res += 100;		
		if (letter == D) res += 500;
		if (letter == M) res += 1000;		
	}
	cout << "Арабські: "<< res << endl;
	return 0;
	
}
