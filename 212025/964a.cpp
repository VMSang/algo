/*
Hôm nay mình chưa làm sớm nên chỉ kịp làm bài rất đơn giản này
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;

	while (n--){
		int x; cin >> x;
		long sum = 0;
		while (x){
			sum+=x%10;
			x/=10;
		}
		cout<<sum<<"\n";
	}

    return 0;
}