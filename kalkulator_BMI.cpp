//Kalkulator BMI (Body Mass Index)
#include <iostream>
#include <math.h>
using namespace std;
//program tworzy funkcje wyliczajaca BMI na podstawie dostarczonych danych
int bmi2(int height, int weight) {
    float x = pow(height, 2)/10000;
    float bmi = weight/x;
    return(bmi);
}
int main() {
    int weight;
    int height;
    float bmi;
    //program pobiera od uzytkownika mase ciala (w kilogramach) i wzrost (w centymetrach), oraz uzywa utworzonej poprzednio funkcji do wyliczenia BMI
    cout << "type your weight in kilograms: \n";
    cin >> weight;
    cout << "type your height in centimetres: \n";
    cin >> height;
    bmi = bmi2(height, weight);
    //program wypisuje BMI uzytkownika i informacje o tym jak (nie)prawidlowa jest jego waga
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