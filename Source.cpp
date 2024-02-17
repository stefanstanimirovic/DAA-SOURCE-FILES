#pragma once
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Imports from other files
vector<pair<int, char>> barber_shop(const vector<double>& prices, const vector<double>& distances);

int main() {
    int n;
    cin >> n;
    vector<double> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    vector<double> distances(n);
    for (int i = 0; i < n; i++) {
        cin >> distances[i];
    }

    // Ispis
    vector<pair<int, char>> result = barber_shop(prices, distances);
    for (pair<int, char> p : result) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}