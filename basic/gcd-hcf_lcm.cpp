/* Wednesday, 05.02.2025 07:48 PM (GMT+7) */
#include <bits/stdc++.h>
using namespace std;

// by Euclid: a > b, gcd(a, b) = gcd(b, b-a), if a == b then gcd(a,b) == a
int gcd_Euclidean_recursion (int a, int b){
	if(a==b) return a;
	return gcd(min(a, b), abs(a-b));
}
 int gcd_Euclidean(int a, int b){
 	if(a==0 || b==0) return a+b;
 	while(a != b){
 		if (a > b) a -= b;
 		else b -= a;
 	}
 	return a;
 }

// otimize: gcd(a,b) = gcd(b, a%b), if b = 0 then gcd(a, b) = a
int gcd_otimize_recursion(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int gcd_otimize(int a, int b){
	while(b != 0){
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

// LCM
int LCM(int a, int b){
	return a*__gcd(a, b) * b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b; cin >> a >> b;

    return 0;
}