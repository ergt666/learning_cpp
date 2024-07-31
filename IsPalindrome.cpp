#include <iostream>
#include <string>

using namespace std;

int main(){
											   
	string s = "Was it a car or a cat I saw?"; 

	string s2;
	int distance;
	
	//if (s.size() == 1) return true;
	
	for (size_t i = 0; i < s.size(); i++){
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z')){
			s2.push_back(toupper(s[i]));
		}
	}
	cout << s2 << endl;
	
	if (s2.size() % 2){		
		distance = (s2.size() / 2) + 1;
	} else {
		distance = (s2.size() / 2);
	}

	for (int i = 0, j = s2.size() - 1; j >= distance; j--, i++){

		if (s2[j] != s2[i]){
			cout << "false" << endl;
			//return false;		
		}
	}
	cout << "true";
	//return true;
}


/*Given a string s, return true if it is a palindrome, otherwise return false.

A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.

Example 1:

Input: s = "Was it a car or a cat I saw?"

Output: true
*/














/*char letter;
	int x, y;
	
	for (letter = 'A'; letter <= 'Z'; letter++) cout << letter;
	
	string s2;
	string s3;

	for (size_t i = 0; i < s.size(); ++i){
        if (isalpha(s[i])){
			s2 += toupper(s[i]); 
		}  
    }
    
    for (int i = s2.size() - 1; i >= 0; i--) s3 += s2[i];
		
	
	cout << s2 << endl;
	cout << s3 << endl;	
    
	if (s2 == s3){
		cout << "true";
	} else {
		cout << "false";
	}
	
	
	
	*/
