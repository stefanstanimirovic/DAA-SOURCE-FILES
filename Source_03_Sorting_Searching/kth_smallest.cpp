#include <limits>

void swap(int&, int&);
int partition(int arr[], int l, int r); 
    // standardno particionisanje iz quicksort algoritma

int kthSmallest(int arr[], int l, int r, int K) {
    if (K > 0 && K <= r - l + 1) {
        int pos = partition(arr, l, r);
        if (pos - l == K - 1) {
            return arr[pos];
        }
        if (pos - l > K - 1) {
            return kthSmallest(arr, l, pos - 1, K);
        }
        return kthSmallest(arr, pos + 1, r, K - pos + l - 1);
    }
    return INT_MAX;
}