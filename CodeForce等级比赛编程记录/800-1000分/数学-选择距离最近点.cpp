#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

void solve(){
	int a,x,y;
	cin>>a>>x>>y;
	if(a>x&&a<y) cout<<"NO";
	else if(a<x&&a>y) cout<<"NO";
	else cout<<"YES";
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
