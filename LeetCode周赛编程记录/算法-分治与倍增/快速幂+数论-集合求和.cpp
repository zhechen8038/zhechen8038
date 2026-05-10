#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=1;i<=n;i++)

const int MAX=1e5+5;

ll sum;
int cnt;

ll fast_pow(){
	ll res=1;
	int a=2,b=cnt-1;
	while(b>0){
		if(b&1) res*=a;
		a*=a;
		b>>=1;
	}
	return res;
}

void solve(){
	int x;
	while(cin>>x){
		sum+=x;
		cnt++;
	}
	
	ll ans=sum*fast_pow();
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
}