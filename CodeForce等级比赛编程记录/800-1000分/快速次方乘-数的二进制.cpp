#include<bits/stdc++.h>
using namespace std;

long long fastPow(long long k,int n){
	long long result=1;
	while(n>0){
		if(n&1){
			result*=k;//是奇数就乘上k
		}
		k*=k;
		n>>=1;//整体右移一位，相当于除2
	}
	return result;
}
int main(){
	int k,n;
	cin>>k>>n;
	long long ans=0;
	int a[12];
	memset(a,0,sizeof(a));
	for(int i=0;(i<12)&&n;i++){
		a[i]=n%2;
		n/=2;
	}
	for(int i=0;i<12;i++){
		if(a[i]==1) ans+=fastPow(k,i);
	}
	cout<<ans;
	return 0;
	
	
}