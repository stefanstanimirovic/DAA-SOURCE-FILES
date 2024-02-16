#include <iostream>
using namespace std;

// Imports from other files
bool permutation_sum_composite_bt(int, int);

int main() {
    cout << "Unesite brojeve n i m: ";
    int n, m;
    cin >> n >> m;
    permutation_sum_composite_bt(n, m);
    return 0;
}