#include <bits/stdc++.h>
using namespace std;

//dp[i]: i là số lượng tờ tiền cần để tạo nên S=i;
// ý tưởng: với mỗi tờ tiền kiểm tra cách nó được tạo nếu đã có cách thì tăng thêm 1
// dp[i] = dp[i-c] + 1;

int coin[1000005], dp[1000005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n, s;
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}
	fill(dp, dp+s+1, 1e9);
	dp[0] = 0;
	//for đi qua các tờ tiền
	for (int i = 1; i <= n; i++) {
		//mỗi tờ tiền đi qua từng lượng giá trị
		for (int j = 1; j <= s; j++) {
			if (j >= coin[i]) {
				dp[j] = min(dp[j - coin[i]] + 1, dp[j]);
			}
		}
	}
	if(dp[s] == 0) cout<<-1;
	else cout<<dp[s];

	return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// long long f[1000000];

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(nullptr);
// 	cout.tie(nullptr);

// 	int n, s; cin >> n >> s;
// 	int coin[n];
// 	for (int &x : coin) {
// 		cin >> x;
// 	}

// 	f[0] = 0;
// 	for (long long i = 1; i <= s; i++) {
// 		f[i] = 1e9;
// 		for (int &c : coin){
// 			if (i >= c){
// 				f[i] = min(f[i - c] + 1, f[i]);
// 			}
// 		}
// 	}


// 	cout << ((f[s] == 1e9) ? -1 : f[s]);
// 	return 0;
// }