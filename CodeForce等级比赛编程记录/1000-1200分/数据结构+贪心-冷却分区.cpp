#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	
	//统计前缀不同元素个数
	unordered_set<int> num;
	vector<int> dif(n);
	rep(i,n){
		num.insert(a[i]);
		dif[i]=num.size();
	}
	
	int ans=0;
	int r=n-1;
	unordered_set<int> fre;
	for(int i=n-1;i>=0;i--){
		fre.insert(a[i]);
		int cur=fre.size();
		if(cur==dif[r]){
			ans++;
			r=i-1;
			fre.clear();//清空统计
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