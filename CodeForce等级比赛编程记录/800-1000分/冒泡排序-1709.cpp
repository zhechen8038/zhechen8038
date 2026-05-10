#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

void solve(){
	int n;
	cin>>n;
	
	vector<int> a(n),b(n);
	rep(i,n) cin>>a[i];
	rep(i,n) cin>>b[i];
	
	vector<pair<int,int>> tr;
	for(int i=0;i<n-1;i++){
		int flag=0;
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				tr.push_back({1,j+1});
				flag=1;
			}
		}
		if(flag==0) break;
	}
	for(int i=0;i<n-1;i++){
		int flag=0;
		for(int j=0;j<n-i-1;j++){
			if(b[j]>b[j+1]){
				swap(b[j],b[j+1]);
				tr.push_back({2,j+1});
				flag=1;
			}
		}
		if(flag==0) break;
	}
	for(int i=0;i<n;i++){
		if(a[i]>b[i]){
			swap(a[i],b[i]);
			tr.push_back({3,i+1});
		}
	}
	cout<<tr.size()<<"\n";
	for(auto &p:tr){
		cout<<p.first<<" "<<p.second<<"\n";
	}
	
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		solve();
	}
}