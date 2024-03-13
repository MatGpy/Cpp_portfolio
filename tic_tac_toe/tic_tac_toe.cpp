#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void printTable(char table[3][3]) {
    cout << table[0][0] << "|" << table[0][1] << "|" << table[0][2] << endl;
    cout << table[1][0] << "|" << table[1][1] << "|" << table[1][2] << endl;
    cout << table[2][0] << "|" << table[2][1] << "|" << table[2][2] << endl;
}
void takeUserSign(char& userSign, char& programSign, map<char,char> programSignValues) {
    cout << "choose sign you want to use (x or o): \n";
    cin >> userSign;
    programSign = programSignValues[userSign];
}
string takeUserMove(char table[3][3], string userMove) {
    cout << "your turn - insert coordinates of the field where you want to put your number (in a following order - rc, where r means number of row and c means number of column): \n";
    cin >> userMove;
    while (table[(userMove[0]-'0')-1][(userMove[1]-'0')-1] != ' ') {
        cout << "player chose field that's already occupated\n";
        cout << "insert coordinates of the field where you want to put your number (in a following order - rc, where r means number of row and c means number of column): \n";
        cin >> userMove;
    }
    if (size(userMove) > 2) {
        throw(userMove);
    }
    return userMove;
}
void takeProgramMove(char table[3][3], int programMoveRow, int programMoveColumn, char programSign) {
    programMoveRow = (rand()%3)+1;
    programMoveColumn = (rand()%3)+1;
    while(table[programMoveRow-1][programMoveColumn-1] != ' ') {
        programMoveRow = (rand()%3)+1;
        programMoveColumn = (rand()%3)+1;
    }
    table[programMoveRow-1][programMoveColumn-1] = programSign;
}
void checkVictory(char table[3][3], char userSign, char programSign, int& userVictory, int& programVictory) {
    if(table[0][0] == userSign && table[0][1] == userSign && table[0][2] == userSign || table[1][0] == userSign && table[1][1] == userSign && table[1][2] == userSign || table[2][0] == userSign && table[2][1] == userSign && table[2][2] == userSign || table[0][0] == userSign && table[1][1] == userSign && table[2][2] == userSign || table[0][2] == userSign && table[1][1] == userSign && table[2][0] == userSign || table[0][0] == userSign && table[1][0] == userSign && table[2][0] == userSign || table[0][1] == userSign && table[1][1] == userSign && table[2][1] == userSign || table[0][2] == userSign && table[1][2] == userSign && table[2][2] == userSign) {
        userVictory = 1;
    }
    if(table[0][0] == programSign && table[0][1] == programSign && table[0][2] == programSign || table[1][0] == programSign && table[1][1] == programSign && table[1][2] == programSign || table[2][0] == programSign && table[2][1] == programSign && table[2][2] == programSign || table[0][0] == programSign && table[1][1] == programSign && table[2][2] == programSign || table[0][2] == programSign && table[1][1] == programSign && table[2][0] == programSign || table[0][0] == programSign && table[1][0] == programSign && table[2][0] == programSign || table[0][1] == programSign && table[1][1] == programSign && table[2][1] == programSign || table[0][2] == programSign && table[1][2] == programSign && table[2][2] == programSign) {
        programVictory = 1;
    }
}
int main() {
    srand(time(0));
    try {
        char table[3][3] = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
        };
        int occupatedFields = 0;
        int userVictory = 0;
        int programVictory = 0;
        int programMoveRow;
        int programMoveColumn;
        char userSign = ' ';
        char programSign = ' ';
        string userMove;
        map<char,char> programSignValues = {
            {'x', 'o'}, {'o', 'x'}
        };
        takeUserSign(userSign, programSign, programSignValues);
        while(userVictory+programVictory==0) {
            userMove = takeUserMove(table, userMove);
            table[(userMove[0]-'0')-1][(userMove[1]-'0')-1] = userSign;
            printTable(table);
            occupatedFields++;
            if(occupatedFields==9) {
                cout << "the end\n";
                break;
            }
            takeProgramMove(table, programMoveRow, programMoveColumn, programSign);
            cout << "program's move:\n";
            printTable(table);
            occupatedFields++;
            checkVictory(table, userSign, programSign, userVictory, programVictory);
            if(userVictory+programVictory == 1) {
                if(userVictory == 1) {
                    cout << "You won\n";
                    break;
                }
                else if(programVictory == 1) {
                    cout << "Program won\n";
                    break;
                }
                else {
                    cout << "Something went wrong\n";
                    break;
                }
            }
            if(userVictory+programVictory==2) {
                cout << "Draw\n";
                break;
            }
            if (occupatedFields >= 9 && userVictory+programVictory==0) {
                cout << "the end\n";
                break;
            }
        }
    }
    catch(string errorString) {
        cout << "Error\n";
    }
    return 0;
}