#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=a;i<=b;i++)

//总结map的使用要确保一一对应关系
map<int,int> cnt;

void solve(){
	int n;
	cin>>n;
	rep(i,1,n){
		int x;
		cin>>x;
		cnt[x]=i;
	}
	
	int q;
	cin>>q;
	
	while(q--){
		int x;
		cin>>x;
		if(cnt.count(x)){
			cout<<cnt[x]<<"\n";
		}
		else cout<<0<<"\n";
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}