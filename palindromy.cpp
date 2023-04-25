//Program sprawdzajacy czy dana liczba/slowo jest palindromem
#include <iostream>
using namespace std;
//program definiuje funkcje sprawdzajaca czy liczba/slowo jest palindromem
string palindrom(string x) {
    int m = 0;
    int i = 0;
    int l = (x.size()-1);
    //funkcja posluguje sie petla while, aby sprawdzic, czy znaki po przeciwnych stronach stringa sa identyczne. Gdy tak jest, iterator zwiekszany jest o 1, tak samo jak waryosc zmiennej m
    while(x[i] == x[l-i]) {
        m = m+1;
        i = i+1;
        //program konczy dzialanie petli w przypadku, w ktorym iterator osiaga wartosc wyzsza niz dlugosc badanego stringa
        if(i>l){
            break;
        }
    //funkcja sprawdza, czy wartosc zmiennej m jest rowna dlugosci badanego stringa (wartosc m byla zwiekszana o 1 za kazdym razem, kiedy znaki po przeciwnych stronach stringa byly identyczne. Dlatego zakladajac, ze petla przeszla przez calego stringa, liczba w stringu jest palindromem wylacznie wtedy, gdy wartosc m jest rowna dlugosci tego stringa)
    } if(m == l+1) {
        return(" is a palindrome\n");
    } else {
        return(" isn't a palindrome\n");
    }
}

int main() {
    string input;
    //program pobiera od uzytkownika liczbe/slowo, ktora uzytkownik chce zbadac, a nastepnie zwraca odpowiednia odpowiedz w zaleznosci od tego, czy podana liczba/slowo jest palindromem
    cout << "type a number/word: \n";
    cin >> input;
    cout << input << palindrom(input) << endl;
    return 0;
}