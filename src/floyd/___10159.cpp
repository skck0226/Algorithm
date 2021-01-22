#include <iostream>
#define INF 987654321
using namespace std;
int n,m;
int dist[101][101];
void floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dist[i][j]==1){
				for(int k=1;k<=n;k++){
					if(dist[j][k]==1) dist[i][k] = 1;
				}
			}
			if(dist[i][j]==-1){
				for(int k=1;k<=n;k++){
					if(dist[j][k]==-1) dist[i][k] = -1;
				}	
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
		dist[b][a] = -1;
	}	
	floyd();
	for(int i=1;i<=n;i++){
		int cnt = 0;
		for(int j=1;j<=n;j++){
			if(dist[i][j]==INF) cnt++;
			// printf("%10d ",dist[i][j]);
		}
		cout <<cnt << endl;
	}	
	return 0;
}