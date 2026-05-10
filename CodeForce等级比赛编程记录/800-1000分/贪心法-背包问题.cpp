#include<bits/stdc++.h>
using namespace std;

struct obj{
	int id;
	int w;
	int p;
	double q;
};

bool cmp1(const obj& a,const obj& b){
	return (a.p*1.0/a.w)>(b.p*1.0/b.w);
}

bool cmp2(const obj& a,const obj& b){
	return a.id<b.id;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	
	cin>>n>>m;
	
	vector<obj> a(n);
	
	for(int i=0;i<n;i++){
		cin>>a[i].id>>a[i].p>>a[i].w;
		a[i].q=0;
	}
	
	sort(a.begin(),a.end(),cmp1);
	
	for(int i=0;i<n;i++){
		if(m>=a[i].w){
			m-=a[i].w;
			a[i].q=1;
		}
		else{
			a[i].q=m*1.0/a[i].w;
			m=0;
			break;
		}
	}
	
	sort(a.begin(),a.end(),cmp2);
	
	for(int i=0;i<n;i++){
		printf("%.2f ",a[i].q);
	}
	
	return 0;
}