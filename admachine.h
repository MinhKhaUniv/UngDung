/*
1. read x
2. x <- y 
3. x <- x+y
4. x <- x-y
5. if x >= y
6. write x
*/
const double PI = 3.141592654; 

double nhan(double a, double b) {
    double aMoi = 0;

    for (long long i = 0; i < 10000000; i++) {
        aMoi += a;
    }

    double soSanh = 0;
    double dapAn = 0;

    while (soSanh < aMoi) {
        soSanh += b;
        dapAn += 0.0000001;
    }

    return dapAn;
}

double nhan(double a, double b) {
    double soBe = a;
    double sonLon = b;

    if (a > b) {
        soBe = b;
        sonLon = a;
    } 

          

    long long i = 0;
    while (i < 10000000) {

    }
}

