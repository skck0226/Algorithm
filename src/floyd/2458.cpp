#include <iostream>
#include <string.h>
#define INF 987654321
using namespace std;
int n,m;
int dist[505][505];
int can[505];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||k==j||i==k) continue;
				if(dist[i][j]>dist[i][k]+dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}
int main() {
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j] = INF;
			if(i==j) dist[i][j] = 0;
		}
	}
	for(int i=0;i<m;i++){
		int a,b; scanf("%d %d",&a,&b);
		dist[a][b] = 1;
	}
	
	floyd();
	
	int know = 0;
	for(int i=1;i<=n;i++){
		memset(can,0,sizeof(can));
		for(int j=1;j<=n;j++){
			if(dist[i][j]!=INF) can[j] = 1;
			if(dist[j][i]!=INF) can[j] = 1;
		}
		int cnt = 0;
		for(int j=1;j<=n;j++){
			if(can[j]==1) cnt++;
		}
		if(cnt==n){
			know++; 
		}
	}
	cout << know;
	return 0;
}