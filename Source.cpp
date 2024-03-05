#pragma once
#include <vector>
#include <iostream>
using namespace std;

// Imports from other files
void canon_factorization(int n, vector<int> &primes, vector<int> &exponents);

int main() {
    int n;
    cin >> n;
    vector<int> primes, exponents;
    canon_factorization(n, primes, exponents);
    for (int p : primes) {
        cout << p << " ";
    }
    cout << endl;
    for (int e : exponents) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}