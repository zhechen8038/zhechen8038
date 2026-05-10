#include<bits/stdc++.h>
using namespace std;

priority_queue<int> mx_hp; // 大顶堆
priority_queue<int, vector<int>, greater<int>> mn_hp; // 小顶堆，存储获奖的
// 无论是 大顶堆 还是 小顶堆，都会自动调整堆的结构

int now;

//插入堆中
void push(int num){
	if(num>mx_hp.top()){
		mn_hp.push(num);
	}
	else mx_hp.push(num);
}

//调整堆
void adjust(){
	if((int)mn_hp.size()>now){
		mx_hp.push(mn_hp.top());
		mn_hp.pop();
	}
	if((int)mn_hp.size()<now){
		mn_hp.push(mx_hp.top());
		mx_hp.pop();
	}
}

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    mx_hp.push(0);
    
    for(int i=1;i<=n;i++){
    	now=max(1,i*w/100);
    	
    	push(a[i]);
    	adjust();
    	
    	cout<<mn_hp.top()<<" ";
    }

    
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
