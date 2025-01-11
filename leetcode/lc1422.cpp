class Solution {
public:
    int maxScore(string s) {
        vector<int> pf1(s.size());
	if (s[0] == '1') pf1[0] = 1;
	else pf1[0] = 0;

	for (size_t i = 1; i < s.size(); i++) {
		pf1[i] = pf1[i-1] + (s[i] == '1' ? 1 : 0);
	}

	
	// -----
	vector<int> pf0(s.size());
	if (s[0] == '0') pf0[0] = 1;
	else pf0[0] = 0;

	for (size_t i = 1; i < s.size(); i++) {
		pf0[i] = pf0[i-1] + (s[i] == '0' ? 1 : 0);
	}
	// for(size_t i = 0; i < pf0.size(); i++){
	// 	cout << pf0[i] << " ";
	// }
	// -----
	long max = INT_MIN;
	for (size_t i = 0; i < s.size() - 1; i++) {
		long cal = pf0[i] + pf1[s.size() - 1] - pf1[i];
		if (cal > max) max = cal;
	}
        return max;
    }
};