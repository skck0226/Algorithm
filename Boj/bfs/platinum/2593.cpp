#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int n,m;
int visited[100111];
vector<int> adj[100111];
queue<int> q,qcnt;
queue<string> lift;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int from, term; scanf("%d %d",&from,&term);
		for(int j=0;;j++){
			int x = from+term*j;
			if(x>n) break;
			adj[n+i].push_back(x);
			adj[x].push_back(n+i);
		}
	}
	int start,end; scanf("%d %d",&start,&end);
	q.push(start); qcnt.push(0); lift.push("");
	while(!q.empty()){
		int now = q.front(); q.pop();
		int cnt = qcnt.front(); qcnt.pop();
		string route = lift.front(); lift.pop();
		if(now>n){
			cnt++;
			route += to_string(now-n) + "\n";
		}
		for(int i:adj[now]){
			if(visited[i]==1) continue;
			if(i==end){
				cout << cnt << endl;
				cout << route;
				return 0;
			}
			visited[i] = 1;
			q.push(i); qcnt.push(cnt); lift.push(route);
		}
	}
	cout << "-1";
	// for(int i=1;i<=n+m;i++){
	// 	if(adj[i].size()==0) continue;
	// 	cout << i << " : ";
	// 	for(int j:adj[i]){
	// 		cout << j << " ";
	// 	}
	// 	cout << endl;
	// }
	return 0;
}