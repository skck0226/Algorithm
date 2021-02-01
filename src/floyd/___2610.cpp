#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int n,m;
int dist[101][101];
int visited[101];
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
int mini = 987654321;
int flag;
void dfs(int node){	
	visited[node] = 1;
	int cnt = 0;
	for(int i=1;i<=n;i++){		
		if(dist[node][i]!=INF&&i!=node){
			cnt +=dist[node][i];
			if(visited[i]==0) dfs(i);
		}
	}
	if(mini>cnt){
		mini = cnt;
		flag = node;
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
		dist[b][a] = 1;
	}
	floyd();
	
	int k=0;
	vector<int> v;
	for(int i=1;i<=n;i++){
		if(visited[i]==1) continue;
		mini = 987654321;
		dfs(i);
		k++;
		v.push_back(flag);
	}
	sort(v.begin(),v.end());
	cout<<k<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
	return 0;
}