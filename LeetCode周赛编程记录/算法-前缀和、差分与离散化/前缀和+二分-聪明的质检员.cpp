#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i = a; i <= b; i++)

const int INF=1e6;
const int MAX=1e6;

int n,m;
ll s;
int w[MAX],v[MAX];
int l[MAX],r[MAX];

void solve(){
	cin>>n>>m>>s;
	int mx=0;
	rep(i,1,n){
		cin>>w[i]>>v[i];
		mx=max(mx,w[i]);
	}
	
	rep(i,1,m){
		cin>>l[i]>>r[i];
	}
	
	ll ans=LLONG_MAX;//易错点，设置大值
	int L=1,R=mx;
	while(L<=R){
		int mid=(L+R)/2;
		vector<int> x(n+1,0);
		vector<ll> y(n+1,0);
		rep(i,1,n){
			if(w[i]>=mid){
				x[i]=x[i-1]+1;
				y[i]=y[i-1]+v[i];
			}
			else{
				x[i]=x[i-1];
				y[i]=y[i-1];
			}
		}
		
		ll sum=0;
		rep(i,1,m){
			int cnt=x[r[i]]-x[l[i]-1];
			ll val=y[r[i]]-y[l[i]-1];
			sum+=1LL*cnt*val;
		}
		
		ans=min(ans,abs(sum-s));
		
		if(ans==0) break;
		
		if(sum>s){
			L=mid+1;
		}
		else{
			R=mid-1;
		}
	}
	
	cout<<ans;
	
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}