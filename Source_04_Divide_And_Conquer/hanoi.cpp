#include <iostream>
using namespace std;

void hanoi(int n, char from, char to, char aux) {
    if (n == 0) {
        return;
    }
    hanoi(n - 1, from, aux, to);
    cout << "Disk " << n << " od stuba " << from << " do stuba " << to << endl;
    hanoi(n - 1, aux, to, from);
}

/*
* // Drivers code
int main()
{
    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
*/