//动态规划（递归）+高精度
#include<bits/stdc++.h>
using namespace std;

string add(string a,string b){
	string res;
	int carry=0;
	int i=a.size()-1;
	int j=b.size()-1;
	while(i>=0||j>=0||carry){
		int na=(i>=0)?(a[i]-'0'):0;
		int nb=(j>=0)?(b[j]-'0'):0;
		int sum=na+nb+carry;
		res.push_back(sum%10+'0');
		carry=sum/10;
		i--;
		j--;
	}
	reverse(res.begin(),res.end());
	return res;
}
string func(int n){
	if(n==1) return "1";
	if(n==2) return "2";
	string a="1",b="2",c;
	for(int i=3;i<=n;i++){
		c=add(a,b);
		a=b;
		b=c;
	}
	return b;
}
int main(){
	int n;
	cin>>n;
	string ans=func(n);
	cout<<ans;
	return 0;
}