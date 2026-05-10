//矩阵取数游戏
#include <bits/stdc++.h>
using namespace std;
#define N 80

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin>>a[i][j];
    	}
    }
    __int128 ans=0;
    for(int i=0;i<n;i++){
    	vector<vector<__int128>> dp(m,vector<__int128>(m,0));
    	for(int len=1;len<=m;len++){
    		for(int l=0;l<=m-len;l++){
    			int r=l+len-1;
    			int current_step=m-(r-l);
    			__int128 p=1;
    			for(int k=0;k<current_step;k++) p*=2;
    			if(l==r){
    				dp[l][r]=a[i][l]*p;
    			}
    			else{
    				dp[l][r]=max(a[i][l]*p+dp[l+1][r],a[i][r]*p+dp[l][r-1]);
    			}
    		}
    	}
    	ans+=dp[0][m-1];
    }
    // 输出 __int128（需要手动实现）
    if (ans == 0) cout << "0";
    else {
        vector<int> digits;
        while (ans > 0) {
            digits.push_back(ans % 10);
            ans /= 10;
        }
        reverse(digits.begin(), digits.end());
        for (int d : digits) cout << d;
    }
    cout << endl;
    return 0;
}