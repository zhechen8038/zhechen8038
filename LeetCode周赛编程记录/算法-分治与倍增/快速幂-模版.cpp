#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=1;i<=n;i++)

ll fast_pow(ll a,ll b,ll p){// 将b转换成二进制
	ll res=1%p;
	a%=p;
	
	while(b>0){
		if(b&1){ //当前最低位为1
			res=(res*a)%p;
		}
		a=(a*a)%p; //底数平方
		b>>=1; //指数右移
	}
	return res;
}

void solve(){
	int a,b,p;
	cin>>a>>b>>p;
	string s=to_string(fast_pow(a,b,p));
	string ans=to_string(a)+"^"+to_string(b)+" mod "+to_string(p)+"="+s;
	
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
}