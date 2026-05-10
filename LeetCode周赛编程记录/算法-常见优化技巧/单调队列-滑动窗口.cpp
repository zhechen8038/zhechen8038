#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=a;i<=b;i++)

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1);
	rep(i,1,n) cin>>a[i];
	
	//可以进行两头操作的队列
	deque<int> mx;//存储递减值的下标
	deque<int> mn;//存储递增值的下标
	
	vector<int> ans1;
	vector<int> ans2;
	
	rep(i,1,n){
		//维护队列的大小
		while(!mx.empty()&&i-mx.front()>=k){
			mx.pop_front();
		}
		while(!mn.empty()&&i-mn.front()>=k){
			mn.pop_front();
		}
		
		//维护队列单调性
		while(!mx.empty()&&a[mx.back()]<=a[i]){
			mx.pop_back();
		}
		while(!mn.empty()&&a[mn.back()]>=a[i]){
			mn.pop_back();
		}
		
		//插入元素下标
		mx.push_back(i);
		mn.push_back(i);
		
		if(i>=k){
			ans1.push_back(a[mx.front()]);
			ans2.push_back(a[mn.front()]);
		}
	}
	
	for(int i:ans2) cout<<i<<" ";
	cout<<"\n";
	for(int i:ans1) cout<<i<<" ";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}