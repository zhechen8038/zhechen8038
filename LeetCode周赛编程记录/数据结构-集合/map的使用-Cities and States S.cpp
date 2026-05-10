#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=a;i<=b;i++)

void solve(){
	int n;
	cin>>n;
	
	map<string,int> a;//字符串出现的次数，起始值为0
	
	int ans=0;
	
	while(n--){
		string c,s;
		cin>>c>>s;
		
		string s1,c1,s2,c2;
		s2=s.substr(0,2);
		c2=c.substr(0,2);
		s1=s2+" "+c2;//州在前
		c1=c2+" "+s2;//市在前
		
		ans+=a[s1];//一个州有多个市
		if(c2==s2){//特殊情况
			ans-=a[c1];
		}
		a[c1]++;
	}
	
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}