void swap(int& a, int& b);

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSortRec(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSortRec(arr, low, p - 1);
        quickSortRec(arr, p + 1, high);
    }
}

void quickSort(int arr[], int n) {
    quickSortRec(arr, 0, n - 1);
}