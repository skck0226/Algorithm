#include <iostream>
#include <queue>
using namespace std;
int n,m;
int a,b;
int arr[101][101];
int visited[101];
int min2=987654321;

int main() {
	scanf("%d",&n);
	scanf("%d %d",&a,&b);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int c,d;
		scanf("%d %d",&c,&d);
		arr[c][d]=1; arr[d][c]=1;
	}
	queue<int> q,qcnt;
	q.push(a);qcnt.push(0); visited[a]=1;
	while(!q.empty()){
		int next = q.front(); q.pop();
		int ccnt = qcnt.front(); qcnt.pop();
		if(next==b){
			min2 = ccnt;
		}
		for(int i=1;i<=n;i++){
			if(arr[next][i]==1&&visited[i]!=1){
				visited[i]=1; q.push(i); qcnt.push(ccnt+1);
			}
		}
	}
	
	if(min2==987654321) cout<<"-1";
	else cout<<min2;
	
	return 0;
}