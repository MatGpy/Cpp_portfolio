//Generator of Nth element of Fibonacci sequence (N is chosen by the user)
#include <iostream>
using namespace std;
//program creates function that defines Nth element of Fibonacci sequence
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
    //program takes N from user's input and outputs Nth element of Fibonacci sequence  
    cout << "type X to print Xth element of Fibonacci sequence: \n";
    cin >> num;
    cout << ciag(num);
    return 0;
}