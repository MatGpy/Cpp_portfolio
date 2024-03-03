#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <map>
#include <string>
using namespace std;
void compareGuess(int guess, int guessedNumber) {
    if (guess == guessedNumber) {
        cout << "Correct answer\n";
    } else {
        if (guess < guessedNumber) {
            cout << "Your guess is too low\n";
        } if (guess > guessedNumber) {
            cout << "Your guess is too high\n";
        }
    }
}
string takeDifficultyLevel(string difficultyLevel) {
    cout << "level of difficulty:\nvery easy - 8 attempts\neasy - 6 attempts\nnormal - 4 attempts\nhard - 2 attempts\nchoose level of difficulty: ";
    cin >> difficultyLevel;
    if (difficultyLevel != "very easy" && difficultyLevel != "easy" && difficultyLevel != "normal" && difficultyLevel != "hard") {
        throw (difficultyLevel);
    }
    return difficultyLevel;
}
int defineAmountOfAttempts (int amountOfAttempts, string difficultyLevel, const map <string, int>& difficultyLevelAttempts) {
    amountOfAttempts = difficultyLevelAttempts.at(difficultyLevel);
    return amountOfAttempts;
}
string askAboutHint(string hint) {
    cout << "Do you want to get a hint (type 'yes' if you want a hint and 'no' if you don't)? " << endl;
    cin >> hint;
    if (hint != "yes" && hint != "no") {
        throw (hint);
    }
    return hint;
}
void displayHint(string hint, int guessedNumber, int hintNumber, int hintNumber2) {
    if (hint == "yes") {
        switch (hintNumber) {
            case 1:
            if (guessedNumber % 2 == 0) {
                cout << "this number is even\n";
            } else {
                cout << "this number is odd\n";
            } break;
            case 2:
            if (guessedNumber < hintNumber2) {
                cout << "this number is lower than " << hintNumber2 << endl;
            } else {
                cout << "this number is higher or equal to " << hintNumber2 << endl;
            } break;
            case 3:
            if (pow(guessedNumber, 2) < 10) {
                cout << "this number squared is lower than 10\n";
            } else {
                cout << "this number squared is higher or equal to 10\n";
            } break;
            default:
            cout << "something went wrong\n";
            break;
        }
    }
}
int takeGuess(int guess, int attemptNumber) {
    cout << "Attempt no." << attemptNumber << "\nInsert your guess: \n";
    cin >> guess;
    if (guess < 1 || guess > 10) {
        throw (guess);
    }
    return guess;
}
int main() {
    srand(time(0));
    try {
        cout << "Try to guess a randomly generated number between 1 and 10\n";
        int guessedNumber = (rand()%10)+1;
        int hintNumber = (rand()%3)+1;
        int hintNumber2 = (rand()%10)+1;
        int amountOfAttempts;
        int attemptNumber;
        int guess;
        string difficultyLevel;
        string hint;
        map<string, int> difficultyLevelAttempts;
        difficultyLevelAttempts["very easy"] = 8;
        difficultyLevelAttempts["easy"] = 6;
        difficultyLevelAttempts["normal"] = 4;
        difficultyLevelAttempts["hard"] = 2;
        difficultyLevel = takeDifficultyLevel(difficultyLevel);
        amountOfAttempts = defineAmountOfAttempts(amountOfAttempts, difficultyLevel, difficultyLevelAttempts);
        hint = askAboutHint(hint);
        displayHint(hint, guessedNumber, hintNumber, hintNumber2);
        attemptNumber = 1;
        while(attemptNumber <= amountOfAttempts) {
            guess = takeGuess(guess, attemptNumber);
            compareGuess(guess, guessedNumber);
            if(guess == guessedNumber) {
                break;
            }
            if(attemptNumber == amountOfAttempts) {
                cout << "You ran out of attempts. Correct answer is " << guessedNumber << endl;
            }
            attemptNumber++;
        }
    }
    catch(int errorNumber) {
        cout << "Error";
    } catch (string error) {
        cout << "Error";
    }
    return 0;
}