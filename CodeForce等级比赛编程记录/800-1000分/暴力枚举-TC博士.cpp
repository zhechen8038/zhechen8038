#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)


void solve(){
	int n;
	string s;
	cin>>n>>s;
	int sum=0;
	int ans=0;
	rep(i,n){
		if(s[i]=='1') sum++;
	}
	rep(i,n){
		int count=sum;
		if(s[i]=='1') count--;
		else count++;
		ans+=count;
	}
	cout<<ans;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
	return 0;
}