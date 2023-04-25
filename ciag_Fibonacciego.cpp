//Program generujacy N-ty element ciagu Fibonacciego (N wybiera uzytkownik)
#include <iostream>
using namespace std;
//program tworzy funkcje okreslajaca wartosc N-tego elementu ciagu Fibonacciego
int ciag(int x) {
    if(x == 0) {
        return(0);
    } if(x == 1 or x == 2) {
        return(1);
    } else {
        return(ciag(x-2)+ciag(x-1));
    }
}
int main() {
    int num;
    //program pobiera N od uzytkownika i wypisuje N-ty element ciagu Fibonacciego  
    cout << "type X to print Xth element of Fibonacci sequence: \n";
    cin >> num;
    cout << ciag(num);
    return 0;
}