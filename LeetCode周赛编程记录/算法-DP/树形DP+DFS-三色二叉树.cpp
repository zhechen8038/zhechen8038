#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 1;

string s;
int idx;

vector<vector<int>> dfs(){
	char c = s[idx++];
	vector<vector<int>> res(3, vector<int>(2, 0)); // 3种颜色的最大最小，res[i][0] 为颜色i的最小
	
	if(c == '0'){ // 叶子节点
		res[0] = {0, 0}; // 红色
		res[1] = {1, 1}; // 绿色
		res[2] = {0, 0}; // 蓝色
		return res;
	}
	
	else if(c == '1'){ // 一个子树
		auto child = dfs();
		for(int color = 0; color < 3; color ++){ // 遍历当前节点的3种颜色
			int add = (color == 1); // 绿色要额外加1
			
			// 遍历子树的颜色
			int mn = INT_MAX, mx = -INT_MAX;
			for(int cc = 0; cc < 3; cc ++){
				if(cc == color) continue;
				mn = min(mn, add + child[cc][0]);
				mx = max(mx, add + child[cc][1]);
			}
			
			res[color]= {mn, mx};
		}
		return res;
	}
	
	else{ // 两个子树
		auto left = dfs();
		auto right = dfs();
		
		for(int color = 0; color < 3; color ++){
			int add = (color == 1);
			
			int mn = INT_MAX, mx = -INT_MAX;
			vector<int> other; // 存储子树可选的颜色
			for(int c2 = 0; c2 < 3; c2 ++){
				if(c2 != color) other.push_back(c2);
			}
			
			// 随机分配a,b颜色
			int a = other[0], b = other[1];
			//(a,b)
			mn = min(mn, add + left[a][0] + right[b][0]);
			mx = max(mx, add + left[a][1] + right[b][1]);
			
			//(b,a)
			mn = min(mn, add + left[b][0] + right[a][0]);
			mx = max(mx, add + left[b][1] + right[a][1]);
			
			res[color] = {mn, mx};
		}
		
		return res;
	}
	
}
void solve(){
	cin >> s;
	int n = s.size();
	auto dp_root = dfs();
	
	int mn_ans = INT_MAX, mx_ans = -INT_MAX;
	for(int c = 0; c < 3; c ++){
		mn_ans = min(mn_ans, dp_root[c][0]);
		mx_ans = max(mx_ans, dp_root[c][1]);
	}
	
	cout << mx_ans << " " << mn_ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}