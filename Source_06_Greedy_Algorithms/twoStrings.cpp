#include <iostream>
#include <string>
using namespace std;

void twoStrings(string s1, string s2) {
    int j = 0, i = 0;
    while (i < s1.size() && j < s2.size()) {
        if (s1[i] == s2[j]) {
            j++;
        }
        i++;
    }
    if (j == s2.size()) {
        cout << "DA" << endl;
    }
    else {
        cout << "NE" << endl;
    }
}