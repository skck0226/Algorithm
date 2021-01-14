#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v[100001];
int visited[100001];
int parent[100001];
void dfs(int node){
	for(int i=0;i<v[node].size();i++){
		int next = v[node][i];
		if(visited[next]!=1){
			parent[next] = node;
			visited[next] = 1;
			dfs(next);
		}
	}
}
int main() {
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		int a,b; scanf("%d %d",&a,&b);
		v[a].push_back(b); v[b].push_back(a);
	}
	visited[1] = 1;
	dfs(1);
	for(int i=2;i<=n;i++){
		cout<<parent[i] << '\n';
	}
	return 0;
}