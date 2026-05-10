#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

struct node {
	int data;
	node* next;
	node(int val):data(val),next(nullptr){}
};

void solve(){
	int n,m;
	cin>>n>>m;
	
	//创建链表
	node* head=new node(1);
	node* prev=head;
	for(int i=2;i<=n;i++){
		prev->next=new node(i);
		prev=prev->next;
	}
	
	prev->next=head;//形成环形链表
	
	node* cur=head;
	
	while(cur->next!=cur){
		for(int i=1;i<m;i++){
			prev=cur;//记录删除节点的前一个节点
			cur=cur->next;
		}
		
		cout<<cur->data<<" ";
		//删除当前节点
		prev->next=cur->next;
		delete cur;
		cur=prev->next;
	}
	
	cout<<cur->data;
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}