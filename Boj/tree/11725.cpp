#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int main() {
	queue<int> q,qcnt, qbefore;
	int arr[100001]={0,};
	int visited[100001]={0,};
	int parent[100001];
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			arr[i][j] = 0;
		}
	}
	int a,b;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		arr[a][b] = 1; arr[b][a] = 1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << arr[i][j];
		}
		cout << endl;
	}
	// q.push(1); qcnt.push(0); qbefore.push(0);
	// visited[1] = 1;
	// while(!q.empty()){
	// 	int now = q.front(); q.pop();
	// 	int ccnt = qcnt.front(); qcnt.pop();
	// 	int cbefore = qbefore.front(); qbefore.pop();
	// 	cout << now << endl;
	// 	parent[now] = cbefore;
	// 	for(int i=1;i<=n;i++){
	// 		if(arr[now][i]==1){
	// 			if(visited[i]==0){
	// 				visited[i] = 1;
	// 				q.push(i); 
	// 				qcnt.push(ccnt+1);
	// 				qbefore.push(now);
	// 			}
	// 		}
	// 	}
	// }
	// for(int i=2;i<=n;i++){
	// 	cout << parent[i] << endl;
	// }
	return 0;
}