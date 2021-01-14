#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int n,m;
vector<int> v[10001];
vector<int> com;
int visited[10001];
int dfs(int node){
	if(v[node].size()==0) return 1;
	int ret = 1;
	for(int i=0;i<v[node].size();i++){
		int next = v[node][i];
		if(visited[next]!=1){
			ret += dfs(next);
		}
	}
	return ret;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b; scanf("%d %d",&a,&b);
		v[b].push_back(a);
	}
	int max=0;
	for(int i=1;i<=n;i++){
		memset(visited,0,sizeof(int)*10001);
		visited[i] = 1;
		int res = dfs(i);
		com.push_back(res);
		if(max<res) max = res;
	}
	for(int i=0;i<com.size();i++){
		if(com[i]==max) cout<<i+1<<" ";
	}
	return 0;
}