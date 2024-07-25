/******************************************************************************
Given a string s consisting of words and spaces, return the length of the last word in the string.
*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "   fly me   to   the moon  ";
    
    bool x = false;
    string sum = ""; 
    
    if (s.size() == 1) return 1;
    
    for (int i = s.size() - 1; i >= 0; i--){

        if (s[i] != ' '){
            x = true;
        }
        
        if (x){
            if (s[i] == ' '){
                break;}
                else sum += s[i];
        }
    }
    cout << sum;
    return 0;
}