#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

bool is_blance(ll k,int a){
	string s="";
	
	while(k){
		int c=k%a;
		s+=c+'0';
		k=k/a;
	}
	
	int len;
	len=s.size();
	
	rep(t,len/2){
		if(s[t]!=s[len-1-t]) return false;
	}
	
	return true;
}

void solve(){
	int a;
	ll n;
	cin>>a>>n;
	ll sum=0;
	for(int half=1;;half++){
		string s=to_string(half);
		string rev=s;
		reverse(rev.begin(),rev.end());
		
		//奇数
		string odd=s+rev.substr(1);
		ll val1=stoll(odd);
		if(val1>n) break;
		if(is_blance(val1,a)) sum+=val1;
		
		//偶数
		string even=s+rev;
		ll val2=stoll(even);
		if(val2<=n&&is_blance(val2,a)) sum+=val2;
		
	}
	cout<<sum;
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}