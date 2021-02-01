#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int n,m;
char arr[1004][31];
int visited[1004];
vector<int> adj[1004];
queue<int> q,qcnt;
queue<string> qroute;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		char c; scanf("%c",&c);
		for(int j=0;j<m;j++){
			scanf("%c",&arr[i][j]);
		}
	}
	int from,to; scanf("%d %d",&from,&to);
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int cnt = 0;
			for(int k=0;k<m;k++){
				if(arr[i][k]!=arr[j][k]) cnt++;
				if(cnt==2) break;
			}
			if(cnt==1){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	q.push(from); qcnt.push(0); qroute.push(to_string(from));
	visited[from] = 1;
	while(!q.empty()){
		int now = q.front(); q.pop();
		int cnt = qcnt.front(); qcnt.pop();
		string route = qroute.front(); qroute.pop();
		for(int i:adj[now]){
			int next = i;	
			if(next==to){
				cout << route+" "+to_string(next);
				return 0;
			}
			if(visited[next]==1) continue;
			visited[next] = 1;
			q.push(next); qcnt.push(cnt+1); 
			qroute.push(route+" "+to_string(next));
		}
	}
	cout << "-1";
	return 0;
}