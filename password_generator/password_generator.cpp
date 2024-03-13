#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int takeAmountOfCharacters(int amountOfCharacters) {
    cout << "How many characters do you want your password to have? (type a positive number): \n";
    cin >> amountOfCharacters;
    if(amountOfCharacters <= 0 || amountOfCharacters > 100) {
        throw(amountOfCharacters);
    }
    return amountOfCharacters;
}
char generateChar() {
    int charNumber = rand()%123;
    while(charNumber < 33 || charNumber > 57 && charNumber < 65 || charNumber > 90 && charNumber < 97) {
        charNumber = rand()%123;
    }
    return char(charNumber);
}
int main() {
    srand(time(0));
    try {
        int amountOfCharacters = takeAmountOfCharacters(amountOfCharacters);
        string passwordChars = "";
        for(int i=0; i < amountOfCharacters; i++) {
            passwordChars += generateChar();
        }
        cout << "\nHere's your password: " << passwordChars << endl;
    }
    catch(int errorNumber) {
        cout << "Error";
    }
}