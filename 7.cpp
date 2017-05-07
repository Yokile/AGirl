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
		int n;	scanf("%d", &n);
		int cnt = 1;
		for(int i = 1; i < n; ++i){
			int x;	scanf("%d", &x);
			if(x == 2){
				cnt++;
			}else{
				if(cnt)	cnt--;
				else	cnt++;
			}
		}
		if(!cnt)	puts("Yes");
		else	puts("No");
	}
	return 0;
}