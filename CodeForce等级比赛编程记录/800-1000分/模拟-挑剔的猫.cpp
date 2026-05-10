#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)


void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	int count=0;
	for(int i=1;i<n;i++){
		if(abs(a[i])>abs(a[0])) count++;
	}
	if(n%2==1){
		if(count>=n/2) cout<<"YES";
		else cout<<"NO";
	}
	else{
		if(count>=n/2-1) cout<<"YES";
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