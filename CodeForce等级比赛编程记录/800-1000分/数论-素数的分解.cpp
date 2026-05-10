#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

bool isPrime(int x){
	if(x<=1) return false;
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}

void solve(){
		int x,k;
	cin>>x>>k;
	if(x>1&&k>1){
		cout<<"NO";
	}
	else if(k==1){
		if(isPrime(x)) cout<<"YES";
		else cout<<"NO";
	}
	else if(x==1){
		string s(k,'1');
		int sum=stoll(s);
		if(isPrime(sum)) cout<<"YES";
		else cout<<"NO";
	}
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