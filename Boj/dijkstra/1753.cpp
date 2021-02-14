#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;
vector<vector<pair<int,int>>> adj;
vector<int> dist;
void dstra(int start){
	priority_queue<pair<int,int>> pq;
	pq.push({0,start});
	dist[start] = 0;
	while(!pq.empty()){
		int here = pq.top().second;
		int cost_sum = -pq.top().first;
		pq.pop();
		if(cost_sum>dist[here]) continue;	
		for(int i=0;i<adj[here].size();i++){
			int there = adj[here][i].second;
			int next_dist = cost_sum + adj[here][i].first;
			if(next_dist<dist[there]){
				dist[there] = next_dist;
				pq.push({-next_dist,there});
			}
		}
	}
}
int main(){
	int n,m; scanf("%d %d",&n,&m);
	int from; scanf("%d",&from);
	adj = vector<vector<pair<int,int>>>(n+1);
	dist = vector<int>(n+1,INF);
	for(int i=0;i<m;i++){
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		adj[a].push_back({c,b});
	}
	dstra(from);
	for(int i=1;i<=n;i++){
		if(dist[i]==INF) printf("INF\n");
		else printf("%d\n",dist[i]);
	}
	return 0;
}