#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;
string compareGuess(int guess, int guessedNumber) {
    if (guess == guessedNumber) {
        return "Correct answer";
    } else {
        if (guess < guessedNumber) {
            return "Your guess is too low";
        } if (guess > guessedNumber) {
            return "Your guess is too high";
        }
    }
}

/*
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
    int num = (rand()%10)+1;
    int num2 = (rand()%3)+1;
    int num3 = (rand()%10)+1;
    string level1;
    string hint;
    int level2;
    int x;
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
*/