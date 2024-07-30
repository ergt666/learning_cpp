#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	
	string s = "macecar";
	string t = "qarrace";
	
	unordered_map<char,int> s_count;
	unordered_map<char,int> t_count;
	
	for (size_t i = 0; i < s.size(); i++){
		s_count[s[i]]++;
		t_count[t[i]]++;
	}
	
	for (size_t i = 0; i < s_count.size(); i++){
		if (s_count[i] != t_count[i]){
			cout << "false" << endl;
			break; // return false;
		}
		 
	}
	
	cout << "true"; // return true;
	return 0;
}
/*Is Anagram
Solved

Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Example 1:

Input: s = "racecar", t = "carrace"

Output: true

Example 2:

Input: s = "jar", t = "jam"

Output: false

Constraints:

    s and t consist of lowercase English letters.
*/
