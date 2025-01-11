#include <bits/stdc++.h>
using namespace std;

int main() {
	string s = ""annabelle"";
	int k = 2;

	unordered_set<char> se1;
	for (char c : s) {
		se1.insert(c);
		if (se1.size() == 26)
			break;
	}

	int ans = 0; // count number of palindrome can make
	for (char c : se1) {
		int i = -1, j = 0;
		for (size_t x = 0; x < s.size(); x++) {
			if (s[x] == c) {
				if (i == -1) {
					i = x;
				}
				j = x;
			}
		}

		unordered_set<char> se2;
		se2.insert(c);
		for (int x = i + 1; x < j; x++) {
			se2.insert(s[x]);
		}

		if (se2.size() == se1.size()) {
			ans++;
			if (ans >= k) cout << "co the";
		}
	}
	cout << "khong the";
	return 0;
}