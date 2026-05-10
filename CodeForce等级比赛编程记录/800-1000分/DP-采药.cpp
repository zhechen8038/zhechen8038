#include<bits/stdc++.h>
using namespace std;

int main(){
	int T,n;
	cin>>T>>n;
	vector<int> t(n+1);
	vector<int> v(n+1);
	for(int i=0;i<n;i++){
		cin>>t[i]>>v[i];
	}
	vector<int> dp(T+1,0);
	for(int i=0;i<n;i++){
		for(int j=T;j>=t[i];j--){
			dp[j]=max(dp[j],dp[j-t[i]]+v[i]);
		}
	}
	cout<<dp[T];
	return 0;
}