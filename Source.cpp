#include <iostream>
using namespace std;

void egyptianFraction(int m, int n);

int main() {
    int numerator, denominator;
    cin >> numerator >> denominator;
    cout << numerator << "/" << denominator << " = ";
    egyptianFraction(numerator, denominator);
    return 0;
}