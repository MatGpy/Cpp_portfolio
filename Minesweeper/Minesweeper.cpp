#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <map>
#include <string>
#include <cstdio>
using namespace std;
void populateTablesWithMines(char mainTable[10][10], int mines) {
    int b1;
    int b2;
    while (mines > 0) {
        b1 = rand()%10;
        b2 = rand()%10;
        while (mainTable[b1][b2] != ' ') {
            b1 = rand()%10;
            b2 = rand()%10;
        }
        mainTable[b1][b2] = 'X';
        mines--;
    }
}
void populateTablesWith1(char mainTable[10][10], int points1) {
    int b1;
    int b2;
    while (points1 > 0) {
        b1 = rand()%10;
        b2 = rand()%10;
        while (mainTable[b1][b2] != ' ') {
            b1 = rand()%10;
            b2 = rand()%10;
        }
        mainTable[b1][b2] = '1';
        points1--;
    }
}
void populateTablesWith2(char mainTable[10][10], int points2) {
    int b1;
    int b2;
    while (points2 > 0) {
        b1 = rand()%10;
        b2 = rand()%10;
        while (mainTable[b1][b2] != ' ') {
            b1 = rand()%10;
            b2 = rand()%10;
        }
        mainTable[b1][b2] = '2';
        points2--;
    }
}
void populateTablesWith3(char mainTable[10][10], int points3) {
    int b1;
    int b2;
    while (points3 > 0) {
        b1 = rand()%10;
        b2 = rand()%10;
        while (mainTable[b1][b2] != ' ') {
            b1 = rand()%10;
            b2 = rand()%10;
        }
        mainTable[b1][b2] = '3';
        points3--;
    }
}
void printTable(char displayedTable[10][10]) {
    int column = 0;
    int row = 0;
    cout << " |0|1|2|3|4|5|6|7|8|9|\n";
    while (column <= 9) {
        cout << row << "|" << displayedTable[column][0] << "|" << displayedTable[column][1] << "|" << displayedTable[column][2] << "|" << displayedTable[column][3] << "|" << displayedTable[column][4] << "|" << displayedTable[column][5] << "|" << displayedTable[column][6] << "|" << displayedTable[column][7] << "|" << displayedTable[column][8] << "|" << displayedTable[column][9] << "|" << endl;
        column++;
        row++;
    }
}
string takeDifficultyLevel(string difficultyLevel) {
    cout << "Choose level of difficulty (easy, medium, hard or very hard): \n";
    cin >> difficultyLevel;
    if (difficultyLevel != "easy" && difficultyLevel != "medium" && difficultyLevel != "hard" && difficultyLevel != "very hard") {
        throw(difficultyLevel);
    } 
    return difficultyLevel;
}
string takeAttempt(char displayedTable[10][10], string attempt) {
    cout << "Which field do you want to uncover? (type the answer in the following order - rc (r - row, c - column)) \n";
    cin >> attempt;
    if (size(attempt) > 2) {
        throw(attempt);
    } while (displayedTable[(attempt[0]-'0')][(attempt[1]-'0')] != 'O') {
        cout << "Chosen field is already uncovered\n";
        cout << "Which field do you want to uncover? (type the answer in the following order - rc (r - row, c - column)) \n";
        cin >> attempt;
        if (size(attempt) > 2) {
            throw (attempt);
        }
    }
    return attempt;
}
int main() {
    srand(time(0));
    string attempt;
    string difficultyLevel;
    int mines;
    int points1;
    int points2;
    int points3;
    try {
        char displayedTable[10][10] = {
            {'O','O','O','O','O','O','O','O','O','O'},
            {'O','O','O','O','O','O','O','O','O','O'},
            {'O','O','O','O','O','O','O','O','O','O'},
            {'O','O','O','O','O','O','O','O','O','O'},
            {'O','O','O','O','O','O','O','O','O','O'},
            {'O','O','O','O','O','O','O','O','O','O'},
            {'O','O','O','O','O','O','O','O','O','O'},
            {'O','O','O','O','O','O','O','O','O','O'},
            {'O','O','O','O','O','O','O','O','O','O'},
            {'O','O','O','O','O','O','O','O','O','O'}
        };
        char mainTable[10][10] = {
            {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
        };
        map<string, int> difficultyLevelMines;
        difficultyLevelMines["easy"] = 25;
        difficultyLevelMines["medium"] = 35;
        difficultyLevelMines["hard"] = 45;
        difficultyLevelMines["very hard"] = 55;
        map<string, int> difficultyLevelPoint1;
        difficultyLevelPoint1["easy"] = 36;
        difficultyLevelPoint1["medium"] = 32;
        difficultyLevelPoint1["hard"] = 27;
        difficultyLevelPoint1["very hard"] = 22;
        map<string, int> difficultyLevelPoint2;
        difficultyLevelPoint2["easy"] = 23;
        difficultyLevelPoint2["medium"] = 20;
        difficultyLevelPoint2["hard"] = 16;
        difficultyLevelPoint2["very hard"] = 14;
        map<string, int> difficultyLevelPoint3;
        difficultyLevelPoint3["easy"] = 16;
        difficultyLevelPoint3["medium"] = 13;
        difficultyLevelPoint3["hard"] = 12;
        difficultyLevelPoint3["very hard"] = 9;
        difficultyLevel = takeDifficultyLevel(difficultyLevel);
        mines = difficultyLevelMines.at(difficultyLevel);
        points1 = difficultyLevelPoint1.at(difficultyLevel);
        points2 = difficultyLevelPoint2.at(difficultyLevel);
        points3 = difficultyLevelPoint3.at(difficultyLevel);
        populateTablesWithMines(mainTable, mines);
        populateTablesWith1(mainTable, points1);
        populateTablesWith2(mainTable, points2);
        populateTablesWith3(mainTable, points3);
        int uncoveredMines = 0;
        int uncoveredCells = 0;
        int points = 0;
        printTable(displayedTable);
        while (uncoveredCells < 100-mines) {
            attempt = takeAttempt(displayedTable, attempt);
            displayedTable[(attempt[0]-'0')][(attempt[1]-'0')] = mainTable[(attempt[0]-'0')][(attempt[1]-'0')];
            printTable(displayedTable);
            switch (mainTable[(attempt[0]-'0')][(attempt[1])-'0']) {
                case '1':
                uncoveredCells++;
                cout << "+1 point\n";
                points++;
                break;
                case '2':
                uncoveredCells++;
                cout << "+2 points\n";
                points+=2;
                break;
                case '3':
                uncoveredCells++;
                cout << "+3 points\n";
                points+=3;
                break;
                case 'X':
                uncoveredCells++;
                uncoveredMines = 1;
                break;
                default:
                cout << "Something went wrong\n";
                break;
            }
            if (uncoveredMines == 1) {
                cout << "Game over\nTotal scored points: " << points << endl;
                break;
            }
        }
        if (uncoveredMines == 0) {
            cout << "Victory\nTotal scored points: " << points;
        }
    }
    catch (int errorNumber) {
        cout << "Error";
    } catch (string errorString) {
        cout << "Error";
    }
    return 0;
}