#include <cstdlib>
#include <vector>
using namespace std;

// modifikacija binarne pretrage
int findInsertionPoint(int a[], int n, int m) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] < m) {
            low = mid + 1;
        }
        else if (a[mid] > m) {
            high = mid - 1;
        }
        else {
            return mid;  // nadjena je vrednost m
        }
    }
    return low;  // vrednost m nije nadjena
}

vector<int> findKClosestElements(int a[], int m, int k, int n) {
    int i = findInsertionPoint(a, n, m);

    int left = i - 1;
    int right = i;

    while (k > 0) {
        if (left < 0 || (right < n &&
            abs(a[left] - m) > abs(a[right] - m))) {
            right++;
        }
        else {
            left--;
        }
        k--;
    }

    vector<int> result;
    left++;
    while (left < right)
    {
        result.push_back(a[left]);
        left++;
    }
    return result;
}