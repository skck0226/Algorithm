#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
vector<vector<int>> adj;
vector<int> dist;
void dstra(int start){
	priority_queue<pair<int,int>> pq;
	pq.push({0,start});
	dist[start] = 0;	
	while(!pq.empty()){
		int now = pq.top().second;
		int now_dist = pq.top().first;
		pq.pop();
		if(now_dist>dist[now]) continue;
		for(int i:adj[now]){
			int cost = now_dist + 1;
			if(cost < dist[i]){
				dist[i] = cost;
				pq.push({cost,i});
			}
		}
	}
}
int main(){
	int a,b; scanf("%d %d",&a,&b);
	int n,m; scanf("%d %d",&n,&m);
	
	adj = vector<vector<int>>(n+1);
	dist = vector<int>(n+1,INF);
	
	for(int i=0;i<m;i++){
		int f,t; scanf("%d %d",&f,&t);
		adj[f].push_back(t);
		adj[t].push_back(f);
	}
	dstra(a);

	if(dist[b]==INF) cout <<"-1";
	else cout << dist[b];
	return 0;
}