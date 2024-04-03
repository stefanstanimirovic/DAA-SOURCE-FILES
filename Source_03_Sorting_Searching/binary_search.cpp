int binarySearchRec(int a[], int l, int r, int x)
{
    if (l > r) {
        return -1;
    }
    int mid = l + (r - l) / 2;
    if (a[mid] == x) {
        return mid;
    }
    if (a[mid] > x) {
        return binarySearchRec(a, l, mid - 1, x);
    }
    return binarySearchRec(a, mid + 1, r, x);
 }