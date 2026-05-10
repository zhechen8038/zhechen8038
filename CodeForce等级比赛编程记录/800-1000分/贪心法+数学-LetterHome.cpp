#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(n);i++)


void solve(){
	int n,s;
	cin>>n>>s;
	vector<int> x(n);
	rep(i,n) cin>>x[i];
	x.push_back(s);
	sort(x.begin(),x.end());
	
	n=(int)x.size();
	int index;
	index=find(x.begin(),x.end(),s)-x.begin();
	int ans=0;
	if(abs(x[index]-x[0])<abs(x[index]-x[n-1])){
		ans+=2*abs(x[index]-x[0])+abs(x[index]-x[n-1]);
	}
	else ans+=abs(x[index]-x[0])+2*abs(x[index]-x[n-1]);
	
	cout<<ans;
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