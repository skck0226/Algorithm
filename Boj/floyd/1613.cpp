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
					dist[i][j] = dist[i][k]+dist[k][j];
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
	
	int q; scanf("%d",&q);
	for(int i=0;i<q;i++){
		int a,b; scanf("%d %d",&a,&b);
		if(dist[a][b]!=INF) cout << "-1\n";		
		else if(dist[b][a]!=INF) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}