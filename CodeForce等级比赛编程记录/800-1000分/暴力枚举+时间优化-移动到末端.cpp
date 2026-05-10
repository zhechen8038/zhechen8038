#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)


void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	
	int mx=a[0];
	int index=0;
	for(int i=1;i<n;i++){
		if(mx<a[i]){
			mx=a[i];
			index=i;
		}
	}
	
	ll sum=0;
	rep(k,n){
		if(index<n-k){
			if(k>0){
				sum+=a[n-k];
			}
			sum+=mx;
			cout<<sum<<" ";
			sum-=mx;
		}
		else{
			mx=a[n-k-1];
			for(int i=n-2-k;i>=0;i--){
				if(mx<a[i]){
					mx=a[i];
					index=i;
				}
			}
			if(k>0){
				sum+=a[n-k];
			}
			sum+=mx;
			cout<<sum<<" ";
			sum-=mx;
		}
		
		
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