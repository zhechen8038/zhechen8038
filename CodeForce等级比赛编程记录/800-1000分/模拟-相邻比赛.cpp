#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)


void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	int sum1,sum2;
	sum1=0;sum2=0;
	rep(i,n){
		int c;
		cin>>c;
		if(c==0) sum1++;
		else sum2++;
		a[i]=c;
	}
	if(sum1==n||sum2==n){
		cout<<"YES";
		return;
	}
	rep(i,n-1){
		if(!a[i]&&!a[i+1]){
			cout<<"YES";
			return;
		}
	}
	cout<<"NO";
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
	return 0;
}