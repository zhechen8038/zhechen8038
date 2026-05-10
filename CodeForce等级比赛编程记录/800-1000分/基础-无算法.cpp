//回文数
#include<bits/stdc++.h>
#include <cstring>
using namespace std;
#define N 100
int check_func(char a[]){
	int n=strlen(a);
	for(int i=0;i<n/2;i++){
		if(a[i]!=a[n-1-i]) return 0;
	}
	return 1;
}
void sum_func(char a[],int n,char b[]){
	int len=strlen(a);
	int s=0;
	int index=0;
	for(int i=0;i<len;i++){
		int x,y;
		int x_value,y_value;
		if(a[i]<='9'&&a[i]>='0'){
			x_value=a[i]-'0';
		}
		else{
			x_value=10+(a[i]-'A');
		}
		if(a[len-1-i]<='9'&&a[len-1-i]>='0'){
			y_value=a[len-1-i]-'0';
		}
		else{
			y_value=10+(a[len-1-i]-'A');
		}
		x=(x_value+y_value+s)/n;
		y=(x_value+y_value+s)%n;
		if(y>=10) b[index++]=(y-10)+'A';
		else b[index++]=y+'0';
		s=x;
	}
	if(s>0){
		if(s>=10) b[index++]=(s-10)+'A';
		else b[index++]=s+'0';
	}
}
int main(){
	int n;
	char a[N],b[N];
	cin>>n>>a;
	if(check_func(a)) cout<<"STEP=0"<<endl;
	else{
		int i=0;
		while(i<=30){
			sum_func(a,n,b);
			i++;
			if(check_func(b)) break;
			strcpy(a, b);
            memset(b, 0, sizeof(b));
		}
		if(i>30) cout<<"Impossible!"<<endl;
		else cout<<"STEP="<<i<<endl;
	}
	return 0;
	
	
}