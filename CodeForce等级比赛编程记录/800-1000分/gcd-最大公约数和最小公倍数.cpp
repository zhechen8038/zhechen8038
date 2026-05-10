//求以x0为最大公约数，y0为最小公倍数的p,q数对个数
// p = x*a，q = x*b，其中a和b互质且a*b = y/x。这样我们只需要找到满足这些条件的(a,b)对。
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int main(){
	int x,y;
	int ans=0;
	cin>>x>>y;
	
	//判断是否存在
	if(y%x!=0){
		cout<<ans;
		return 0;
	}
	int n=y/x;
	//a和b为质数,且a*b=n
	for(int a=1;a<=sqrt(n);a++){
		if(n%a==0){
			int b=n/a;
			if(gcd(a,b)==1){
				ans+=(a==b)?1:2;//相等加一次，不相等加2次
			}
		}
	}
	
	cout<<ans;
	return 0;
}