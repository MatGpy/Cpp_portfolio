/*
Number-guessing game - player has to guess a randomly generated number between 1 and 10 in amount of attempts specified by chosen level of difficulty
1. choose level of difficulty
2. specify if you want or don't want to get a hint about generated number
3. try to guess that number before you'll run out of attempts
*/
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;
// program creates a function which checks if number from the user's input is correct, too low or too high
string guess(int x, int y) {
    if(x == y) {
        return "correct answer";
    } else {
        if(x < y) {
            return("your guess is too low");
        } if(x > y) {
            return("your guess is too high");
        }
    }
}
int main() {
    srand(time(0));
    // program randomly generates three numbers - number that has to be guessed and two other numbers that wil be used for hints generation
    int num = (rand()%10)+1;
    int num2 = (rand()%3)+1;
    int num3 = (rand()%10)+1;
    string level1;
    string hint;
    // program creates a variable which is used to store amount of available attempts
    int level2;
    int x;
    // program takes chosen level of difficulty from the player and gives him certain amount of available attempts based on chosen level of difficulty.
    cout << "level of difficulty:\nvery easy - 8 attempts\neasy - 6 attempts\nnormal - 4 attempts\nhard - 2 attempts\nchoose level of difficulty: ";
    cin >> level1;
    if(level1 == "very easy") {
        level2 = 8;
    } else if(level1 == "easy") {
        level2 = 6;
    } else if(level1 == "normal") {
        level2 = 4;
    } else if(level1 == "hard") {
        level2 = 2;
    } else {
        cout << "player chose unavailable level of difficulty";
    }
    // program asks user if they want to get a hint and gives them a hint if they want it
    cout << "Do you want a hint (type 'yes' if you want, or 'no' if you don't want):\n";
    cin >> hint;
    if(hint == "yes") {
        switch(num2) {
            case 1:
            if(num % 2 == 0) {
                cout << "this number is even\n";
            } else {
                cout << "this number is odd\n";
            } break;
            case 2:
            if(num < num3) {
                cout << "this number is lower than " << num3 << endl;
            } else {
                cout << "this number is higher or equal to " << num3 << endl;
            } break;
            case 3:
            if(pow(num, 2) < 10) {
                cout << "this number squared is lower than 10\n";
            } else {
                cout << "this number squared is higher or equal to 10\n";
            } break;
            default:
            cout << "something went wrong";
            break;
        }
    }
    // program creates a loop which iterates through all available attempts, shows accuracy of user's guesses and outputs correct number if user hasn't guessed it before all their attempts ran out
    for(int i = 1; i <= level2; i++) {
        cout << "attempt number " << i << ": \n";
        cin >> x;
        cout << guess(x, num) << endl;
        if(i == level2) {
            cout << "you ran out of attempts. Correct answer is " << num << endl;
        } if(x == num) {
            break;
        }
    }
    return 0;
}