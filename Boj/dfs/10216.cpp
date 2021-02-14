#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
using namespace std;
int visited[3001];
void dfs(vector<int> v[3001], int node){
	visited[node] = 1;
	for(int i=0;i<v[node].size();i++){
		int next = v[node][i];
		if(visited[next]) continue;
		dfs(v,next);		
	}
}
int main(){
	int t; scanf("%d",&t);
	for(int z=0;z<t;z++){
		memset(isCycle,0,sizeof(isCycle));
		memset(visited,0,sizeof(visited));
		int n; scanf("%d",&n);
		int y[3001],x[3001],r[3001]; 
		vector<int> v[3001];
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&y[i],&x[i],&r[i]);			
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j) continue;
				if(sqrt(pow(y[i]-y[j],2)+pow(x[i]-x[j],2)) <=
				   (r[i]+r[j])){
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		int cnt = 0;
		for(int i=0;i<n;i++){
			if(visited[i]) continue;
			dfs(v,i);
			cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}