#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int t; scanf("%d",&t);
	for(int z=0;z<t;z++){	
		vector<int> level[20001];
		vector<int> v[20001];
		int n,m; scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++){
			int a,b; scanf("%d %d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int flag = 0;
		int visited[20001];
		memset(visited,0,sizeof(visited));
		queue<int> q,qcnt,qbefore;
		for(int i=1;i<=n;i++){
			if(visited[i]==1) continue;
			q.push(i); qcnt.push(0); qbefore.push(0);
			while(!q.empty()){
				int now = q.front(); q.pop();
				int cnt = qcnt.front(); qcnt.pop();
				int before = qbefore.front(); qbefore.pop();
				
				int size = level[now].size();
				if(size!=0&&level[now][size-1]!=(cnt%2)){
					flag = 1;
					break;
				}
				level[now].push_back(cnt%2);
				
				if(visited[now]==1) continue;
				visited[now] = 1;
				
				size = v[now].size();
				for(int i=0;i<size;i++){
					if(before==v[now][i]) continue;
					q.push(v[now][i]); qcnt.push(cnt+1); qbefore.push(now);
				}
			}
		}
		if(flag==1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}