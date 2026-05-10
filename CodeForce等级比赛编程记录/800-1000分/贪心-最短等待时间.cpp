#include<bits/stdc++.h>
using namespace std;

struct people{
	int id;
	int t;
};

bool compare(const people& a,const people& b){
	return a.t<b.t;
}
int main(){
	int n;
	cin>>n;
	vector<people> p(n);
	for(int i=0;i<n;i++){
		p[i].id=i+1;
		cin>>p[i].t;
	}
	sort(p.begin(),p.end(),compare);
	
	long long sum=0;
	for(int i=0;i<n;i++){
		cout<<p[i].id<<" ";
		sum+=p[i].t*(n-1-i);
	}
	cout<<endl;
	
	double res=sum*1.0/n;
	cout<<fixed<<setprecision(2)<<res;
	return 0;
	
}