// ?i?i?i?????????????????????????????????????????????????????????????????????????i
// ?i?i?i???i?i?i?i?i?i?i???????????????????????????????i?i?i?????????i???????????i
// ?i?i?i?i?i?i?i???i?i?i?i?i???????????????????????i?i?i?????????????????????????i
// ?i?i?i?i???????????????i?i?i?i?i????????????i?i?i????????????????????????????i
// ?i?i?i???????????????????????i?i???????????????????????????????????????????????i
// ?i?i?i?i???????????????????????i???????????????????????????????????????????????i
// ?i?i?i???i???i?i?i?i?i?i?i?????i?i?i?????????????????i?i?i?i?i?i?i?????????????i
// ?i?i?i?i?i?i?i?i?i?i?i?i?i?i?i?i???i??????????????????????????????????????????i
// ?i?i?i?????????????????????????????i???????????????????????????????????????????i
// ?i?i?i?i???????????????????????????i???????????????????????????????????????????i
// ?i?i?i???i?????????????????????????????????????????????????????????????????????i
// ?i?i?i?i?i?????????????????i???????i???????????????????????????????????????????i
// ?i?i?i?i?i???????????????i?i???????i????????????????????????????????????????i?i
// ?i?i?i?i?i???????????i?i?i?i???????i????????????????????????????????????????i?i
// ?i?i?i?i???i?????????i?i?????????i?i????????????????????????????????????????i?i
// ?i?i?i?i?????i?i?i???????????????i?i??????????????????????????i?????????????i?i
// ?i?i?i?i?i???i?i?i?????????????????i?i?i?i??????????????????i???????????????i?i
// ?i?i?i?i?i?????i???i?i?i???????i?i?i?i?????i???????????????i??????????????i?i?i
// ?i?i?i?i?i?i???i?i???i?i?i?i?i?i?i???????????????????i?i???????????????????i?i?i
// ?i?i?i?i?i?i?i???i?i????????????????????????????????????????????????????i?i?i?i
// ?i?i?i?i?i?i?i?????i?i???????????????????????????????????????????????????i?i?i?i
// ?i?i?i?i?i?i?i?i???????i?i?i?i?i???????????????????????????????????????i?i?i?i?i
// ?i?i?i?i?i?i?i?i?i???????i???????????i?i?i???????????????????????????i?i?i?i?i?i
// ?i?i?i?i?i?i?i?i?i?i???????i???????????i?i?????????????????????????i?i?i?i?i?i?i
// ?i?i?i?i?i?i?i?i?i?i?i?????i?????????i?i?i???????????????????????i?i?i?i?i?i?i?i
// ?i?i?i?i?i?i?i?i?i?i?i?i?i?i???????i?i?i????????????????????i?i?i?i?i?i?i?i?i?i
// ?i?i?i?i?i?i?i?i?i?i?i?i?i?i?i???????i?i???????????????????i?i?i?i?i?i?i?i?i?i?i
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
//#define DEBUG
#define RE(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define SZ(x) ((int)(x.size()))
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int,int>;
using C = complex<double>;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
    
const double PI = 3.14159265;
const double eps = 1e-8;
const int N = 1e6 +10;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;
ll pw(ll a, ll b){ll t=1;a%=M;for(;b;b>>=1){if(b&1){t=t*a%M;}a=a*a%M;}return t;}
ll gcd(ll a, ll b){return b?gcd(b, a%b): a;}

int n, m, q;
int a[N];
int ans[N];
vector<int> g[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		a[x]++;
	}

	for(int i=1;i<=m;i++){
		g[a[i]].PB(i);
	}
	vector<pair<ll, int>> qry(q);
	for(int i=0;i<q;i++){
		cin>>qry[i].F;
		qry[i].S=i;
	}
	sort(qry.begin(),qry.end());
	ll sum=n;
	ordered_set<int> pos;
	int j=0;
	for(int i=0;i<=n;i++){
		for(int x:g[i]){
			pos.insert(x);
//			pos.insert(upper_bound(ALL(pos), x), x);
		}
		while(j<q&&sum+(int)pos.size()>=qry[j].F){
			int k=(qry[j].F-sum-1)%((int)pos.size());
//			ans[qry[j].S]=pos.upper_bound(k)-pos.begin();
			#ifdef DEBUG
				printf("k: %d\n", k);
				for(const int& x:pos){
					printf("%d ", x);
				}
				printf("\n");
			#endif

			ans[qry[j].S]=*pos.find_by_order(k);
//			ans[qry[j].S]=pos[k];
			j++;
		}
		sum+=(int)pos.size();
	}
	while(j<q){
		int k=(qry[j].F-sum-1)%m;
		ans[qry[j].S]=*pos.find_by_order(k);
//		ans[qry[j].S]=pos[k];
		j++;
	}
	for(int i=0;i<q;i++){
		cout<<ans[i]<<"\n";
	}
}

/*
#ifdef DEBUG
	cout<<"I Love Co shu Nie [ https://coshunie.com/ ]"
#endif
*/
