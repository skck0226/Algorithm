#include <iostream>
#include <queue>
using namespace std;
int n;
int board = 0;
int visited[1001];
void c(int n){
	board = n;
}
int main(){
	scanf("%d",&n);
	queue<int> q,qcnt,qc;
	q.push(1); qcnt.push(0); qc.push(0);
	while(!q.empty()){
		int now = q.front(); q.pop();
		int ccnt = qcnt.front(); qcnt.pop();
		int cc = qc.front(); qc.pop();
		cout << ccnt << " " << now <<endl;
		if(now==n){
			cout<<ccnt;
			return 0;
		}
		if(cc!=0){
			int x = now + cc;
			if(visited[x]==0&&x<=1000){
				visited[x] = 1;
				q.push(x);
				qcnt.push(ccnt+1);
				qc.push(cc);	
			}
		}
		if(cc!=now){
			c(now);
			q.push(now);
			qcnt.push(ccnt+1);	
			qc.push(board);
		}
		if(visited[now-1]==0&&now>2){
			visited[now-1] = 1;
			q.push(now-1);
			qcnt.push(ccnt+1);
			qc.push(cc);
		}
	}
	return 0;
}