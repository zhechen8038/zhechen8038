#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}

void solve(){
	int n;
	cin>>n;
	vector<ll> p(n),s(n);
	rep(i,n) cin>>p[i];
	rep(i,n) cin>>s[i];
	
	bool ans=1;
	
	//构造中间数组
	vector<ll> x(n);
	rep(i,n){
		x[i]=lcm(p[i],s[i]);
	}
	
	if(x[n-1]!=s[n-1]||x[0]!=p[0]) ans=0;
	
	//验证前缀和后缀
	for(int i=0;i<n-1;i++){
		if(gcd(p[i],x[i+1])!=p[i+1]){
			ans=0;
			break;
		}
	}
	
	for(int i=n-2;i>=0;i--){
		if(gcd(s[i+1],x[i])!=s[i]){
			ans=0;
			break;
		}
	}
	
	if(ans){
		cout<<"YES";
	}
	else cout<<"NO";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		solve();
		cout<<"\n";
	}
}