#include<iostream>
using namespace std;

int main() {
    int x, y, z;
    cout << "(x^y) mod z: x>=0, y>0, z>0" << endl;
    cout << "Enter x, y, z: ";
    cin >> x >> y >> z;

    if (x<0 || y<=0 || z <=0) {
        cout << "Invalid input!";
        return 0;
    }

    cout << x << "^" << y << " % " << z << " = ";

    int u = 1;
    int v = 1;
    int l = 1;

    do {
        int temp;
        
        temp = u;
        u = v;
        v = v + temp;
        l = l + 1;
    } while (y >= v);

    int r = 1;
    int s = 1;
    int t = 0;
    int w = y;

    do {
        if (w >= u) {
            w = w - u;
            t = t + s;
        }

        int temp;

        temp = u;
        u = v - u;
        v = temp;

        temp = r;
        r = s;
        s = temp + s;

        l = l - 1;

    } while (u < v);

// Part 2:
    x = x % z;
    w = x;
    u = 1;
    l = 1;

    do {
        int temp;

        if (t >= r) {
            t = t - r;
            temp = u*w;
            u = temp % z;
        }

        temp = r;
        r = s - r;
        s = temp;

        temp = x;
        x = w;
        w = (temp*w) % z;
        l = l + 1;

    } while (r < s);

    cout << u;

    return 0;
}