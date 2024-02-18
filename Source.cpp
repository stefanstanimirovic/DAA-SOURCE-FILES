#pragma once
#include <string>
#include <iostream>
using namespace std;

// Imports from other files
string max_palindrome(string s);

int main() {
    string s;
    cin >> s;
    cout << max_palindrome(s);
    return 0;
}