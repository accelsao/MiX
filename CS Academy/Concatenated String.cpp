#include <bits/stdc++.h>
#define LL long long
#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define Re(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
#define REP(I, N) for (int I = 0; I < (N); I++)
#define MID ((l+r)>>1)
#define lc (rt<<1)
#define rc (rt<<1|1)
#define ls lc,l,MID
#define rs rc,MID+1,r
#define st 1,1,n
#define PII pair<int,int>
#define PLL pair<LL,LL>
using namespace std;
const int N=1e5+1;
const int M=1e9+7;
const double eps=1e-6;
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
string a,b;
vector<int>g[26];
int main(){Accel
	cin>>a>>b;
	int n=a.size();
	REP(i,n)g[a[i]-'a'].PB(i);
	int ans=1,j=-1;
	n=b.size();
	REP(i,n){
		if(g[b[i]-'a'].size()==0)return cout<<-1,0;
		auto it=upper_bound(ALL(g[b[i]-'a']),j);
		if(it==g[b[i]-'a'].end())ans++,j=g[b[i]-'a'][0];
		else j=*it;
	}
	cout<<ans<<endl;
}
