#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int n,m;
vector<int> v[2001];
int visited[2001];
int flag = 0;
void dfs(int node, int level){
	if(level==5){
		flag = 1;
		return ;
	}
	visited[node] = 1;
	for(int i=0;i<v[node].size();i++){
		int next = v[node][i];
		if(visited[next]==1) continue;
		dfs(next,level+1);
		if(flag==1) return ;
	}
}
int main() {
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b; scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);	
	}
	for(int i=0;i<n;i++){
		memset(visited,0,sizeof(visited));
		dfs(i,1);
		if(flag==1){
			cout<<"1";
			break;
		}
	}
	if(flag==0) cout<<"0";
	return 0;
}