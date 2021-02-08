#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int n,m;
vector<int> v[10001];
vector<int> com;
int visited[10001];
int dp[10001]={0,};
int dfs(int node){
	if(v[node].size()==0) return dp[node] = 1;
	int ret = 1;
	for(int i=0;i<v[node].size();i++){
		int next = v[node][i];
		if(dp[next]!=0) ret += dp[next];
		else ret += dfs(next);
	}
	return dp[node] = ret;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b; scanf("%d %d",&a,&b);
		v[b].push_back(a);
	}
	int max=0;
	for(int i=1;i<=n;i++){
		int res = dfs(i);
		com.push_back(res);
		if(max<res) max = res;
	}
	for(int i=0;i<com.size();i++){
		if(com[i]==max) printf("%d ",i+1);
	}
	return 0;
}