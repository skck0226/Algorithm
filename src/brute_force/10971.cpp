#include <iostream>

using namespace std;
int n;
int arr[11][11];
int visited[11];
int dfs(int node,int start,int level,int cost){
	int mini=987654321;
	for(int i=0;i<n;i++){		
		if(arr[node][i]==0) continue;
		if(level==n&&i==start){
			return cost+arr[node][i];
		}
		if(visited[i]==1) continue;
		visited[i] = 1;
		int ret = dfs(i,start,level+1,cost+arr[node][i]);
		if(mini>ret) mini = ret;
		visited[i] = 0;
	}
	return mini;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int mini=987654321;
	for(int i=0;i<n;i++){
		visited[i] = 1;
		int ret = dfs(i,i,1,0);
		if(mini>ret) mini = ret;
		visited[i] = 0;
	}
	cout << mini;
	return 0;
}