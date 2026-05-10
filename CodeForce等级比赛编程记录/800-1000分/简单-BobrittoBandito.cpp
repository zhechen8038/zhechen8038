#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int n,m,l,r;
	cin>>n>>m>>l>>r;
	int dif=n-m;
	while(dif--){
		if(abs(r)>=abs(l)) r--;
		else l++;
	}
	cout<<l<<" "<<r;
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