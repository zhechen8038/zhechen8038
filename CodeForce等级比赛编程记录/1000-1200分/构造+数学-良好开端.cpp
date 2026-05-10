#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<n ;i++)

void solve(){
	int w,h,a,b,x1,x2,y1,y2;
	cin>>w>>h>>a>>b>>x1>>y1>>x2>>y2;
	
	if(abs(x2-x1)>=a&&abs(x2-x1)%a==0) cout<<"Yes";
	else if(abs(y2-y1)>=b&&abs(y2-y1)%b==0) cout<<"Yes";
	else if(abs(x2-x1)==0&&abs(y2-y1)%b==0) cout<<"Yes";
	else if(abs(y2-y1)==0&&abs(x2-x1)%a==0) cout<<"Yes";
	else cout<<"No";
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
}