#include <vector>
#include <iostream>
using namespace std;

void display(const vector<int>& v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}

void printSubsetsRec(int arr[], int i, int k, vector<int>& p, vector<vector<bool>> dp) {
	if (i == 0 && k != 0 && dp[0][k]) {
		p.push_back(arr[i]);
		if (arr[i] == k) {
			display(p);
		}
		return;
	}

	if (i == 0 && k == 0) {
		display(p);
		return;
	}

	if (dp[i - 1][k]) {
		vector<int> b = p;
		printSubsetsRec(arr, i - 1, k, b, dp);
	}

	if (k >= arr[i] && dp[i - 1][k - arr[i]]) {
		p.push_back(arr[i]);
		printSubsetsRec(arr, i - 1, k - arr[i], p, dp);
	}
}

void printAllSubsets(int arr[], int n, int k)
{
	if (n == 0 || k < 0)
		return;

	vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, true));
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = true;
	}

	if (arr[0] <= k) {
		dp[0][arr[0]] = true;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			dp[i][j] = (arr[i - 1] <= j) 
				? dp[i - 1][j] || dp[i - 1][j - arr[i - 1]]
				: dp[i - 1][j];
		}
	}
	if (dp[n - 1][k] == false) {
		printf("There are no subsets with sum %d\n", k);
		return;
	}

	vector<int> p;
	printSubsetsRec(arr, n - 1, k, p, dp);
}