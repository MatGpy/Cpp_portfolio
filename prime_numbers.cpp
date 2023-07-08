//This program checks if number from the input is a prime number
#include <iostream>
#include <cmath>
using namespace std;
// program creates a function which checks if certain number is a prime number - it checks if this number can be divided by numbers between 2 and square root of this number
string check_if_prime(int x) {
    for(int i = 2; i <= sqrt(x);i++) {
        if(x % i == 0) {
            return(" isn't a prime number");
        }
    } return(" is a prime number");
}
int main() {
// program takes a number from user's input
    int number;
    cout << "insert a number: ";
    cin >> number;
// program checks if numer from user's input is 0 or 1 (these numbers aren't prime numbers) and if it isn't, program uses a function created previously to check if this number is a prime number
   if(number == 1 || number == 0) {
       cout << number << " isn't a prime number\n";
   } else {
       cout << number << check_if_prime(number) << "\n" << endl;
   }
    return 0;
}