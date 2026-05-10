#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

void solve(){
	ll n,m;
	cin>>n>>m;
	ll mn=n;
	ll mx=1LL*n*(n+1)/2;
	if(m>mx||m<mn){
		cout<<"-1";
		return;
	}
	
	ll dif=m-mn;
	int index,val;
	index=n;
	val=1;
	vector<int> a(n+1);
	for(int i=n-1;i>=0;i--){
		if(dif>=i){
			a[n-i-1]=i+1;
			dif-=i;
		}
		else{
			a[n-i-1]=dif+1;
			val=dif+1;
			index=n-i;
			dif=0;
			break;
		}
	}
	int k=1;
	for(int i=index;i<n;i++){
		if(k!=val){
			a[i]=k;
			k++;
		}
		else{
			k++;
			a[i]=k;
			k++;
		}
	}
	cout<<a[0]<<"\n";
	rep(i,n-1){
		cout<<a[i]<<" "<<a[i+1];
		if(i!=n-2) cout<<"\n";
	}
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