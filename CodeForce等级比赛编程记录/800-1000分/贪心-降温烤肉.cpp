#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

void solve(){
	int k,a,b,x,y;
	cin>>k>>a>>b>>x>>y;
	int ans=0;
	if(k<a&&k<b){
		cout<<ans;
		return;
	}
	if(x<y){
		if(k>=a){
			ans+=(k-a)/x+1;
			k-=((k-a)/x+1)*x;
		}
		if(k>=b){
			ans+=(k-b)/y+1;
			k-=((k-b)/y+1)*y;
		}
	}
	else{
		if(k>=b){
			ans+=(k-b)/y+1;
			k-=((k-b)/y+1)*y;
		}
		if(k>=a){
			ans+=(k-a)/x+1;
			k-=((k-a)/x+1)*x;
		}
	}
	cout<<ans;
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
