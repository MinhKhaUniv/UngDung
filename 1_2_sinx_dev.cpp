#include<iostream>
#include"admachine.h"
#include<cmath>
using namespace std;

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    int k = (PI-x) / (2*PI);
    x = x + k*2*PI;
    double epsilon = 0.0000001;
    double ans = 0;
    double temp = x;
    int i = 0;

    while (true) {
        if (i % 2 == 0) ans += temp;
        else  ans -= temp;
        
        i++;

        if (fabs(temp) <= epsilon) break;
        
        temp = temp * x * x / (i*2) / (i*2+1);
        
    }
    cout << "Dap an  = " << ans;
    return 0;
}