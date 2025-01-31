/*
[Graph]. Bài 42. Lát đường
Ở 28techland có n thành phố và ban đầu không có đường giữa chúng. Tuy nhiên,
mỗi ngày một con đường mới sẽ được xây dựng và sẽ có tổng cộng m con đường.
Một cụm thành phố là một nhóm các thành phố trong đó có một tuyến đường
giữa hai thành phố bất kỳ bằng cách sử dụng các con đường. Sau mỗi ngày,
nhiệm vụ của bạn là tìm ra số lượng cụm thành phố và kích thước của cụm thành
phố lớn nhất.
Input Format
Dòng đầu tiên có hai số nguyên n và m: số thành phố và đường. Các thành phố
được đánh số 1,2,…, n. Sau đó, có m dòng mô tả các con đường mới. Mỗi dòng có
hai số nguyên a và b: một con đường mới được xây dựng giữa các thành phố a và
b. Bạn có thể cho rằng mọi con đường sẽ được xây dựng giữa hai thành phố khác
nhau.
Constraints
1≤n≤10^5; 1≤m≤2⋅10^5; 1≤a,b≤n;
Output Format
In m dòng: thông tin cần thiết sau mỗi ngày.
Sample Input 0
5 3
1 2
1 3
4 5
Sample Output 0
4 2
3 3
2 3
*/

// #include "precompiled_header.h"
#include <bits/stdc++.h>
using namespace std;

int n,m, MAX = 0;
int parent[100001], sz[100001];

void init(){
	for(int i = 1; i < n+1; i++){
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int v){
	if(v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

bool UNION(int u, int v){
	u = find(u);
	v = find(v);
	if(u == v) return false;
	else if(sz[u] < sz[v]) {
		parent[u] = v;
		sz[v] += sz[u];
		MAX = max(sz[v], MAX);
	}
	else {
		parent[v] = u;
		sz[u] += sz[v];
		MAX = max(sz[u], MAX);
	}
	return true;
}

int main(){
	cin >> n >> m;

	init();
	int cnt = n;
	while(m--){
		int u, v; cin >> u >> v;
		if(UNION(u, v)) cnt--;
		cout << cnt << " " << MAX << "\n";
	}
	return 0;
}