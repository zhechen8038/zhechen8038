//组合数问题
#include<bits/stdc++.h>
using namespace std;
//int ans=0;
int n,k;
vector<int> x;

bool check(int t){
	for(int i=1;i<t;i++){
		if(x[i]==x[t]) return false;
	}
	return true;
}

void backTrace(int t,int start){
	if(t>k){
		//ans++;
		for(int i=1;i<=k;i++){
			cout<<x[i]<<" ";
		}
		cout<<endl;
	}
	else{
		//到下一个节点，遍历比自己大的数
		for(int j=start;j<=n;j++){
			x[t]=j;
			if(check(t)){
				backTrace(t+1,j+1);
			}
		}
	}
}

int main(){
	cin>>n>>k;
	x.resize(k+1);
	backTrace(1,1);
	//cout<<ans;
	return 0;
}