#pragma once
#include <vector>
#include <iostream>
using namespace std;

// Imports from other files
int gcd(int a, int b, int& x, int& y);
int gcd_it(int a, int b, int& x, int& y);

int main() {
    int a = 55, b = 80;
    int x, y, x1, y1;
    gcd(a, b, x, y);
    gcd_it(a, b, x1, y1);
    cout << x << " " << y << " " << x1 << " " << y1 << endl;

    return 0;
}