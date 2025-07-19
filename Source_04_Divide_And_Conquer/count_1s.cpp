int count1s(int a[], int n) {
    int l = 0;
    int r = n - 1;
    
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (a[mid] == 0) {
            low = mid + 1;
        } else {
            if (mid == 0 || arr[mid - 1] == 0) {
                return n - mid;
            } else {
                high = mid - 1;
            }
        }
    }

    return 0; // nema jedinica u nizu
}
