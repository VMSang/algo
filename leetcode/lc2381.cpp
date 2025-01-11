#include <bits/stdc++.h>
using namespace std;

int main() {
	string s = "dztz";
	vector<vector<int>> shifts = {{0, 0, 0}, {1, 1, 1}};

	vector<int> da(s.size() + 1);
	for (auto x : shifts) {
		if (x[2] == 1) {
			da[x[0]] += 1;
			da[x[1] + 1] -= 1;
		} else {
			da[x[0]] -= 1;
			da[x[1] + 1] += 1;
		}
	}

	vector<int> pf(s.size());
	pf[0] = da[0];
	for (int i = 1; i < s.size(); i++) {
		pf[i] = pf[i - 1] + da[i];
	}

	// for(int x : pf){s
	// 	cout<< x << " ";
	// }

	// for (int i = 0; i < s.size(); i++) {
	// 	int cal = pf[i] % 26;
	// 	if (cal >= 0) {
	// 		if((s[i] + cal) > 'z'){
	// 			s[i] = (char)('a' + ((s[i] + cal) - 'z') - 1);
	// 		} else {
	// 			s[i] += cal;
	// 		}
	// 	} else {
	// 		if (('a' - cal) > 'a') {
	// 			s[i] = s[i] + cal;
	// 		} else {
	// 			// cout << 'z' - ('a' - (s[i] + cal));
	// 			s[i] = 'z' - ('a' - (s[i] + cal));
	// 		}
	// 	}
	// }
	for (int i = 0; i < s.size(); i++) {
		int shiftedValue = (s[i] - 'a' + pf[i]) % 26;
		if (shiftedValue < 0) {
			shiftedValue += 26;
		}
		s[i] = 'a' + shiftedValue;
	}
	cout << s;	return 0;
}