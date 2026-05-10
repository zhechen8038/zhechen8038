//余数相加等于要减的数
//(a+b-3)mod4等价于(a mod 4) + (b mod 4)==3
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		vector<int> count_val(4,0);
		rep(i,n){
			if(i%4==0) count_val[0]++;
			if(i%4==1) count_val[1]++;
			if(i%4==2) count_val[2]++;
			if(i%4==3) count_val[3]++;
		}
		if(count_val[0]==count_val[3]&&count_val[1]==count_val[2]) cout<<"Bob\n";
		else cout<<"Alice\n";
	}
	return 0;
}