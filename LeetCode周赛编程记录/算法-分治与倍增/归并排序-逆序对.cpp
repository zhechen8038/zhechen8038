#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

const int MAX=1e6;

int n;
int a[MAX];

//归并排序并统计逆序对数
ll merge_sort(int left,int mid,int right){
	vector<int> temp(right-left+1);
	int i=left,j=mid+1;
	ll cnt=0;
	int k=0;
	while(i<=mid&&j<=right){
		if(a[i]<=a[j]){
			temp[k++]=a[i++];
		}
		else{
			temp[k++]=a[j++];
			cnt+=mid-i+1;
		}
	}
	
	while(i<=mid) temp[k++]=a[i++];
	while(j<=right) temp[k++]=a[j++];
	
	rep(i,k){
		a[left+i]=temp[i];
	}
	
	return cnt;
}

ll merge_and_cnt(int left,int right){
	if(left>=right) return 0;
	int mid=(left+right)/2;
	
	ll cnt=0;
	//分左右统计
	cnt+=merge_and_cnt(left,mid);
	cnt+=merge_and_cnt(mid+1,right);
	
	//合并统计
	cnt+=merge_sort(left,mid,right);
	
	return cnt;
}

void solve(){
	cin>>n;
	rep(i,n) cin>>a[i];
	
	ll ans=merge_and_cnt(0,n-1);
	
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
}