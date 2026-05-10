#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)


void solve(){
	int x;
	cin>>x;
	int min_val,max_val,second_val;
	min_val=0;max_val=0;second_val=0;
	int ans=1;
	while(min_val<x){
		int c=max_val;
		max_val=second_val*2+1;;
		second_val=c;
		min_val=second_val;
		ans++;
	}
	cout<<ans;
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