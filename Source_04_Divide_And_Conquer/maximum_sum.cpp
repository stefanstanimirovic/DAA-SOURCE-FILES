#include <climits>
#include <algorithm>
using namespace std;

int maximum_sum(int a[], int low, int high) {
    if (high <= low) {
        return a[low];
    }

    int mid = (low + high) / 2;

    // Nadji maksimalnu sumu za levi podniz
    int left_max = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += a[i];
        if (sum > left_max) {
            left_max = sum;
        }
    }

    // Nadji maksimalnu sumu za desni podniz
    int right_max = INT_MIN;
    sum = 0;   
    for (int i = mid + 1; i <= high; i++) {
        sum += a[i];
        if (sum > right_max) {
            right_max = sum;
        }
    }

    int max_left_right = max(maximum_sum(a, low, mid),
        maximum_sum(a, mid + 1, high));
    return max(max_left_right, left_max + right_max);
}