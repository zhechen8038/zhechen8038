//矩阵连乘问题
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int p[n+1];
    for(int i=0;i<n+1;i++){
        cin>>p[i];
    }
    int dp[n][n];
    for(int i=0;i<n;i++){
        dp[i][i]=0;
    }
    for(int l=2;l<=n;l++){
        for(int i=0;i<=n-l;i++){
        	int j=i+l-1;
        	dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][k]+dp[k+1][j]+p[i]*p[k+1]*p[j+1],dp[i][j]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}