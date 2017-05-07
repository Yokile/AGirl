#include <bits/stdc++.h>

using namespace std;
#define LL long long
#define pb push_back
#define mk make_pair
#define mst(a, b)	memset(a, b, sizeof a)
#define REP(i, x, n)	for(int i = x; i < n; ++i)
const int qq = 55, mod = 1e9 + 7;
char st[qq];
int mar[qq][qq], dist[qq][qq];
int n;

int main(){
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; ++i){
			scanf("%s", st);
			for(int j = 0; j < n; ++j){
				mar[i][j] = st[j] - '0';
				dist[i][j] = st[j] - '0';
			}
		}
		for(int k = 0; k < n; ++k)
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j){
					if(i == j)	continue;
					if(dist[i][k] && dist[k][j]){
						if(!dist[i][j])	dist[i][j] = dist[i][k] + dist[k][j];
						else 	dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
					}
				}
		bool flag = true;
		for(int i = 1; i < n; ++i)
			if(dist[0][i] == 0)	flag = false;
		if(!flag){
			printf("0\n");
			continue;
		}
		LL ans = 1;
		for(int i = 1; i < n; ++i){
			int k = 0;
			for(int j = 0; j < n; ++j){
				if(!mar[i][j])	continue;
				if(mar[i][j] + dist[j][0] == dist[i][0])
					k++;
			}
			ans = (ans * k) % mod;
		}
		printf("%lld\n", (ans + mod) % mod);
	}
	return 0;
}