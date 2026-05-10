#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

void solve(){
	int n;
	ll x,y;
	cin>>n>>x>>y;
	ll sum=0;
	vector<ll> a(n);
	rep(i,n){
		cin>>a[i];
		sum+=a[i];
	}
	
	sort(a.begin(),a.end());
	
	ll ans=0;
	
	for(int i=0;i<n-1;i++){
		int l,r;
		
		int mn=i;
		l=i+1;r=n-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(sum-a[i]-a[mid]<=y){
				if(sum-a[i]-a[mid]>=x) mn=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		
		if(mn==i) continue;
		
		int mx=mn;
		l=mn+1;r=n-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(sum-a[i]-a[mid]>=x){
				if(sum-a[i]-a[mid]<=y) mx=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		ans+=mx-mn+1;
	}
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		solve();
		cout<<"\n";
	}
}