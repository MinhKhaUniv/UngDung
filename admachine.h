/*
1. read x
2. x <- y 
3. x <- x+y
4. x <- x-y
5. if x >= y
6. write x
*/
const double PI = 3.141592654; 

void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

double cong(double a, double b) {
    return a + b;
}

double tru(double a, double b) {
    return a - b;
}

double nhan(double a, double b) {
	return a*b;
}

double chia(double a, double b) {
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

    for (long long i = 0; i < 10000000; i++) {
        aMoi += a;
    }

    double soSanh = 0;
    double dapAn = 0;

    while (soSanh < aMoi) {
        soSanh += b;
        dapAn += 0.0000001;
    }

	if (phepChiaAm == true) dapAn = -dapAn;
    return dapAn;
}

int chiaDuP3(int x, int y) {
    int z, w;
    while(x >= y) {
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

int chiaDuP4(int x, int y) {
	int z;
	if(x >= y) {
		z = y;
		do {
			y = y + z;
			swap(y, z);
		} while(x >= z);

		do {
			if(x >= y)
				x = x - y;

			z = z - y; // <y, z> <- <z - y, y>
			swap(y, z);


		} while(!(y >= z));

	}
	return x;
}

int Multiplication_and_Division_P5(int x, int y, int z) {
	int w = 0;
	int u, v;
	if(y >= z) {
		u = x;
		v = z;

		do {
			u = u + x; // <u, x> <- <x, u + x>
			swap(x, u);

			v = v + z; // <v, z> <- <z, v + z>
			swap(v, z);

		} while(y >= z);

		do {
			if(y >= v) {
				y = y - v;
				w = w + u;
			}

			x = x - u; // <u, x> <- <x - u, u>
			swap(x, u);

			z = z - v; // <v, z> <- <z - v, v>
			swap(z, v);

		} while(!(v >= z));
	}
	return w;
}

int gcd_P6(int x, int y) {
	int z = y;
	z = z + z;

	while(!(y >= z)) {
		while(x >= z)
		{
			y = y + z;
			swap(y, z);
		}

		do {
			if(x >= y)
				x = x - y;
			z = z - y;
			swap(z, y);

		} while(!(y >= z));

		swap(x, y);
		z = y;
		z = z + z;
	}
	return x;
}
