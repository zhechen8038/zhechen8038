#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> b(n);
	rep(i,n) cin>>a[i];
	rep(i,n) cin>>b[i];
	
	stack<int> q;
	
	int j=0;
	
	rep(i,n){
		q.push(a[i]);
		while(!q.empty()&&q.top()==b[j]){
			q.pop();
			j++;
		}
	}
	
	if(q.empty()){
		cout<<"Yes";
	}
	else{
		cout<<"No";
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