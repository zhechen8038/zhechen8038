#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	vector<long long> dp(n+1,0);
	dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=1;//只有本身时，初始化为1
		//遍历以后面的数作为尾数的个数，并相加
		for(int j=i/2;j>=1;j--){
			dp[i]+=dp[j];
		}
		
	}
	cout<<dp[n];
	return 0;
}