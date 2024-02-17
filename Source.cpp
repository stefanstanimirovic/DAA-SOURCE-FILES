#include <iostream>
using namespace std;

// Imports from other files
long long exp_s1_ineffective(int n);
long long exp_s1(int n);
double exp_s2(int n);
double exp_s3(int n);

int main() {
    //int n;
    //cin >> n;
    //cout << exp_s1_ineffective(n);
    for (int i = 1; i <= 10; i++) {
        cout << exp_s1_ineffective(i) << " " << exp_s1(i) << " " << exp_s2(i) << " " << exp_s3(i) << endl;
    }
    return 0;
}