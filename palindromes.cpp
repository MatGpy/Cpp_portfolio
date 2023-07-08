//This program checks if certain number/word is a palindrome
#include <iostream>
using namespace std;
//program creates a function which checks if certain number/word is a palindrome
string palindrom(string x) {
    int m = 0;
    int i = 0;
    int l = (x.size()-1);
    //function uses while loop to check if signs on opposite sides of analyzed string are identical
    while(x[i] == x[l-i]) {
        m = m+1;
        i = i+1;
        //program ends while loop if value of i is higher than length of analyzed strings
        if(i>l){
            break;
        }
    //function checks if value of m is equal to the length of analyzed string (value of m was increased by 1 every time when signs on opposite sides of the string were identical - while loop went through all length of analyzed string, so m is only equal to the length of this string if it's a palindrome)
    } if(m == l+1) {
        return(" is a palindrome\n");
    } else {
        return(" isn't a palindrome\n");
    }
}

int main() {
    string input;
    //program takes a number/word from the user's input and outputs the answer  
    cout << "type a number/word: \n";
    getline(cin, input);
    cout << input << palindrom(input) << endl;
    return 0;
}