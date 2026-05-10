#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	string s;
	cin>>s;
	int n=s.size();
	int count=0;
	
	int flag=0;
	for(int i=n-1;i>=0;i--){
		if(s[i]!='0'&&flag==0){
			flag=1;
			continue;
		}
		if(s[i]=='0'){
			if(flag==0) count++;
		}
		else count++;
	}
	cout<<count;
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
}