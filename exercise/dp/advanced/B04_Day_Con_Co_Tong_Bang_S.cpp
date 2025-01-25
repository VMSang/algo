#include <bits/stdc++.h>
using namespace std;

// chú ý bài toán cơ sở là dp[0] = 1 (tập rỗng), các dp khác bằng 0
// xây dụng từ cuối về đầu để tránh dùng lặp lại một phần tử nhiều lần
// ý tưởng: tại mỗi dp hãy kiểm tra dp tại số đó trừ đi a[i] đang xét có là 1 không
// nếu dúng thì cập nhập dp tại đó lên 1 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
 	int n, s; cin>>n>>s;
 	int a[n];
 	for(int i=0; i<n; i++){
 		cin>>a[i];
 	}   

 	bool dp[s+1] = {0};
 	dp[0] = 1;

 	for(int i=0; i<n; i++){
 		for(int j=s; j >= a[i]; j--){
 			if(dp[j - a[i]]){
 				dp[j] = 1;
 			}
 		}
 	}
 	cout<<dp[s];


    return 0;
}