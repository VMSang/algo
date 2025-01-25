#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    string s, t, z; 
    cin >> s >> t >> z;
    
    int n = s.length(), m = t.length(), k = z.length();
    s = " " + s; t = " " + t; z = " " + z;

    int dp[n+1][m+1][k+1];

    // Khởi tạo giá trị ban đầu cho dp
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            for(int h = 0; h <= k; h++)
                dp[i][j][h] = 0;

    // Tính toán giá trị dp
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int h = 1; h <= k; h++) {
                if(s[i] == t[j] && t[j] == z[h]) {
                    dp[i][j][h] = dp[i-1][j-1][h-1] + 1;
                } else {
                    dp[i][j][h] = max({dp[i-1][j][h], dp[i][j-1][h], dp[i][j][h-1]});
                }
            }
        }
    }
    
    cout << dp[n][m][k] << '\n';
    return 0;
}
