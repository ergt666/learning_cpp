#include <iostream>
#include <string>
#include <algorithm> 
#include <climits>
#include <limits>
using namespace std;


int main(){
	
	int x = 1534236469;
	string res = "";
	int i;
	long long j;
	
	if (x > INT_MAX || x < INT_MIN || x == 0){	
		cout << "За межами";
		return 0;
		} else {
			
			string str = to_string(x);
			int len = str.size();
				
			if ( str[len-1] == '0') str.pop_back();
				
			if (str[0] == '-'){
				res += '-';
				
				for(i = str.length() - 1; i >= 0; i--)res += str[i];
				res.pop_back();
				
				} else {
					for(i = str.length() - 1; i >= 0; i--)res += str[i];
					}
					
			j = stol(res);    
			if (j > numeric_limits<int>::max() || j < numeric_limits<int>::min()) { cout << j; return 0;} // Перевірка на переповнення
			
			}
	return j;
}

/*Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned)
Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21
.*/
