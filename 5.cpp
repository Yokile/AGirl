#include <bits/stdc++.h>

using namespace std;
#define LL long long
#define pb push_back
#define mk make_pair
#define mst(a, b)	memset(a, b, sizeof a)
#define REP(i, x, n)	for(int i = x; i < n; ++i)
const int qq = 1e5 + 10, mod = 1e9 + 7;

int main(){
	int t;	scanf("%d", &t);
	while(t--){
		int n, k;	scanf("%d%d", &n, &k);
		LL ans = 1;
		for(int i = 2; i <= n; ++i){
			LL w = 1;
			for(int j = 1; j <= k; ++j)
				w = (w * i + mod) % mod;
			ans = (ans + w + mod) % mod;
		}
		printf("%lld\n", (ans + mod) % mod);
	}
	return 0;
}