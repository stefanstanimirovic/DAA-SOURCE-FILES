#include <vector>
#include <iostream>
using namespace std;

void sumSubsets(int set[], int size, int n, int k) {
	// Create the new array with size
	// equal to array set[] to create
	// binary array as per n(decimal number)
	vector<int> x(size);
	int j = size - 1;

	// Convert the array into binary array
	while (n > 0) {
		x[j] = n % 2;
		n = n / 2;
		j--;
	}

	int sum = 0;
	// Calculate the sum of this subset
	for (int i = 0; i < size; i++) {
		if (x[i] == 1) {
			sum = sum + set[i];
		}
	}

	// Check whether sum is equal to k
	// if it is equal, then print the subset
	if (sum == k) {
		for (int i = 0; i < size; ++i) {
			if (x[i] == 1) {
				cout << set[i] << " ";
			}
		}
		cout << endl;
	}
}

// Function to find the subsets with sum k
void findSubsets(int arr[], int n, int k) {
	// Calculate the total no. of subsets
	int x = pow(2, n);

	// Run loop till total no. of subsets
	// and call the function for each subset
	for (int i = 1; i < x; i++) {
		sumSubsets(arr, n, i, k);
	}
}