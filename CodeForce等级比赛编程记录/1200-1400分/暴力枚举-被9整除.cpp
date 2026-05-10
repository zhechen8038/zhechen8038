#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

void solve(){
	string s;
	cin>>s;
	
	int cnt2=0,cnt6=0;//2-2 3-6
	int sum=0;
	int n=s.size();
	rep(i,n){
		if(s[i]=='2') cnt2++;
		if(s[i]=='3') cnt6++;
		sum+=s[i]-'0';
	}
	
	int last=sum%9;
	
	if(last==0){
		cout<<"YES";
		return;
	}
	
	if(cnt2==0&&cnt6==0){
		cout<<"NO";
		return;
	}
	
	rep(i,cnt2+1){
		rep(j,cnt6+1){
			if((2*i+6*j+last)%9==0){
				cout<<"YES";
				return;
			}
		}
	}
	cout<<"NO";
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