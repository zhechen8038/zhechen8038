#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> x;
int ans=0;

bool check(int t){
	for(int j=1;j<t;j++){
		if(x[j]==x[t] || abs(j-t)==abs(x[j]-x[t])) return false;
	}
	return true;
}

void backTrace(int t){
	if(t>n){
		ans++;
		for(int i=1;i<=n;i++){
			cout<<x[i]<<" ";
		}
		cout<<endl;
	}
	else{
		//到下一级，遍历所有的列
		for(int j=1;j<=n;j++){
			x[t]=j;
			if(check(t)) backTrace(t+1);//若不冲突，遍历到下一行
		}
	}
}

int main(){
	cin>>n;
	x.resize(n+1);
	backTrace(1);
	cout<<ans;
	return 0;
}