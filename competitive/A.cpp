/* Wednesday, 05.02.2025 08:42 PM (GMT+7) */
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	while(b != 0){
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int res = a[0];
	for(int i = 1; i < n; i++){
		res = gcd(res, a[i]);
	}
	cout << res;
    
    return 0;
}