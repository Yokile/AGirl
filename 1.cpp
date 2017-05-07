#include <bits/stdc++.h>

using namespace std;
#define LL long long
#define pb push_back
#define mk make_pair
#define mst(a, b)	memset(a, b, sizeof a)
#define REP(i, x, n)	for(int i = x; i < n; ++i)
const int qq = 1e5 + 10, mod = 1e9 + 7;
int cost[1005];
bool vis[1005];

int main(){
	int t;	scanf("%d", &t);
	while(t--){
		mst(vis, false), mst(cost, 0); 
		int n, k;	scanf("%d%d", &n, &k);
		char st[100], op[100];
		int ans = 0;
		while(k--){
			int x;	scanf("%d", &x);
			x = x - 1000;
			scanf("%s%s", st, op);
			int time = 0;
			for(int i = 0; i < (int)strlen(st) - 3; ++i)
				time = time * 10 + st[i] - '0';
			time = time * 60;
			int minus = 0;
			for(int i = (int)strlen(st) - 2; i < (int)strlen(st); ++i)
				minus = minus * 10 + st[i] - '0';
			time += minus;
			if(strcmp(op, "AC") == 0){
				if(!vis[x])
					ans += time + cost[x];
				vis[x] = true;
			}else{
				cost[x] += 20;
			}
		}
		int num = 0;
		for(int i = 0; i < 1005; ++i)
			if(vis[i])	num++;
		printf("%d %d\n", num, ans);
	}
	return 0;
}