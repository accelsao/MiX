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
#define SZ(a) ((int)a.size())
//#pragma GCC optimize(2)
using namespace std;
const int N=5e5+5;
const int M=1e6;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//for(int mask=i;mask>0;mask=(mask-1)&i)
//size() use int
//__gcd, atan2(y,x)=y/x , __int128
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln() , log(x)/log(y)=log(y)-base-x
//watch out LL
//INT_MAX 127,INT_MIN 128
//cout<<fixed<<setprecision(12)<<ans<<endl;
int t;
int a[N],b[N];
LL v[M+5],inv[M+5];
int p[M+5];
map<int,int>A,B;
void build(){
	for(LL i=1;i<=M;i++)
		v[i]=inv[i]=1;
	for(LL i=2;i<=M;i++)
		if(!p[i]){
			for(int j=i;j<=M;j+=i){
				p[j]=1;
				int c=0,t=j;
				while(t%i==0){
				    c++;
				    t/=i;
				}
				if(c%3==1){
					v[j]*=i;
					inv[j]*=i*i;
				}
				else if(c%3==2){
					v[j]*=i*i;
					inv[j]*=i;
				}
			}
		}
}
int main(){Accel
	build();
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        A.clear();B.clear();
        FOR(i,1,n){
			cin>>a[i];
			A[v[a[i]]]++;
		}
        FOR(i,1,m){
			cin>>b[i];
			B[inv[b[i]]]++;
		}
		int l=0,r=0;
		LL ans=-1,c1,c2;
		for(auto x:A){
		    LL a=x.S;
		    LL b=B[x.F];
		    if(a&&b)
		    ans=max(ans,a*a+b*b);
		}
		cout<<ans<<endl;
    }
}
