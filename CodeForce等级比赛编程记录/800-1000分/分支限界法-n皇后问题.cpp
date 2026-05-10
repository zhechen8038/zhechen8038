#include<bits/stdc++.h>
using namespace std;

struct Board{
	vector<int> queens;//每行的情况
	int row;
	
	Board(int n) : queens(n, -1), row(0) {}
};


void solve(int n){
	queue<Board> q;
	Board f(n);
	q.push(f);
	
	while(!q.empty()){
		Board current=q.front();
		q.pop();
		
		if(current.row==n){
			for(int i=0;i<n;i++){
				cout<<current.queens[i]+1<<" ";
			}
			// cout<<endl;
			// continue;
			return;
		}
		
		//尝试在当前行的每一列
		for(int i=0;i<n;i++){
			int flag=1;
			for(int j=0;j<current.row;j++){
				if(current.queens[j]==i||abs(j-current.row)==abs(current.queens[j]-i)){
					flag=0;
					break;
				}
			}
			if(flag){
				Board next=current;
				next.queens[current.row]=i;
				next.row++;
				q.push(next);
			}
		}
	}
}

int main(){
	int n;
	cin>>n;
	solve(n);
	return 0;
}