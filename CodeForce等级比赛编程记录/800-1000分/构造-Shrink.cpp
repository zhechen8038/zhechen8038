#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	int low,high;
	low=3;high=n;
	if(n%2==0){
		a[0]=2;
		a[n-1]=1;
	}
	else{
		a[0]=1;
		a[n-1]=2;
	}
	for(int i=1;i<n-1;i++){
		if(i%2==0){
			a[i]=high--;
		}
		else{
			a[i]=low++;
		}
	}
	rep(i,n) cout<<a[i]<<" ";
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		solve();
		cout<<"\n";
	}
	return 0;
}