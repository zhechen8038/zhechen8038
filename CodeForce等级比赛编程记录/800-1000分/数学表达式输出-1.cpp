#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n+1;i++){
		cin>>a[i];
	}
	int flag=0;
	for(int i=0;i<n+1;i++){
		if(a[i]>0){
			if(flag==0){
				if(i==n) cout<<a[i];
				else if(i==n-1){
					if(a[i]==1) cout<<"x";
					else cout<<a[i]<<"x";
				}
				else{
					if(a[i]==1) cout<<"x^"<<n-i;
					else cout<<a[i]<<"x^"<<n-i;
				}
				flag=1;
			}
			else{
				if(i==n) cout<<"+"<<a[i];
				else if(i==n-1){
					if(a[i]==1) cout<<"+"<<"x";
					else cout<<"+"<<a[i]<<"x";
				}
				else{
					if(a[i]==1) cout<<"+"<<"x^"<<n-i;
					else cout<<"+"<<a[i]<<"x^"<<n-i;
				}
			}
		}
		else if(a[i]<0){
			flag=1;
			if(i==n){
				cout<<a[i];
			}
			else if(i==n-1){
				if(a[i]==-1) cout<<"-"<<"x";
				else cout<<a[i]<<"x";
			}
			else{
				if(a[i]==-1) cout<<"-"<<"x^"<<n-i;
				else cout<<a[i]<<"x^"<<n-i;
			}
		}
		else{
			if(i==n&&flag==0) cout<<"0";
		}
	}
	return 0;
}