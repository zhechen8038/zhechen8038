#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<n ;i++)

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	
	vector<int> a(n,0),b(n,0);
	rep(i,n){
		if(s[i]=='A') a[i]=1;
		else b[i]=1;
	}
	
	if(a[n-1]==1&&a[0]==1){
		cout<<"Alice";
		return;
	}
	if(b[n-1]==1&&b[0]==1){
		cout<<"Bob";
		return;
	}
	
	//A有张牌B都大不了，不然A输
	int flag;
	for(int i=n-1;i>=0;i--){
		flag=0;
		if(!a[i]) continue;
		
		for(int j=n-1;j>=0;j--){
			flag=1;
			if(i==0&&j==n-1) continue;
			if(b[j]&&i==n-1&&j==0){
				flag=0;
				break;
			}
			if(b[j]&&j>i){
				flag=0;
				break;
			}
		}
		
		if(flag==1){
			break;
		}
	}
	
	if(flag==1){
		cout<<"Alice";
	}
	else cout<<"Bob";
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
}