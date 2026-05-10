#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)


void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int> ans(n);
	int mx,mn;
	mx=n;mn=1;
	for(int i=n-2;i>=0;i--){
		if(s[i]=='<'){
			ans[i+1]=mn;
			mn++;
		}
		else{
			ans[i+1]=mx;
			mx--;
		}
	}
	ans[0]=mn;
	rep(i,n) cout<<ans[i]<<" ";
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