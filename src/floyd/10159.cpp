#include <iostream>
#define INF 987654321
using namespace std;
int n,m;
int dist[101][101];
int dist2[101][101];
int res[101];
void floyd(){
	for(int k=1;k<=n;k++){	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][j]>dist[i][k]+dist[k][j])
					dist[i][j] = dist[i][k]+dist[k][j];
				if(dist2[i][j]>dist2[i][k]+dist2[k][j])
					dist2[i][j] = dist2[i][k]+dist2[k][j];
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
			dist2[i][j] = INF;
			if(i==j) dist2[i][j] = 0;
		}
	}
	for(int i=0;i<m;i++){
		int a,b; scanf("%d %d",&a,&b);
		dist[a][b] = 1;
		dist2[b][a] = 1;
	}	
	floyd();
	for(int i=1;i<=n;i++){
		int cnt = 0;
		for(int j=1;j<=n;j++){
			if(dist[i][j]!=INF&&dist[i][j]!=0) res[i]++;
			// printf("%10d ",dist[i][j]);
		}
		// cout << endl;
	}	
	for(int i=1;i<=n;i++){
		int cnt = 0;
		for(int j=1;j<=n;j++){
			if(dist2[i][j]!=INF&&dist2[i][j]!=0) res[i]++;
			// printf("%10d ",dist2[i][j]);
		}
		// cout << endl;
	}	
	for(int i=1;i<=n;i++){
		cout << n-1-res[i] << endl;
	}
	return 0;
}