#include<iostream>
using namespace std;

int func2(int x, int y, int z) {
    if (z==1) return 0;
    int modZ = x%z;
    int ans = 1;

    for (int i = 1; i <= y; i++) {
        ans = (ans*modZ)%z;
    }

    return ans;
}

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
    cout << func2(x, y, z);
    return 0;
}