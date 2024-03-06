#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void printTable(char table[9][9]) {
    cout << " |1|2|3|4|5|6|7|8|9|\n";
    for(int row = 0; row < 9; row++) {
        cout << row+1 << "|" << table[row][0] << "|" << table[row][1] << "|" << table[row][2] << "|" << table[row][3] << "|" << table[row][4] << "|" << table[row][5] << "|" << table[row][6] << "|" << table[row][7] << "|" << table[row][8] << "|" << endl;
    }
}
string checkIfVictory(char table[9][9]) {
    int amountOfX = 0;
    map<pair<int,int>,string> comparisonOutcomes;
    comparisonOutcomes[make_pair(0,80)] = "no";
    comparisonOutcomes[make_pair(81,82)] = "yes";
    for(int row = 0; row < 9; row++) {
        for(int column = 0; column < 9; column++) {
            if (table[row][column] == 'X') {
                amountOfX++;
            }
        }
    }
    for (const auto& entry: comparisonOutcomes) {
        auto amountRange = entry.first;
        auto outcome = entry.second;
        if (amountOfX >= amountRange.first && amountOfX <= amountRange.second) {
            return outcome;
        }
    }
    return "Something went wrong";
}
string takeUserMove(string userMove) {
    cout << "Insert coordinates of the cell on the table where you would like to place 'X' (in a form of double digit number, where first digit is an number of row and second number is a number of column): \n";
    cin >> userMove;
    vector<int> numbers = {1,2,3,4,5,6,7,8,9};
    if (find(numbers.begin(), numbers.end(), userMove[0]-'0') == numbers.end() || find(numbers.begin(), numbers.end(), userMove[1]-'0') == numbers.end() || size(userMove) > 2) {
        throw(userMove);
    }
    return userMove;
}
void modifyTable(char table[9][9],string userMove,int XaxisPlacement,int YaxisPlacement, map<char, char> tableValues) {
    if ((userMove[0]-'0') - YaxisPlacement < 0 || (userMove[1]-'0') - XaxisPlacement < 0) {
        return;
    } 
    try {
        table[(userMove[0]-'0')-YaxisPlacement][(userMove[1]-'0')-XaxisPlacement] = tableValues[table[(userMove[0]-'0')-YaxisPlacement][(userMove[1]-'0')-XaxisPlacement]];
    } catch(const out_of_range& error) {
        return;
    }
}
int main() {
    try {
        char table[9][9] = {
            {'O','O','O','O','O','O','O','O','O'},
            {'O','O','O','O','O','O','O','O','O'},
            {'O','O','O','O','O','O','O','O','O'},
            {'O','O','O','O','O','O','O','O','O'},
            {'O','O','O','O','O','O','O','O','O'},
            {'O','O','O','O','O','O','O','O','O'},
            {'O','O','O','O','O','O','O','O','O'},
            {'O','O','O','O','O','O','O','O','O'},
            {'O','O','O','O','O','O','O','O','O'}
        };
        map<char,char> tableValues;
        tableValues['X'] = 'O';
        tableValues['O'] = 'X';
        string victory = "no";
        string userMove;
        int turn = 0;
        while (victory == "no") {
            turn++;
            printTable(table);
            userMove = takeUserMove(userMove);
            modifyTable(table, userMove, 1, 1, tableValues);
            modifyTable(table, userMove, 2, 1, tableValues);
            modifyTable(table, userMove, 1, 0, tableValues);
            modifyTable(table, userMove, 0, 1, tableValues);
            modifyTable(table, userMove, 1, 2, tableValues);
            victory = checkIfVictory(table);
        }
        cout << "You won!\nYou managed to set all the table cells as 'X' in " << turn << " rounds.\n";
    }
    catch (const out_of_range& error) {
        cout << "Error: invalid data in the input";
    } catch(int errorNumber) {
        cout << "Error";
    } catch (string error) {
        cout << "Error";
    }
    return 0;
}