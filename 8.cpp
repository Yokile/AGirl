#include <bits/stdc++.h>

using namespace std;
#define LL long long
#define pb push_back
#define mk make_pair
#define mst(a, b)	memset(a, b, sizeof a)
#define REP(i, x, n)	for(int i = x; i < n; ++i)
const int qq = 1e5 + 10, mod = 1e9 + 7;
char st[15];
int f[105], num, dis;
int prime[] = {2, 3, 5, 7, 11, 13};
int n = 3;

void Dfs(int id){
	if(id == dis){
		for(int i = 0; i < 6; ++i){
			for(int j = prime[i] - 1; j < id; ++j){
				int a, b;	a = b = 0;
				for(int k = j - prime[i] + 1; k <= j; ++k)
					if(st[k] == 'a')	a++;
					else	b++;
				if(b > a)	return;
			}
		}
		num++;
		return;
	}
	st[id] = 'a';
	Dfs(id + 1);
	st[id] = 'b';
	Dfs(id + 1);
	return;
}

void Init(){
	for(int i = 4; i <= 10; ++i){
		dis = i, num = 0;
		Dfs(0);
		f[i] = num;
	}
	f[1] = 0;
	f[2] = 3;
	f[3] = 4;
	for(int i = 1; i <= 15; ++i){
		printf("%d ", f[i]);
	}
	puts("");
}

struct Mar{
	LL mar[3][3];
	Mar(){
		mst(mar, 0);
	}
	Mar operator * (const Mar &a){
		Mar tmp;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				for(int k = 0; k < n; ++k)
					tmp.mar[i][j] = (tmp.mar[i][j] + (mar[i][k] * a.mar[k][j]) % mod + mod) % mod;
		return tmp;
	}
};
Mar Quickpow(LL k){
	Mar tmp;
	Mar t;
	t.mar[0][0] = t.mar[0][2] = t.mar[1][0] = t.mar[2][1] = 1;
	for(int i = 0; i < n; ++i)
		tmp.mar[i][i] = 1;
	while(k){
		if(k & 1)	tmp = tmp * t;
		t = t * t;
		k >>= 1;
	}
	return tmp;
}

int main(){
//	Init();
	int t;	scanf("%d", &t);
	while(t--){
		LL n;	scanf("%lld", &n);
		if(n == 2){
			puts("3");
		}else if(n == 3){
			puts("4");
		}else{
			Mar ans = Quickpow(n - 4);
			LL g = (6 * ans.mar[0][0] + 4 * ans.mar[0][1] +  3 * ans.mar[0][2] + mod) % mod;
			printf("%lld\n", (g + mod) % mod);
		}
	}
	return 0;
}
