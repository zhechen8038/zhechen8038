#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)


void solve(){
	int a,b,c;
	cin>>a>>b>>c;
	int dif=b-a;
	if(c-dif-b<0){
		cout<<"NO";
		return;
	}
	if((c-dif-b)%3==0) cout<<"YES";
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
	return 0;
}