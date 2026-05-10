#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)


void solve(){
	string s;
	cin>>s;
	int n=s.size();
	int count;
	count=0;
	for(int i=1;i<n-1;i++){
		if(s[i]=='(') count++;
		else count--;
		if(count<0){
			cout<<"YES";
			return;
		}
	}
	if(count==0){
		cout<<"NO";
	}
	else{
		cout<<"YES";
	}
}


int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
	return 0;
}