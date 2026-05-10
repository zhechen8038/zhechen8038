#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i = a; i <= b; i++)

const int MAX=1e7;

struct node{
	ll l,r;
};

bool cmp(const node& a,const node& b){
	return a.l<b.l;
}

void solve(){
	int n;
	cin>>n;
	vector<node> s(n);
	
	rep(i,0,n-1){
		cin>>s[i].l>>s[i].r;
	}
	
	sort(s.begin(),s.end(),cmp);
	
	ll ans=0;
	ll L=s[0].l,R=s[0].r;
	rep(i,1,n-1){
		if(s[i].l>R){
			ans+=R-L;
			L=s[i].l;R=s[i].r;
		}
		else{
			R=max(R,s[i].r);
		}
	}
	
	ans+=R-L;
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}