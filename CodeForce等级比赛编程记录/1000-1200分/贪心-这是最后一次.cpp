#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

struct obj{
	int l;
	int r;
	int real;
};

bool cmp(const obj a,const obj b){
	return a.l<b.l;
}

void solve(){
	int n,k;
	cin>>n>>k;
	vector<obj> a(n);
	rep(i,n) cin>>a[i].l>>a[i].r>>a[i].real;
	sort(a.begin(),a.end(),cmp);
	int cur=k;
	rep(i,n){
		if(cur<a[i].l) break;
		cur=max(cur,a[i].real);
	}
	cout<<cur;
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