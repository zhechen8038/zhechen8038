#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)


void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	sort(a.begin(),a.end());
	int i,j;
	i=0;j=n-1;
	int ans=0;
	if((a[i]+a[j])%2==0){
		cout<<ans;
		return;
	}
	int count1,count2;
	count1=0;count2=0;
	while(i<=n-1&&(a[i++]+a[n-1])%2!=0) count1++;
	while(j>=0&&(a[0]+a[j--])%2!=0) count2++;
	ans+=min(count1,count2);
	cout<<ans;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
	return 0;
}