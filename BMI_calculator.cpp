//BMI (Body Mass Index) calculator
#include <iostream>
#include <math.h>
using namespace std;
//program creates a function which calculates BMI value
int bmi2(int height, int weight) {
    float x = pow(height, 2)/10000;
    float bmi = weight/x;
    return(bmi);
}
int main() {
    int weight;
    int height;
    float bmi;
    //program takes user's input with their body weight (in kilograms) and height (in centimeters) and uses previously created function to calculate BMI
    cout << "type your weight in kilograms: \n";
    cin >> weight;
    cout << "type your height in centimetres: \n";
    cin >> height;
    bmi = bmi2(height, weight);
    //program outputs user's BMI and an information whether their BMI is healthy, too high or too low
    cout << "Your BMI is: " << bmi << endl;
    if(bmi <= 18) {
        cout << "you weight too little\n";
    } if(bmi > 18 && bmi <= 24) {
        cout << "your weight is perfect\n";
    } if(bmi > 24 && bmi <= 29) {
        cout << "you weight a bit too much\n";
    } if(bmi > 29 && bmi <= 35) {
        cout << "you weight too much\n";
    } if(bmi > 35) {
        cout << "you weight way too much\n";
    }
    return 0;
}