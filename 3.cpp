#include <bits/stdc++.h>

using namespace std;
#define LL long long
#define pb push_back
#define mk make_pair
#define mst(a, b)	memset(a, b, sizeof a)
#define REP(i, x, n)	for(int i = x; i < n; ++i)
const int qq = 1e5 + 10, mod = 1e9 + 7;
LL gcd(LL a, LL b){
	return b == 0 ? a : gcd(b, a % b);
}
LL num[qq];
LL pre[qq], suf[qq];

int main(){
	int t;	scanf("%d", &t);
	while(t--){
		int n;	scanf("%d", &n);
		for(int i = 1; i <= n; ++i){
			scanf("%lld", &num[i]);
		}
		pre[1] = num[1];
		for(int i = 2; i <= n; ++i){
			pre[i] = gcd(pre[i - 1], num[i]);
		}
		suf[n] = num[n];
		for(int i = n - 1; i >= 1; --i){
			suf[i] = gcd(suf[i + 1], num[i]);
		}
		LL ans = 0;
		for(int i = 1; i <= n; ++i){
			if(i == 1)	ans = max(ans, suf[2]);
			else if(i == n)	ans = max(ans, pre[n - 1]);
			else	ans = max(ans, gcd(pre[i - 1], suf[i + 1]));
		}
		printf("%lld\n", ans);
	}
	return 0;
}