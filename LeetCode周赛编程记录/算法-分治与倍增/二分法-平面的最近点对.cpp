#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

const int MAX=1e4+5;

struct p{
	int x,y;
};

int n;
p abj[MAX];

double dist(const p& a,const p& b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cmp_x(const p& a,const p& b){
	return a.x<b.x;
}

bool cmp_y(const p& a,const p& b){
	return a.y<b.y;
}

double dis_min(int l,int r){
	if(r-l<=3){
		double mn=1e8;
		for(int i=l;i<r;i++){
			for(int j=i+1;j<r;j++){
				mn=min(mn,dist(abj[i],abj[j]));
			}
		}
		sort(abj+l,abj+r,cmp_y); // 按y值排列
		return mn;
	}
	
	int mid=(l+r)/2;
	int mid_x=abj[mid].x;
	
	double d1=dis_min(l,mid);
	double d2=dis_min(mid,r);
	double d=min(d1,d2);
	
	// 合并是按照y排序
	inplace_merge(abj + l, abj + mid, abj + r, cmp_y);
	
	// 处理中间带
	vector<p> strip;
	for(int i=l;i<r;i++){
		if(fabs(abj[i].x-mid_x)<d){
			strip.push_back(abj[i]);
		}
	}
	
	// 带内只需检查最多 7 个后续点
	for(int i=0;i<(int)strip.size();i++){
		for(int j=i+1;j<(int)strip.size()&&(strip[j].y-strip[i].y)<d;j++){
			d=min(d,dist(strip[i],strip[j]));
		}
	}
	
	return d;
	
}

void solve(){
	cin>>n;
	rep(i,n) cin>>abj[i].x>>abj[i].y;
	sort(abj,abj+n,cmp_x);
	double ans=dis_min(0,n);
	printf("%.4f",ans);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
}