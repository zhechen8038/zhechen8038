#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=1;i<=n;i++)

const int MOD=1e8-3;
const int MAX=1e5+5;

int n;
int a[MAX],b[MAX];
int A[MAX],B[MAX];
int l[MAX];

bool cmp1(int i,int j){
	return A[i]<A[j];
}

bool cmp2(int i,int j){
	return B[i]<B[j];
}

ll merge_sort(int left,int mid,int right){
	vector<int> temp(right-left+1);
	int i=left,j=mid+1;
	int k=0;
	ll cnt=0;
	while(i<=mid&&j<=right){
		if(l[i]<=l[j]){
			temp[k++]=l[i++];
		}
		else{
			temp[k++]=l[j++];
			cnt+=mid-i+1;
		}
	}
	
	while(i<=mid) temp[k++]=l[i++];
	while(j<=right) temp[k++]=l[j++];
	
	for(int i=0;i<k;i++){
		l[left+i]=temp[i];
	}
	
	return cnt;
}

ll merge_and_cnt(int left,int right){
	if(left>=right) return 0;
	int mid=(left+right)/2;
	ll cnt=0;
	
	cnt+=merge_and_cnt(left,mid);
	cnt+=merge_and_cnt(mid+1,right);
	
	cnt+=merge_sort(left,mid,right);
	
	return cnt;
}
void solve(){
	cin>>n;
	rep(i,n){
		cin>>A[i];
		a[i]=i;
	}
	rep(i,n){
		cin>>B[i];
		b[i]=i;
	}
	
	//离散化，使下标按照大小排序
	sort(a+1,a+1+n,cmp1);
	sort(b+1,b+1+n,cmp2);
	
	//映射关系
	rep(i,n){
		l[a[i]]=b[i];
	}
	
	//归并排序，求l数组的逆序对
	ll ans=merge_and_cnt(1,n)%MOD;
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
}