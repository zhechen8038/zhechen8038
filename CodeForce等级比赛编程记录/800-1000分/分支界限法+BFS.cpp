#include<bits/stdc++.h>
using namespace std;

int find(int n,int e,vector<vector<int>>& a,int start,int des){
	vector<vector<int>> adj(n);
	for(int i=0;i<e;i++){
		int left=a[i][0];
		int right=a[i][1];
		adj[left].push_back(right);
		adj[right].push_back(left);
	}
	
	vector<bool> visited(n,false);
	queue<int> q;
	
	q.push(start);
	visited[start]=true;
	
	while(!q.empty()){
		int current=q.front();
		q.pop();
		
		if(current==des) return true;
		
		for(int i:adj[current]){
			if(!visited[i]){
				visited[i]=true;
				q.push(i);
			}
		}
	}
	return false;
	
}
int main(){
	int n,e;
	cin>>n>>e;
	vector<vector<int>> a(n,vector<int>(2));
	
	for(int i=0;i<e;i++){
		cin>>a[i][0]>>a[i][1];
	}
	int start,des;
	cin>>start>>des;
	if(find(n,e,a,start,des)){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
	return 0;
}