#include <iostream>
#include <queue>
using namespace std;
int n, e;
int arr[101][101];
bool check[101];
int main() {
	scanf("%d",&n);
	scanf("%d",&e);
	for(int i=0;i<e;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		arr[a][b]=1; arr[b][a]=1;
	}
	queue<int> q;
	q.push(1); check[1] = true;
	int cnt=0;
	while(!q.empty()){
		cnt++;
		int node = q.front(); q.pop();
		for(int i=1;i<=n;i++){
			if(arr[node][i]==1 && check[i]!=true){
				q.push(i);
				check[i] = true;
			}
		}
	}
	cout << cnt-1;
	return 0;
}