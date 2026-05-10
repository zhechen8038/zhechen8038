//是否构成等比数列
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(n);i++)

bool cmp(ll a,ll b){
	return llabs(a)<llabs(b);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin>>t;
	
	rep(i,t){
		int n;
		cin>>n;
		vector<ll> a(n);
		rep(j,n) cin>>a[j];
		
		if(n==2){
			cout<<"Yes\n";
			continue;
		}
		
		sort(a.begin(),a.end(),cmp);
		
		//公比为1或-1情况
		int count1=1;
		int count2=0;
		for(int j=1;j<n;j++){
			if(a[j]==a[0]) count1++;
			else if(a[j]==a[0]*(-1)) count2++;
			else break;
		}
		if(count1+count2==n){
			if(abs(count1-count2)<=1||count2==0){
				cout<<"Yes\n";
			}
			else cout<<"No\n";
			continue;
		}
		
		if(count1>1||count2>0){
			cout<<"No\n";
			continue;
		}
		
		int flag=0;
		for(int j=1;j<n-1;j++){
			if(a[j]*a[j]!=a[j-1]*a[j+1]){
				flag=1;
				cout<<"No\n";
				break;
			}
		}
		if(flag==0) cout<<"Yes\n";
	}
	return 0;
}