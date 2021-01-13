#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t; scanf("%d",&t);
	for(int z=0;z<t;z++){
		queue<int> q,qcnt;
		int visited[10000];
		int a,b; scanf("%d %d",&a,&b);
		int count=-1;
		q.push(a); qcnt.push(0);
		while(!q.empty()){
			int num = q.front(); q.pop();
			int ccnt = qcnt.front(); qcnt.pop();
			if(num == b){
				break;
			}
			if()
		}
	}
	return 0;
}