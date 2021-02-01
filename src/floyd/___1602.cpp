#include <iostream>
#define INF 987654321
#define max(a,b) a>b?a:b
using namespace std;
int n,m,q;
int dog[505];
int dist[505][505];
int arr[505][505];
void floyd(){
	for(int k=1;k<=n;k++){	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||k==j||i==k) continue;
				if(dist[i][k]==INF||dist[k][j]==INF) continue;
				int maxi = max(arr[i][k],arr[k][j]);
				if(( dist[i][j] + arr[i][j] )>( dist[i][k]+dist[k][j]+maxi)){
					dist[i][j] = dist[i][k]+dist[k][j];
					arr[i][j] = maxi;
				}
			}
		}
	}	
}
int main() {
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j] = INF;
			arr[i][j] = INF;
			if(i==j){
				dist[i][j] = 0;
				arr[i][j] = 0;	
			}
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&dog[i]);
	}
	for(int i=1;i<=m;i++){
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		dist[a][b] = c;
		dist[b][a] = c;
		arr[a][b] = max(dog[a],dog[b]);
		arr[b][a] = arr[a][b];
	}
	floyd();
	// cout << endl;
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++){
	// 		printf("%10d ",dist[i][j]);
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++){
	// 		printf("%10d ",arr[i][j]);
	// 	}
	// 	cout << endl;
	// }
	for(int i=0;i<q;i++){
		int a,b; scanf("%d %d",&a,&b);
		if(dist[a][b]==INF) cout<<"-1\n";
		else cout << dist[a][b]+arr[a][b] << endl;
	}
	return 0;
}