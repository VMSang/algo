#include <bits/stdc++.h>
using namespace std;

// dp[i][j] lưu độ dài của xâu con chung dài nhất khi KIỂM TRA i kí tự từ xâu 1, và k ki tự từ xâu 2
// kết quả cuối cùng là: dp[n][m] (độ dài của từng xâu)
// Cơ sở: dp[0][j] va dp[i][0] tất cả là 0 (vì không chọn kí tự nào trong xâu còn lại thì làm sao có chung)
// lấy từng kí tự xâu 1 xét với tất cả lần lượt từng kí tự của xâu 2 
// nếu dp[][] = dp[][] thì dp[i][j] = dp[i-1][j-1] + 1
// khac: max(dp[i-1][j], dp[i][j-1])
//  0123456
//	@abzuvt
//	@adxuzv
//   0 1 2 3 4 5 6
//    --------------
// 0 | 0 0 0 0 0 0 0
// 1 | 0 1 1 1 1 1 1
// 2 | 0 1 1 1 1 1 2
// 3 | 0 1 1 1 1 2 2
// 4 | 0 1 1 1 2 2 3
// 5 | 0 1 1 2 2 3 3
// 6 | 0 1 2 2 3 3 3


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);

    string s, t; 
    cin >> s >> t;
    int n = s.length(), m = t.length();
    s = " " + s; t = " " + t; // để dùng chỉ số 1 -> length()

    int dp[n+1][m+1];
    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int i=0; i<=m; i++) dp[0][i] = 0;

    for(int i=1; i<=n; i++){
    	for(int j=1; j<=m; j++){
    		if(s[i] == t[j]){ // nếu không " " thì chỗ này xét s[i-1] == t[i-1]
    			dp[i][j] = dp[i-1][j-1] + 1;
    		}
    		else {
    			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    		}
    	}
    }
    // for(int i=0; i<=n; i++){
    // 	for(int j=0; j<=m; j++){
    // 		cout<<dp[i][j]<<" ";
    // 	}
    // 	cout<<"\n";
    // }
    cout<<dp[n][m];
    return 0;
}
