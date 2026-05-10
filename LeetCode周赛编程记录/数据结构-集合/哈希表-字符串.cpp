#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=a;i<=b;i++)

void solve(){
	int n;
	cin>>n;
	
	unordered_set<string> a;
	
	while(n--){
		string s;
		cin>>s;
		
		a.insert(s);
	}
	
	int ans=a.size();
	
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}