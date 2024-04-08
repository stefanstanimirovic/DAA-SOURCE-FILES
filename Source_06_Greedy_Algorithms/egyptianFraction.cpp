#include <iostream>
using namespace std;

int gcd(int, int);

void egyptianFraction(int m, int n) {
    if (m == 1) {
        cout << "1/" << n;
    }
    else {
        int newN = ceil(n / (m * 1.0));
        cout << "1/" << newN << " + ";
        int r = gcd(m * newN - n, n * newN);
        egyptianFraction((m * newN - n) / r, n * newN / r);
    }
}

/*
int main() {
    int numerator, denominator;
    cin >> numerator >> denominator;
    cout << numerator << "/" << denominator << " = ";
    egyptianFraction(numerator, denominator);
    return 0;
}
*/