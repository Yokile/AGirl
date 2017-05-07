#include <bits/stdc++.h>

using namespace std;
#define LL long long
#define pb push_back
#define mst(a, b) memset(a, b, sizeof a)
#define REP(i, x, n)	for(int i = x; i < n; ++i)
const int qq = 1e5 + 10;
struct Pt{
	LL x, c;
	bool operator < (const Pt &a)const{
		return x < a.x;
	}
}pt[3005];

int main(){
	int n;	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%lld%lld", &pt[i].x, &pt[i].c);
	}
	
}