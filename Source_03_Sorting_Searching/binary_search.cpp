int binarySearch(int a[], int l, int r, int x)
{
    if (l > r) {
        return -1;
    }
    int mid = l + (r - l) / 2;
    if (a[mid] == x) {
        return mid;
    }
    if (a[mid] > x) {
        return binarySearch(a, l, mid - 1, x);
    }
    return binarySearch(a, mid + 1, r, x);
 }