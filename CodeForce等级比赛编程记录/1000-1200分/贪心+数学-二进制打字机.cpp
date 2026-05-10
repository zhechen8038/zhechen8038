#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<n ;i++)

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	
	int sum=0;
	rep(i,n-1){
		if(s[i]!=s[i+1]) sum++;
	}
	
	if(sum==0&&s[0]=='1'){
		sum++;
	}
	else if(sum==2){
		sum--;
	}
	else if(sum>2){
		sum-=2;
		if(s[0]=='1') sum++;
	}
	cout<<n+sum;
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
}