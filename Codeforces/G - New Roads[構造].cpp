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
#define PII pair<int,int>
#define PLL pair<LL,LL>
using namespace std;
const int N=2e5+10;
const int M=1e9+7;
const double eps=1e-6;
const double PI(acos(-1.0));
//size() use int
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln()
//watch out LL
int n,k,m;
int d[N];
int main(){Accel
	cin>>n>>m>>k;
	FOR(i,1,m){
		cin>>d[i];
	}
	if(k>n-m){
		cout<<-1<<endl;return 0; 
	}
	FOR(i,1,n-1)
		if(d[i]>d[i+1]){
			k-=d[i]-d[i+1];
		}
	if(k<0){
		cout<<-1<<endl;return 0; 
	}
	cout<<n<<endl;
	for(int l=1,r=1,cur=2,i=1;i<=m;i++){
		int tmp=min(k,min(r-l,d[i]-1));
		k-=tmp;
		l=r-min(r-l,d[i]-1)+tmp;
		if(d[i]<r-l+1){
			l+=(r-l+1)-d[i];
		}
		REP(j,d[i]){
			cout<<l<<" "<<cur<<endl;
			if(l<r)l++;
			cur++;
		}
		l=r+1;
		r+=d[i];
	}
}
