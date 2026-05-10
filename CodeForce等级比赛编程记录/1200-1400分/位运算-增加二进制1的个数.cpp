#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

//计算二进制1的个数
ll func(int x){
	int cnt=0;
	for(int i=0;i<=60;i++){
		ll b=(1ll<<i);
		if(x&b) cnt++;
	}
	return cnt;
}

void solve(){
	ll n,k;
	cin>>n>>k;
	vector<int> a(n);
	
	ll cnt=0;
	rep(i,n){
		cin>>a[i];
		//a[i]中0的个数
		cnt+=func(a[i]);
	}
	
	for(int i=0;i<=60;i++){
		//2^j
		ll b=(1ll<<i);
		
		//遍历每一个数
		for(int j=0;j<n;j++){
			//判断j位上是否为0
			if(!(a[j]&b)&&k>=b){
				cnt++;
				k-=b;
			}
		}
	}
	cout<<cnt;
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