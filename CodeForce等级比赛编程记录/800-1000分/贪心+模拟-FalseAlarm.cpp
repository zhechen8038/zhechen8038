#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int n,x;
	cin>>n>>x;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	int flag=0;
	rep(i,n){
		if(a[i]==1){
			if(flag==0) flag=1;
			if(x<=0){
				cout<<"NO";
				return;
			}
		}
		if(flag==1) x--;
	}
	cout<<"YES";
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		solve();
		cout<<"\n";
	}
	return 0;
}