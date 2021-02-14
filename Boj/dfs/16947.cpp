#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int n;
vector<int> v[3001];
vector<int> cycle;
int num[3001]={0};
int isCycle[3001]={0};
int visited[3001]={0};
int flag = 0;
void searchCycle(int node, int before){
	cycle.push_back(node);
	num[node]++;
	// cout << node <<" + "<< num[node] << endl;
	if(num[node]>1){
		isCycle[cycle[cycle.size()-1]] = 1;
		cycle.pop_back();
		while(1){
			int x = cycle[cycle.size()-1];
			if(num[x]>1){ 
				flag = 1;
				return;
			}
			isCycle[x] = 1;
			cycle.pop_back();
		}
	}
	for(int i=0;i<v[node].size();i++){
		int next = v[node][i];
		if(next == before) continue;
		searchCycle(next,node);
		if(flag) return;
	}
	cycle.pop_back();
}
int dfs(int node, int cnt){
	// cout << node <<endl;
	if(visited[node]==1) return 0;
	visited[node] = 1;
	if(isCycle[node]==1) return cnt;
	int max = 0;
	for(int i=0;i<v[node].size();i++){
		int next = v[node][i];
		int res=dfs(next,cnt+1);
		if(max<res) max = res;
	}
	return max;
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b; scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	searchCycle(1,0);
	for(int i=1;i<=n;i++){
		memset(visited,0,sizeof(visited));
		if(isCycle[i]==1) cout<<"0 ";
		else{
			int res = dfs(i,0);
			cout << res <<" ";
		}
	}
	return 0;
}