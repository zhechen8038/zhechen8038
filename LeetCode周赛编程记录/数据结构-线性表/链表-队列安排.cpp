#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

struct node {
	int l;
	int r;
};

void solve(){
	int n,m;
	cin>>n;
	vector<node> a(n+1);
	vector<bool> deleted(n+1,false);
	
	a[0].l=1;a[0].r=1;
	a[1].l=0;a[1].r=0;
	
	for(int i=2;i<=n;i++){
		int x,y;
		cin>>x>>y;
		if(y==0){
			a[i].l=a[x].l;
			a[i].r=x;
			a[a[x].l].r=i;
			a[x].l=i;
		}
		else{
			a[i].l=x;
			a[i].r=a[x].r;
			a[a[x].r].l=i;
			a[x].r=i;
		}
	}
	
	cin>>m;
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		if(deleted[x]) continue;
		
		a[a[x].l].r=a[x].r;
		a[a[x].r].l=a[x].l;
		
		deleted[x]=true;
	}
	
	int right=a[0].r;
	while(right!=0){
		if(!deleted[right]){
			cout<<right<<" ";
		}
		right=a[right].r;
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}