#include<bits/stdc++.h>
using namespace std;

struct coin{
	int m;
	int v;
};

bool compare(const coin& a,const coin& b){
	return (a.v*1.0/a.m)>(b.v*1.0/b.m);
}

int main(){
	int n,t;
	cin>>n>>t;
	vector<coin> coins(n);
	for(int i=0;i<n;i++){
		cin>>coins[i].m>>coins[i].v;
	}
	double res=0;
	sort(coins.begin(),coins.end(),compare);
	
	int i;
	for(i=0;i<n;i++){
		if(t>=coins[i].m){
			res+=coins[i].v;
			t-=coins[i].m;
		}
		else break;
	}
	
	if(t>0&&i<n) res+=(coins[i].v*1.0/coins[i].m)*t;
	cout<<fixed<<setprecision(2)<<res;
	
}