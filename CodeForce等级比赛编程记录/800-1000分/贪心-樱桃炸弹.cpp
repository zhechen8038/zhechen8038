#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)


void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	vector<int> b(n);
	rep(i,n) cin>>a[i];
	rep(i,n) cin>>b[i];
	int mx=*max_element(a.begin(),a.end());
	int mn=*min_element(a.begin(),a.end());
	
	int sum=-1;
	rep(i,n){
		if(b[i]!=-1){
			if(sum==-1){
				sum=a[i]+b[i];
			}
			if(a[i]+b[i]!=sum){
				cout<<"0";
				return;
			}
		}
	}
	
	if(sum!=-1){
		if(mn+k<sum||mx>sum){
			cout<<"0";
			return;
		}
		cout<<"1";
	}
	else{
		int dif,ans;
		dif=mx-mn;
		if(dif>k){
			cout<<"0";
			return;
		}
		ans=k-dif+1;
		cout<<ans;
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