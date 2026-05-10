#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;


vector<int> solve(vector<int> p){
	int n=p.size();
	if(n==1) return p;
	
	int mid=n/2;
	vector<int> l(p.begin(),p.begin()+mid);
	vector<int> r(p.begin()+mid,p.end());
	
	auto l_sorted=solve(l);
	auto r_sorted=solve(r);
	
	vector<int> merged1=l_sorted;
	merged1.insert(merged1.end(),r_sorted.begin(),r_sorted.end());
	
	vector<int> merged2=r_sorted;
	merged2.insert(merged2.end(),l_sorted.begin(),l_sorted.end());
	
	return min(merged1,merged2);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		
		vector<int> a(1<<n);
		rep(i,1<<n) cin>>a[i];
		
		auto ans=solve(a);
		for(int i:ans) cout<<i<<" ";
		cout<<"\n";
	}
	return 0;
}