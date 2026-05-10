#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	
	ll ans=0;
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			int sum=a[i]+a[j];
			int l=j+1,r=n-1;
			if(sum<=a[l]) continue;
			
			int pos=j,less=j;
			while(l<=r){
				int mid=(l+r)/2;
				if(a[mid]<sum){
					if(a[mid]+sum<=a[n-1]) less=mid;
					pos=mid;
					l=mid+1;
				}
				else r=mid-1;
			}
			
			if(pos!=less){
				l=less+1;r=pos-1;
				while(l<=r){
					int mid=(l+r)/2;
					if(a[mid]+sum<=a[n-1]){
						less=mid;
						l=mid+1;
					}
					else r=mid-1;
				}
			}
			
			ans+=pos-less;
		}
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