#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <cmath>
#include <map>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <random>
#include <array>
using namespace std;
int takeAmountOfQuestions(int amountOfQuestions) {
    cout << "How many questions do you want this quiz to have (type a number)? \n";
    cin >> amountOfQuestions;
    if (amountOfQuestions < 1 || amountOfQuestions > 100) {
        throw(amountOfQuestions);
    }
    return amountOfQuestions;
}
void takeThreeCities(map<int,string> citiesNums, map<string,string> citiesLocations, map<int,string> countryNums, int country, string cityNames[3]) {
    int city1;
    int city2;
    int city3;
    while(city1 == city2 || city1 == city3 || city2 == city1 || city2 == city3 || city3 == city1 || city3 == city2 && citiesLocations[citiesNums[city1]] != countryNums[country] || citiesLocations[citiesNums[city2]] != countryNums[country] || citiesLocations[citiesNums[city3]] != countryNums[country] && citiesLocations[citiesNums[city1]] == citiesLocations[citiesNums[city2]] || citiesLocations[citiesNums[city1]] == citiesLocations[citiesNums[city3]] || citiesLocations[citiesNums[city2]] == citiesLocations[citiesNums[city1]] || citiesLocations[citiesNums[city2]] == citiesLocations[citiesNums[city3]] || citiesLocations[citiesNums[city3]] == citiesLocations[citiesNums[city1]] || citiesLocations[citiesNums[city3]] == citiesLocations[citiesNums[city2]]) {
        city1 = (rand()%12)+1;
        city2 = (rand()%12)+1;
        city3 = (rand()%12)+1;
    }
    cityNames[0] = citiesNums[city1];
    cityNames[1] = citiesNums[city2];
    cityNames[2] = citiesNums[city3];
}
void shuffleCities(string cityNames[3], string cityNamesShuffled[3]) {
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;
    while(index1 == index2 || index1 == index3 || index2 == index3) {
        index1 = rand()%3;
        index2 = rand()%3;
        index3 = rand()%3;
    }
    cityNamesShuffled[index1] = cityNames[0];
    cityNamesShuffled[index2] = cityNames[1];
    cityNamesShuffled[index3] = cityNames[2];
}
void printQuestion(int questionNumber, int country, map<int,string> countryNums, string cityNamesShuffled[3]) {
    cout << "Question #" << questionNumber << ":\nWhich one of these cities is situated in " << countryNums[country] << "?\na) " << cityNamesShuffled[0] << "\nb) " << cityNamesShuffled[1] << "\nc) " << cityNamesShuffled[2] << endl;
}
string takeAnswer(string answer) {
    cout << "Write the answer here (name of the city): \n";
    cin >> answer;
    return answer;
}
void checkAnswer(string answer, int country,map<string,string> citiesLocations,map<int,string> countryNums, float& correctAnswers, float& wrongAnswers) {
    if (citiesLocations[answer] == countryNums[country]) {
        cout << "Correct answer.\n";
        correctAnswers++;
    } else {
        cout << "Wrong Answer.\n";
        wrongAnswers++;
    }
}
void printSummary(float correctAnswers, float wrongAnswers, float amountOfQuestions) {
    float accuracy = correctAnswers/amountOfQuestions;
    cout << "\nSummary of the quiz:\nCorrect Answers: " << correctAnswers << "/" << amountOfQuestions << "\nWrong answers: " << wrongAnswers << "/" << amountOfQuestions << "\nAccuracy: " << round(accuracy*100) << "%\n";
}
int main() {
    srand(time(0));
    try {
        int questionNumber = 1;
        float correctAnswers = 0;
        float wrongAnswers = 0;
        float amountOfQuestions;
        int country;
        string answer;
        string cityNames[3];
        string cityNamesShuffled[3];
        map<string,string> citiesLocations = {
            {"Berlin", "Germany"}, {"Munich", "Germany"}, {"Hanover", "Germany"}, {"Paris", "France"}, {"Lyon", "France"}, {"Toulouse", "France"}, {"Madrid", "Spain"}, {"Barcelona", "Spain"}, {"Seville", "Spain"}, {"Milan", "Italy"}, {"Rome", "Italy"}, {"Naples", "Italy"},
        };
        map<int,string> citiesNums = {
            {1, "Berlin"}, {2, "Munich"}, {3, "Hanover"}, {4, "Paris"}, {5, "Lyon"}, {6, "Toulouse"}, {7, "Madrid"}, {8, "Barcelona"}, {9, "Seville"}, {10, "Milan"}, {11, "Rome"}, {12, "Naples"},
        };
        map<int,string> countryNums = {
            {1, "Germany"}, {2, "France"}, {3, "Spain"}, {4, "Italy"},
        };
        amountOfQuestions = takeAmountOfQuestions(amountOfQuestions);
        while (questionNumber <= amountOfQuestions){
            country = (rand()%4)+1;
            takeThreeCities(citiesNums, citiesLocations, countryNums, country, cityNames);
            shuffleCities(cityNames, cityNamesShuffled);
            printQuestion(questionNumber, country, countryNums, cityNamesShuffled);
            answer = takeAnswer(answer);
            checkAnswer(answer, country, citiesLocations, countryNums, correctAnswers, wrongAnswers);
            questionNumber++;
        }
        printSummary(correctAnswers, wrongAnswers, amountOfQuestions);
    } catch(int errorNumber) {
        cout << "Error\n";
    } catch(string errorString) {
        cout << "Error\n";
    }
    return 0;
}