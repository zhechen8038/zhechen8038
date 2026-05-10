#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	int count_a1,count_a2,count_b1,count_b2;
	count_a1=0;count_a2=0;count_b1=0;count_b2=0;
	rep(i,n){
		if(a[i]=='1'){
			if(i%2==0) count_a2++;
			else count_a1++;
		}
		if(b[i]=='0'){
			if(i%2==0) count_b2++;
			else count_b1++;
		}
	}
	if(count_a1<=count_b2&&count_a2<=count_b1) cout<<"YES";
	else cout<<"NO";
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
}