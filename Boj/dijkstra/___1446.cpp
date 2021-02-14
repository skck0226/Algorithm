#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define INF 987654321
using namespace std;
int n,len;
vector<vector<pair<int,int>>> adj;
vector<int> dist;
set<int> list;
void dstra(int start){
	priority_queue<pair<int,int>> pq;
	pq.push({0,start});
	dist[start] = 0;
	while(!pq.empty()){
		int here = pq.top().second;
		int cost_sum = -pq.top().first;
		pq.pop();
		cout<<here<<" "<<cost_sum<<endl;
		if(cost_sum > dist[here]) continue;
		if(here==len){
			cout << cost_sum;
			return;
		}
		for(pair<int,int> i:adj[here]){
			int there = i.first;
			int cost_next = cost_sum + i.second;
			if(there>len) continue;
			if(dist[there] > cost_next){
				dist[there] = cost_next;
				pq.push({-dist[there],there});
			}
		}
	}
}
int main(){
	scanf("%d %d",&n,&len);
	dist = vector<int>(10002,INF);
	adj = vector<vector<pair<int,int>>>(len);
	for(int i=0;i<n;i++){
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		list.insert(a); list.insert(b);
		adj[a].push_back({b,c});
	}
	list.insert(len);
	set<int>::iterator iter;
	for(int i=0;i<=10000;i++){
		iter = list.find(i);
		int now = *iter;
		if(iter!=list.end()){
			int next = *(++iter);
			int x = next - now;
			adj[now].push_back({next,x});
		}	
	}
	// for(int i=0;i<=10000;i++){
	// 	if(adj[i].size()==0) continue;
	// 	for(pair<int,int> j:adj[i]){
	// 		cout<<i<<" "<<j.first<<","<<j.second<<" ";
	// 	}
	// 	cout<<endl;	
	// }
	dstra(0);
	return 0;
}