//记忆化递归+高精度
#include<bits/stdc++.h>
using namespace std;
int cal[5001]={0};
string m[5001];

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
	else if(n==2) return "2";
	if(cal[n]!=0) return m[n];
	m[n]=add(func(n-1),func(n-2));
	cal[n]=1;
	return m[n];
}

int main(){
	int n;
	cin>>n;
	string ans=func(n);
	cout<<ans;
	return 0;
}