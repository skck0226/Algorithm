#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int n,m;
int arr[101][101];
queue<int> q,qcnt;
int main() {
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b; scanf("%d %d",&a,&b);
		arr[a][b] = 1; arr[b][a] = 1;
	}
	int min = 987654321;
	int flag;
	for(int i=1;i<=n;i++){
		int visited[101];
		memset(visited,0,sizeof(int)*101);
		int cnt = 0;
		q.push(i); qcnt.push(0);
		visited[i] = 1;
		while(!q.empty()){
			int now = q.front(); q.pop();
			int ccnt = qcnt.front(); qcnt.pop();
			cnt += ccnt;
			for(int j=1;j<=n;j++){
				if(arr[now][j]==1&&visited[j]!=1){
					visited[j] = 1;
					q.push(j); qcnt.push(ccnt+1);
				}
			}
		}
		if(min>cnt){
			min = cnt;
			flag = i;
		}
	}
	cout << flag;
	return 0;
}