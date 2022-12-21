#include<iostream>
#include <cmath>
#include"admachine.h"
using namespace std;


int Mod_P3(int x, int y)
{
    int z, w;
    while(x >= y)
    {
        z = y;
        do 
        {
            w = z;
            z = z + z; // doubling z
        } while(x >= z);
        x = x - w;
    }
    return x;
}
double division_AM(double a, double b)
{
    bool phepChiaAm = false;

    if (a < 0 && b < 0) {
        a = -a;
        b = -b;
    }

    if (a < 0) {
        a = -a;
        phepChiaAm = true;
    }

    if (b < 0) {
        b = -b;
        phepChiaAm = true;
    }

    double aMoi = 0;

    for (long long i = 0; i < 1000000; i++) {
        aMoi += a;
    }

    double soSanh = 0;
    double dapAn = 0;

    while (soSanh < aMoi) {
        soSanh += b;
        dapAn += 0.000001;
    }

    if (phepChiaAm == true) dapAn = -dapAn;
    return dapAn;

}

double cosx(double x)
{
    double math_func = 1;
    double res = 1;
    int i = 0;
    do {
        math_func *= division_AM(-x*x, (2*i + 1)*(2*i + 2));
        //math_func *= -x*x / ((2*i + 1)*(2*i + 2));
        res += math_func;
        i++;
    } while(i < 50);
    return res;
}

double expx(double x)
{
    double math_func = 1;
    double res = 1;
    int i = 0;
    do {
        //math_func *= x / (i + 1);
        math_func *= division_AM(x, i + 1);
        res += math_func;
        i++;
    } while(i < 50);
    return res;
    return 0;
} 

int main() {
    cout << cosx(2 * PI/3) << endl;
    cout << cos(2 * PI/3) << endl;
    
    cout << expx(2) << endl;
    cout << exp(2) << endl;
    return 0;
}
