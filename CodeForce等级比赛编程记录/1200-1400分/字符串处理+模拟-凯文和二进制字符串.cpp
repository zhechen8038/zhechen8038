#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

void solve(){
	string s;
	cin>>s;
	int n=s.size();
	
	int index=0;
	while(index<n&&s[index]=='1') index++;
	
	int len=n-index;
	
	if(len==0){
		cout<<1<<" "<<n<<" "<<1<<" "<<1;
		return;
	}
	
	string ch=s.substr(index,len);
	
	int l=index,r=index+len-1;
	ll mx=0;
	
	for(int i=0;i<=index;i++){
		string cur=s.substr(i,len);
		
		int t=0;
		while(t<len&&ch[t]!=cur[t]) t++;
		
		if(t>mx){
			l=i;r=i+len-1;
			mx=t;
		}
	}
	cout<<1<<" "<<n<<" "<<l+1<<" "<<r+1;
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