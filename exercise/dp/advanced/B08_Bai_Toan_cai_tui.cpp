#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005], w[1005], v[1005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
 	int n, V;
 	cin>>n>>V;
 	for(int i=1; i<=n; i++) cin>>w[i];
 	for(int i=1; i<=n; i++) cin>>v[i];

 	for(int i=1; i<=n; i++){
 		for(int j=1; j<=V; j++){
 			dp[i][j] = dp[i-1][j];
 			if(j >= w[i]){
 				dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
 			}
 		}
 	}
 	cout<<dp[n][V];
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;s


// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(nullptr);
// 	cout.tie(nullptr);

// 	int n, s;
// 	cin >> n >> s;

// 	int w[n], v[n];

// 	for (int &x : w) cin >> x;
// 	for (int &x : v) cin >> x;

// 	// int dp[n + 1][s + 1];
// 	// //nếu chỉ khởi tạo dp[0][0] thì khi xét dp[i][j - w[i]] có thể ra số không xác định
// 	// memset(dp, 0, sizeof(dp));

// 	// // Thuật toán DP để giải bài toán knapsack
// 	// for (int i = 0; i < n; i++) {
// 	// 	for (int j = 0; j <= s; j++) {
// 	// 		// Mặc định là không lấy
// 	// 		dp[i + 1][j] = dp[i][j];
// 	// 		// Kiểm tra nếu có thể lấy thì có nhận được giá trị lớn hơn không
// 	// 		if (j >= w[i]) {
// 	// 			//nếu có lấy thì phải lấy giá trị của túi có tải còn vừa đủ để chứa w[i] này
// 	// 			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - w[i]] + v[i]);
// 	// 		}
// 	// 		cout<<dp[i + 1][j]<<" ";
// 	// 	}
// 	// 	cout<<endl;
// 	// }

// 	// cout << dp[1][10];

// 	int dp[s + 1];
// 	memset(dp, 0, sizeof(dp));

// 	// Tối ưu hơn, giảm bộ nhớ
// 	for (int i = 0; i < n; i++) {
// 		for (int j = s; j >= w[i]; j--) {
// 			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
// 		}
// 	}

// 	cout << dp[s];

// 	return 0;
// }
