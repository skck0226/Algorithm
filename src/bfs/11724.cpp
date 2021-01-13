#include <iostream>
#include <queue>
using namespace std;

int main() {
	int arr[1001][1001];
	int n,m; scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		arr[a][b]=1; arr[b][a]=1;
	}
	queue<int> q;
	int visited[1001]={0,};
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(visited[i]==1) continue;
		q.push(i); visited[i]=1;
		while(!q.empty()){
			int next = q.front();
			q.pop();
			for(int j=1;j<=n;j++){
				if(arr[next][j]==1&&visited[j]!=1){
					visited[j]=1;
					q.push(j);
				}
			}
		}	
		cnt++;
	}
	cout <<cnt;
	return 0;
}
