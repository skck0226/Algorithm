#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,m;
vector<pair<int,int>> adj[100001];
int visited[100001];
int lift[100001]={0,};
int record[2][100001];
void recur(int n){
	if(n==-1) return;
	recur(record[0][n]);	
	if(record[0][n]==-1) return;
	printf("%d\n",record[1][n]);
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int start,interval; scanf("%d %d",&start,&interval);
		vector<int> in;
		in.push_back(start);
		for(int j=1;;j++){
			int x = interval*j;
			if((start+x)>n) break;
			for(int k:in){
				adj[k].push_back({start+x,i});
				adj[start+x].push_back({k,i});
			}
			in.push_back(start+x);
		}
	}
	int from,to; scanf("%d %d",&from,&to);
	queue<int> q,qcnt;
	q.push(from); qcnt.push(0);
	visited[from] = 1;
	record[0][from] = -1;
	while(!q.empty()){
		int now = q.front(); q.pop();
		int cnt = qcnt.front(); qcnt.pop();
		
		for(pair<int,int> i:adj[now]){
			int next = i.first;
			int way = i.second;
			if(next==to){
				cout << cnt+1 << endl;
				recur(now);
				printf("%d",way);
				return 0;
			}
			if(lift[way]!=cnt&&lift[way]>0) continue;
			if(visited[next]==1) continue;	
			visited[next] = 1;
			lift[way] = cnt;
			q.push(next); qcnt.push(cnt+1);
			record[0][next] = now;
			record[1][next] = way;
		
		}
	}
	cout << "-1";
	return 0;
}