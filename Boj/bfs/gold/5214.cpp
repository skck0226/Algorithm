#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int n,m,k;
int visited[101111];
vector<int> adj[101111];
vector<int> start;
vector<int> end1;
set<int> dist[100001];
int in[1000];
int main(){
	scanf("%d %d %d",&n,&k,&m);
	for(int i=1;i<=m;i++){
		for(int j=0;j<k;j++){
			scanf("%d",&in[j]);
			adj[n+i].push_back(in[j]);
			adj[in[j]].push_back(n+i);
		}
	}
	if(n==1){
		cout << 1;
		return 0;
	}
	queue<int> q,qcnt;
	q.push(1); qcnt.push(1);
	visited[1] = 1;
	while(!q.empty()){
		int now = q.front(); q.pop();
		int cnt = qcnt.front(); qcnt.pop();
		for(int i:adj[now]){
			if(visited[i]==1) continue;
			if(i==n){
				cout<<cnt/2+1;
				return 0;
			}
			visited[i] = 1;
			q.push(i); qcnt.push(cnt+1);
		}
	}
	cout << "-1";
	
	
	
	return 0;
}