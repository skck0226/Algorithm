#include <iostream>
using namespace std;
int n,k;
int dist[11][11];
void floyd(){
	for(int k=0;k<n;k++){	
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j||k==j||i==k) continue;
				if(dist[i][j]>dist[i][k]+dist[k][j])
					dist[i][j] = dist[i][k]+dist[k][j];
			}
		}
	}	
}
int mini = 987654321;
void dfs(int node, int visited[11], int sum){	
	visited[node] = 1;
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(visited[i]==1){
			cnt++;
		}
	}
	if(cnt==n){
		if(mini>sum) mini = sum;
		return;
	}
	for(int i=0;i<n;i++){
		if(visited[i]==1) continue;
		dfs(i,visited,sum+dist[node][i]);
		visited[i] = 0;
	}
}
int main() {
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&dist[i][j]);
		}
	}
	floyd();
	int visited[11]={0,};
	dfs(k,visited,0);
	cout << mini;
	return 0;
}