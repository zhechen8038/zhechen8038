#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int n,k;
	cin>>n>>k;
	string s,a;
	cin>>s;
	a=s;
	reverse(a.begin(),a.end());
	int flag=0;
	rep(i,n-1){
		if(s[i]!=s[i+1]){
			flag=1;
			break;
		}
	}
	
	if(n==1||flag==0){
		cout<<"NO";
		return;
	}
	
	if(s<a) cout<<"YES";
	else{
		if(k==0) cout<<"NO";
		else cout<<"YES";
	}
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