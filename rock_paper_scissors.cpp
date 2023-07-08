/*
Rock-paper-scissors game
1. choose your move
2. wait for a program to randomly choose a move
3. after that, your move and move of the program will be compared and results will be shown in the output
*/
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
//program chooses its move based on a value of randomly generated number
string aaa(int x) {
    switch(x) {
        case 1:
          return("rock");
          break;
        case 2:
          return("paper");
          break;
        case 3:
          return("scissors");
          break;
    }
}
//program creates a function which compares user's move and program's move
string bbb(string x,string y) {
    if(x == "rock" && y == "scissors" || x == "paper" && y == "rock" || x == "scissors" && y == "paper") {
        return("player 2 won");
    } if(x == "rock" && y == "paper" || x == "paper" && y == "scissors" || x == "scissors" && y == "rock") {
        return("you won");
    } if(x == "rock" && y == "rock" || x == "paper" && y == "paper" || x == "scissors" && y == "scissors") {
        return(" draw");
    }
}
int main() {
    srand(time(0));
    string v1;
    int v2;
    //program takes user's move from the input
    cout << "Now it's your turn (you can choose rock, paper, or scissors): \n";
    cin >> v1;
    v2 = (rand() % 3)+1;
    //program compares player's and program's moves and outputs the result of this comparison
    cout << "player2: " << aaa(v2) << "\n" << bbb(aaa(v2), v1);
    return 0;
}