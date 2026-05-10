//0/1背包问题，回溯法
#include<bits/stdc++.h>
using namespace std;
int n,c;
int bestp=0;
int cp=0;
int cw=0;
vector<int> p;
vector<int> w;
vector<int> x;
vector<int> bestx;
//计算最大上限
int Bound(int i){
	int cleft=c-cw;//剩余容量
	int b=cp;
	//按照物品单位价值递减装入物品
	while(i<=n&&w[i]<=cleft){
		cleft-=w[i];
		b+=p[i];
		i++;
	}
	//装满背包
	if(i<n) b+=p[i]/w[i]*cleft;
	return b;
	
}
void Backtrack(int i){
	if(i>=n){
		if(cp>bestp){
			bestp=cp;
			bestx=x;
		}
		return;
	}
	if(cw+w[i]<=c){
		cw+=w[i];
		cp+=p[i];
		x[i]=1;
		Backtrack(i+1);
		cw-=w[i];
		cp-=p[i];
	}
	if(Bound(i+1)>bestp){//剪枝
		x[i]=0;
		Backtrack(i+1);
	}
}
int main(){
	cin>>n>>c;
	p.resize(n);
	w.resize(n);
	x.resize(n,0);
	bestx.resize(n,0);
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	for(int i=0;i<n;i++){
		cin>>w[i];
	}
	
	// 按照单位价值排序（降序）
    vector<pair<double, int>> items;
    for (int i = 0; i < n; i++) {
        items.emplace_back(static_cast<double>(p[i]) / w[i], i);
    }
    sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
        return a.first > b.first;
    });
    
    vector<int> temp_p = p, temp_w = w;
    for (int i = 0; i < n; i++) {
        p[i] = temp_p[items[i].second];
        w[i] = temp_w[items[i].second];
    }
    
	Backtrack(0);
	cout<<bestp<<endl;
	
	// 还原原始顺序的输出
    vector<int> original_bestx(n, 0);
    for (int i = 0; i < n; i++) {
        original_bestx[items[i].second] = bestx[i];
    }
    
    for (int i = 0; i < n; i++) {
        cout << original_bestx[i] << " ";
    }
	return 0;
	
}