#include <iostream>
using namespace std;

int numberOfGrades1(int a[], int n);
int numberOfGrades2(int a[], int n);

int main() {
    int a[] = { 5, 4, 4, 3, 3 };
    int n = sizeof(a) / sizeof(a[0]);
    cout << numberOfGrades1(a, n) << endl;
    cout << numberOfGrades2(a, n) << endl;
    return 0;
}