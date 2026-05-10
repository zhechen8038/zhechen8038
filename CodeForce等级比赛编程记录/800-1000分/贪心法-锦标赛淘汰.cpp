#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		int n,j,k;
		cin>>n>>j>>k;
		vector<int> a(n);
		rep(i,n) cin>>a[i];
		int count_min,count_max;
		count_min=0;count_max=0;
		rep(i,n){
			if(a[i]>a[j-1]) count_max++;
			if(i!=j-1&&a[i]<=a[j-1]) count_min++;
		}
		if(k==n||count_max==0||n-count_min-count_max+1<=k) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}