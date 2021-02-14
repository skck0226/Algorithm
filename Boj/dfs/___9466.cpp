#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int check = 0;
int dp[100005];
// void dfsCircle(vector<int> v[100001], int node, int start){
// 	dp[node] = 1;
// 	if(node==start) return;
// 	dfsCircle(v,v[node][0],start);
// }
bool dfs(vector<int> v[100005], vector<int> picked, int visited[100005], int node, int start){
	if(dp[node]==1||dp[node]==-1){
		while(1){
			if(picked.size()==0) break;
			int x = picked[picked.size()-1];
			dp[x] = -1;
			picked.pop_back();
			return false;
		}
	}
	if(visited[node]==1){
		if(node==start) check = 1;
		while(1){
			int x = picked[picked.size()-1];
			dp[x] = 1;
			picked.pop_back();
			if(x==node) break;
		}
		while(picked.size()){
			int x = picked[picked.size()-1];
			dp[x] = -1;
			picked.pop_back();
		}
		return false;
	}
	visited[node] = 1;
	picked.push_back(node);
	int next = v[node][0];
	dfs(v,picked,visited,next,start);
	
	if(check==1) return true;
	return false;
}
int main() {
	int t; scanf("%d",&t);
	for(int z=0;z<t;z++){
		int visited[100005];
		memset(visited,0,sizeof(visited));
		memset(dp,0,sizeof(dp));
		int n; scanf("%d",&n);
		vector<int> v[100005];
		
		for(int i=1;i<=n;i++){
			int a; scanf("%d",&a);
			v[i].push_back(a);
		}
		int cnt = 0;
		for(int i=1;i<=n;i++){
			// for(int j=1;j<=n;j++){
			// 	cout << dp[j] <<" ";
			// }
			// cout << endl;
			if(dp[i]==1) continue;
			else if(dp[i]==-1){
				cnt++;
				continue;
			}
			check = 0;
			vector<int> picked;
			if(!dfs(v,picked,visited,i,i)) cnt++;
		}
		cout << cnt << endl;
		for(int i=1;i<=n;i++){
			v[i].clear();	
		}
	}
	return 0;
}