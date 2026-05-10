#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin>>s;
	int cnt0,cnt1;
	cnt1=0;
	rep(i,n){
		if(s[i]=='1') cnt1++;
	}
	cnt0=n-cnt1;
	if(k>n/2){
		cout<<"NO";
		return;
	}
	int match0,match1;
	match0=cnt0/2;
	match1=cnt1/2;
	
	int min_match;
	min_match=min(match1,match0);
	
	if(match1+match0<k){
		cout<<"NO";
		return;
	}
	if(match1+match0==k){
		cout<<"YES";
		return;
	}
	if(match1+match0>k&&(match1+match0-k)%2==0&&min_match*2>=match1+match0-k){
		cout<<"YES";
		return;
	}
	cout<<"NO";
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
		cout << "\n";
	}
	return 0;
}
