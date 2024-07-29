#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
 * */
int main(){
	
	string s = "PINALSIGYAHRPI"; //PINALSIGYAHRPI
	int numRows = 1;
	
	int count = 0;	
	bool isX = true;
	int count_pair = 1;	
	
	std::vector<std::pair<int, char>> paired;
	
	if(numRows == 1) return s;
	
	// тут кожній букві назначаю цифру ряду
	for (size_t i = 0; i < s.size(); i++){
		

		if (isX) count++; else count--;	
			
		if (count == numRows) isX = false; 
		if (count == 1) isX = true;
		
		
		paired.push_back({count, s[i]});
		}
		
	/*
	for (const auto& pair : paired) {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }	*/
	
	// std::sort(paired.begin(), paired.end()); ↓↓↓ сортує мені не так як треба тому ↓↓↓
	
	// по черзі виводжу буки з ряду 1, 2, 3...Xn
	Tekhnika_letyuchoho_Boga_gromu:
	 
    for (const auto& pair : paired) {
        if (pair.first == count_pair) {
            res.push_back(pair.second);
        }
    }
   
	if (count_pair <= numRows){
		count_pair++; 
		goto Tekhnika_letyuchoho_Boga_gromu;}
	
	
	return res;

	}
