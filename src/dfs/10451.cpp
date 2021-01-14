#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
bool dfs(vector<vector<int>>& v,int node, int visited[1001]){
	if(visited[node]==1) return true;
	for(int i=0;i<v[node].size();i++){
		int next = v[node][i];
		visited[next] = 1;
		dfs(v,next,visited);
	}
	v[node].pop_back();
	return false;
}
int main() {
	int t; scanf("%d",&t);
	for(int z=0;z<t;z++){
		int n; scanf("%d",&n);
		vector<vector<int>> v;
		for(int i=1;i<=n;i++){
			int a; scanf("%d",&a);
			v[i].push_back(a);
		}
		int cnt = 0;
		for(int i=1;i<=n;i++){
			if(v[i].size()==0) continue;
			int visited[1001];
			memset(visited,0,sizeof(visited));
			visited[i] = 1;
			if(dfs(v,i,visited)) cnt++;
			
		}
	}
	return 0;
}