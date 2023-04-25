//Program do gry w papier kamien nozyce. Program dziala tak, ze uzytkownik wybiera swoj ruch, potem program. Nastepnie ruchy gracza i programu sa porownywane i wyswietlany jest wynik
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
//program wybiera swoj ruch w oparciu o wartosc losowo wygenerowanej liczby
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
//program tworzy funkcje do porownywania ruchow gracza i programu
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
    //program pobiera ruch od uzytkownika
    cout << "Now it's your turn (you can choose rock, paper, or scissors): \n";
    cin >> v1;
    v2 = (rand() % 3)+1;
    //program porownuje ruch gracza z ruchem programu za pomoca uprzednio utworzonej funkcji i pokazuje wynik starcia wraz z ruchem programu
    cout << "player2: " << aaa(v2) << "\n" << bbb(aaa(v2), v1);
    return 0;
}