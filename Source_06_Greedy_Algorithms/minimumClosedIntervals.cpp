#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minClosedIntervals(double points[], int n) {
    sort(points, points + n);

    int count = 1;
    double lastEnd = points[0] + 1;
    for (int i = 1; i < n; i++) {
        if (points[i] > lastEnd) {
            count++;
            lastEnd = points[i] + 1;
        }
    }
    return count;
}

int Intervals_main() {
    int n;
    cin >> n;
    double points[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> points[i];
    }
    int minIntervals = minClosedIntervals(points, n);
    cout << minIntervals << endl;
    return 0;
}