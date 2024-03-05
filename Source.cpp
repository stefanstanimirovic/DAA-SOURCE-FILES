#pragma once
#include <vector>
#include <iostream>
using namespace std;

// Imports from other files
vector<int> eratosthenesSieve(int n);

int main() {
    int n;
    cin >> n;
    vector<int> primes = eratosthenesSieve(n);
    for (int i : primes) {
        cout << i << " ";
    }
    return 0;
}