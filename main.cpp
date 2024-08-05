#include <iostream>
#include <vector>


using namespace std;

int main()
{
    vector<int> digits = {9,9};
    int count = 0; 
    
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] == 9) {
            digits[i] = 0;
            count++;
        } else {
            digits[i]++;
            break;
        }
        if (i == 0) {
            digits.insert(digits.begin(), 1);
        }
        
    }
    
    for (const auto& i : digits) {
        std::cout << i << std::endl;
    }
    
    return 0;
}