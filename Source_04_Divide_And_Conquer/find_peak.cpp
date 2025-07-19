int findPeak(int arr[], int n) {
    if (arr[0] > arr[1]) {
        return 0;
    }
    if (arr[n - 1] > arr[n - 2]) {
        return n - 1;
    }
    int l = 1;
    int r = n - 2;
    int mid;

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid]) {
            return a[mid];
        }
        if (arr[mid - 1] > arr[mid]) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return -1;
}
