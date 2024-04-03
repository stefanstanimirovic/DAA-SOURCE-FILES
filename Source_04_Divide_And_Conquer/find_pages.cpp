#include <iostream>
#include <climits>
using namespace std;

bool isPossible(int arr[], int n, int m, int curr_min) {
    int studentsRequired = 1;
    int curr_sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > curr_min) {
            return false;
        }

        if (curr_sum + arr[i] > curr_min) {
            studentsRequired++;
            curr_sum = arr[i];
            if (studentsRequired > m) {
                return false;
            }
        }
        else {
            curr_sum += arr[i];
        }
    }
    return true;
}

int findPages(int arr[], int n, int m) {
    int sum = 0;
    if (n < m) {
        return -1;
    }
    int mx = INT_MIN;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        mx = max(mx, arr[i]);
    }

    int start = mx, end = sum;
    int result = INT_MAX;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid)) {
            result = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return result;
}

int find_pages_main() {
    int arr[] = { 15, 18, 30, 47, 58 };
    int n = sizeof arr / sizeof arr[0];
    int m = 3;
    cout << findPages(arr, n, m) << endl;
    return 0;
}