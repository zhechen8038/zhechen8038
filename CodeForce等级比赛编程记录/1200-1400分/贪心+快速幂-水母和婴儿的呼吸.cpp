#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

const int N=1e5+5;
const ll mod=998244353;

vector<ll> s(N);

//提前处理
void func(){
	s[0]=1;
	for(int i=1;i<N;i++) s[i]=s[i-1]*2%mod;
}

//二进制实现快速幂
// ll modpow(ll a,ll b,ll m){
	// ll res=1;
	// while(b>0){
		// if(b&1) res=res*a%m;
		// a=a*a%m;
		// b>>=1;
	// }
	// return res;
// }

void solve(){
	int n;
	cin>>n;
	
	vector<int> p(n);
	vector<int> q(n);
	rep(i,n) cin>>p[i];
	rep(i,n) cin>>q[i];
	
	vector<ll> r(n);
	
	for(int i=0,j=0,k=0;k<n;k++){
		if(p[k]>p[i]) i=k;
		if(q[k]>q[j]) j=k;
		if(p[i]!=q[j]){
			if(p[i]>q[j]){
				r[k]=(s[p[i]]+s[q[k-i]])%mod;
			}
			else{
				r[k]=(s[p[k-j]]+s[q[j]])%mod;
			}
		}
		else{
			r[k]=(s[p[i]]+s[max(p[k-j],q[k-i])])%mod;
		}
	}
	
	rep(i,n) cout<<r[i]<<" ";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	func();
	int t;
	cin>>t;
	
	while(t--){
		solve();
		cout<<"\n";
	}
}