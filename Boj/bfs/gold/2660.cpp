#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int arr[51][51];
int n; 
int bfs(int first, int visited[51]){
	queue<int> q,qcnt;
	q.push(first); qcnt.push(0); visited[first]=1;
	int count;
	while(!q.empty()){
		int now = q.front(); q.pop();
		int cnt = qcnt.front(); qcnt.pop();
		count = cnt;
		for(int i=1;i<=n;i++){
			if(arr[now][i]==1&&visited[i]!=1){
				visited[i] = 1;
				q.push(i); qcnt.push(cnt+1);
			}	
		}
	}
	return count;	
}
int main(){
	vector<int> v;
	scanf("%d",&n);
	while(1){
		int a,b; scanf("%d %d",&a,&b);
		if(a==-1&&b==-1) break;
		arr[a][b]=1; arr[b][a]=1;
	}
	int min;
	for(int i=1;i<=n;i++){
		int visited[51];
		memset(visited,0,sizeof(int)*51);
		int res = bfs(i,visited);
		if(min>res) min = res;
		v.push_back(res);
	}
	int count=0;
	for(int i=0;i<v.size();i++){
		if(v[i]==min) count++;
	}
	cout<<min<<" "<<count<<endl;
	for(int i=0;i<v.size();i++){
		if(v[i]!=min) continue;
		cout<< i+1 <<" ";
	}
	return 0;
}