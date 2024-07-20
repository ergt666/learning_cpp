#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{   
    vector<string> words = {"flower","flow","flight"};
	
	sort(words.begin(), words.end());

    for (const auto& word : words) {
        cout << word << " ";
    }
	
	
	string key_word = words[0];
	cout << key_word << endl;
	size_t x = 0;
	string result = "";
	
	for (size_t i = 0; i < key_word.length(); i++){
		
		char letter = key_word[i];
		cout << "Працюємо по букві: " << letter << "\n" << endl;
		
		for (size_t i = 1; i < words.size(); i++){
			
			string word = words[i];
			cout << "\nВитягуємо слово: " << word << endl;
		
			
			for (size_t j = x; j < word.length(); j++){
				
				char letter2 = word[j];
			
				cout << "Витягуємо з нього букву 3: " << letter2 << endl;
				
				
				if (letter == letter2) { cout << letter << " = " << letter2 << "\nЗійшлося!\n"<< endl;}
				else { cout << "No" << endl; goto exitLoops;}
				
				break;
				}			
			}		
			result += string (1, letter);
			x++;
		}
	
	exitLoops:
	cout << result << " <-- префікс";
	return 0;
}
