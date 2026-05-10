#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

const ll INX=1e9;

void solve(){
	ll n;
	cin>>n;
	vector<pair<ll,ll>> pos(n);
	vector<ll> x(n),y(n);
	vector<ll> xs(n),ys(n);
	
	rep(i,n){
		cin>>pos[i].first>>pos[i].second;
		x[i]=pos[i].first;
		y[i]=pos[i].second;
		xs[i]=pos[i].first;
		ys[i]=pos[i].second;
	}
	
	if(n==1){
		cout<<1;
		return;
	}
	
	sort(xs.begin(),xs.end());
	sort(ys.begin(),ys.end());
	
	ll mn_x=xs[0],mx_x=xs[n-1];
	ll mn_y=ys[0],mx_y=ys[n-1];
	ll ans=(mx_x-mn_x+1)*(mx_y-mn_y+1);
	
	vector<ll> pre_min_x(n),pre_max_x(n),suf_min_x(n),suf_max_x(n);
	vector<ll> pre_min_y(n),pre_max_y(n),suf_min_y(n),suf_max_y(n);
	
	pre_min_x[0]=x[0];pre_max_x[0]=x[0];
	pre_min_y[0]=y[0];pre_max_y[0]=y[0];
	for(int i=1;i<n;i++){
		pre_min_x[i]=min(pre_min_x[i-1],x[i]);
		pre_max_x[i]=max(pre_max_x[i-1],x[i]);
		pre_min_y[i]=min(pre_min_y[i-1],y[i]);
		pre_max_y[i]=max(pre_max_y[i-1],y[i]);
	}
	
	suf_min_x[n-1]=x[n-1];suf_max_x[n-1]=x[n-1];
	suf_min_y[n-1]=y[n-1];suf_max_y[n-1]=y[n-1];
	for(int i=n-2;i>=0;i--){
		suf_min_x[i]=min(suf_min_x[i+1],x[i]);
		suf_max_x[i]=max(suf_max_x[i+1],x[i]);
		suf_min_y[i]=min(suf_min_y[i+1],y[i]);
		suf_max_y[i]=max(suf_max_y[i+1],y[i]);
	}
	
	rep(i,n){
		ll x1,x2,y1,y2;
		if(i==0){
			x1=suf_min_x[i+1];
			x2=suf_max_x[i+1];
			y1=suf_min_y[i+1];
			y2=suf_max_y[i+1];
		}
		else if(i==n-1){
			x1=pre_min_x[i-1];
			x2=pre_max_x[i-1];
			y1=pre_min_y[i-1];
			y2=pre_max_y[i-1];
		}
		else{
			x1=min(suf_min_x[i+1],pre_min_x[i-1]);
			x2=max(suf_max_x[i+1],pre_max_x[i-1]);
			y1=min(suf_min_y[i+1],pre_min_y[i-1]);
			y2=max(suf_max_y[i+1],pre_max_y[i-1]);
		}
		
		ll area=(x2-x1+1)*(y2-y1+1);
		if(area>n-1) ans=min(ans,area);
		else{
			ll area1=area+(y2-y1+1);
			ll area2=area+(x2-x1+1);
			
			if(x2-x1+1==INX) area1=area;
			if(y2-y1+1==INX) area2=area;
			
			area=min(area1,area2);
			ans=min(ans,area);
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