#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 20;
const int INF = 9999;

int n, k;
int p[N], pre[105];

void solve(){
	cin >> k >> n;
	for(int i = 1; i <= n; i ++){
		cin >> p[i];
		int x;
		while(1){
			cin >> x;
			if(x == 0) break;
			pre[i] |= (1 << (x - 1));
		}
	}
	
	int Smax = (1 << n);
	vector<double> dp_cur(Smax, 0), dp_pre(Smax, 0);
	
	for(int t = 1; t <= k; t ++){
		for(int s = 0; s < Smax; s ++){
			double sum = 0;
			for(int i = 1; i <= n; i ++){
				double val;
				if((s & pre[i]) != pre[i]){ // 不能满足前置条件
					val = dp_pre[s];
				}
				
				else{
					int s2 = s | (1 << (i - 1)); // 吃了宝物i的新集合
					if(p[i] > 0){ // 正分必吃
						val = dp_pre[s2] + p[i];
					}
					
					else{
						// 负分要么吃，要么不吃，根据期望值大小
						val = max(dp_pre[s], dp_pre[s2] + p[i]);
					}
				}
				sum += val;
			}
			dp_cur[s] = (1.0 / n) * sum; // 计算当前期望
		}
		dp_pre.swap(dp_cur); // 滚动更新
	}
	
	printf("%.6f",dp_pre[0]);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}