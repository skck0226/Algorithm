#include <iostream>
#define INF 987654321
using namespace std;
int n,m;
int dist[404][404];
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
			if(i==j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	for(int i=0;i<m;i++){
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		dist[a][b] = c;
	}
	floyd();
	int min = 987654321;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(min>dist[i][j]+dist[j][i]) 
				min = dist[i][j]+dist[j][i];
		}
	}
	if(min==987654321) cout << "-1";
	else cout << min;
	return 0;
}