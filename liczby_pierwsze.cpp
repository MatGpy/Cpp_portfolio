//Program sprawdzajacy, czy wpisana przez uzytkownika liczba jest liczba pierwsza
#include <iostream>
#include <cmath>
using namespace std;
// program tworzy funkcje sprawdzajaca, czy dana liczba jest liczba jest liczba pierwsza. sprawdza ona jej podzielnosc przez wszystkie liczby miedzy 2 a jej pierwiastkiem.
string check_if_prime(int x) {
    for(int i = 2; i <= sqrt(x);i++) {
        if(x % i == 0) {
            return(" isn't a prime number");
        }
    } return(" is a prime number");
}

int main() {
// program pobiera badana liczbe od uzytkownika
    int number;
    cout << "insert a number: \n";
    cin >> number;
// program sprawdza, czy liczba podana przez uzytkownika jest rowna 0 lub 1 - w takich przypadkach funkcja zwrocilaby nieprawidlowe wyniki, dlatego dla tych przypadkow trzeba indywidualnie przypisac dzialanie programu. Po analizie tej liczby program odpowiada, czy jest ona pierwsza, czy zlozona 
   if(number == 1 || number == 0) {
       cout << number << " isn't a prime number\n";
   } else {
       cout << number << check_if_prime(number) << endl;
   }
    return 0;
}