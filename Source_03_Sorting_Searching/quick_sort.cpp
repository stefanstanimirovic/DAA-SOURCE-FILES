void swap(int& a, int& b);

int partition(int arr[], int left, int right) {
	int pivot = arr[right];
	int j = left;
	for (int i = left; i < right; i++) {
		if (arr[i] <= pivot) {
			swap(arr[i], arr[j]);
			j++;
		}
	}
	swap(arr[j], arr[right]);
	return j;
}

void quickSortRec(int arr[], int left, int right) {
	if (left < right) {
		int p = partition(arr, left, right);
		quickSortRec(arr, left, p - 1);
		quickSortRec(arr, p + 1, right);
	}
}

void quickSort(int arr[], int n) {
	quickSortRec(arr, 0, n - 1);
}