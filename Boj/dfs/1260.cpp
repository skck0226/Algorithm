#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int n,m,first;
int arr[1001][1001];
int visited[1001];
void bfs(int first){
	queue<int> q;
	q.push(first);
	visited[first]=1;
	while(!q.empty()){
		int next = q.front(); q.pop(); 
		cout<<next<<" ";
		for(int i=1;i<=n;i++){
			if(arr[next][i]==1 && visited[i]!=1){
				visited[i]=1;
				q.push(i);
			}
		}
	}
}
void dfs(int first){
	visited[first]=1;
	cout<<first<<" ";
	for(int i=1;i<=n;i++){
		if(arr[first][i]==1 && visited[i]!=1){
			dfs(i);
		}
	}
}
int main() {
	scanf("%d %d %d",&n,&m,&first);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		arr[a][b]=1; arr[b][a]=1;
	}
	dfs(first);
	memset(visited,0,sizeof(visited));
	printf("\n");
	bfs(first);
	return 0;
}