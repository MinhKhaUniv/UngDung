#include<iostream>
#include"admachine.h"
#include<cmath>
using namespace std;

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << "Nhap so gioi han n : ";
    int n;
    cin >> n;
    int k = chia(tru(PI, x), nhan(2, PI));
    x = cong(x, nhan(nhan(k, 2), PI));
    double epsilon = 0.0000001;
    double ans = 0;
    double temp = x;
    int i = 0;

    while (i < n) {
        if (chiaDuP4(i, 2) == 0) ans += temp;
        else  ans -= temp;
        
        i++;

        if (temp < epsilon) break;

        temp = nhan(temp, nhan(x, x));
        temp = chia(temp, nhan(i, 2));
        temp = chia(temp, nhan(i, 2) + 1);
        
    }
    cout << "Sin(x) = " << ans;
    return 0;
}