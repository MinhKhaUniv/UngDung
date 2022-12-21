#include<iostream>
#include"admachine.h"
using namespace std;

int main() {
    int x = 2, y = 1;
    int q;
    int temp;

    do {
        cout << "Enter q : ";
        cin >> q;
        if (q >= 1) {
            temp = x;
            x = temp*q + y;
            y = temp;
        }
    } while (q >= 1);

    do {
        temp = x;
        q = x/y;
        x = y;
        y = temp%y;

        if (y >= 1) cout << q << " ";
    } while (y >= 1);

    return 0;
}
