#include <string>
using namespace std;

string max_palindrome(string s) {
	int maxLength = 0;
	string maxSubstring = "";
	int n = s.size();

	// Podstringovi neparne duzine
	for (int i = 0; i < n; i++) {
		int length = 0;
		while (i - length >= 0 && i + length < n && s[i - length] == s[i + length]) {
			length++;
		}
		if (2 * length - 1 > maxLength) {
			maxLength = 2 * length - 1;
			maxSubstring = s.substr(i - length + 1, 2 * length - 1);
		}
	}

	// Podstringovi parne duzine
	for (int i = 0; i < n - 1; i++) {
		int length = 0;
		while (i - length >= 0 && i + 1 + length < n && s[i - length] == s[i + 1 + length]) {
			length++;
		}
		if (2 * length > maxLength) {
			maxLength = 2 * length;
			maxSubstring = s.substr(i - length + 1, 2 * length);
		}
	}

	return maxSubstring;
}