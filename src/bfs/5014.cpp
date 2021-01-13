#include <iostream>
#include <queue>
using namespace std;
int f, s, g, u, d;
int visited[1000001];
bool check(int vpos){
	if(vpos<=0 || vpos >f) return false;
	if(visited[vpos]==1) return false;
	return true;
}
int min2 = 987654321;
int main() {
	scanf("%d %d %d %d %d",&f,&s,&g,&u,&d);
	queue<int> q,qcnt;
	q.push(s); qcnt.push(0);
	while(!q.empty()){
		int cpos = q.front(); q.pop();
		int ccnt = qcnt.front(); qcnt.pop();
		
		if(cpos == g){
			min2 = ccnt;
			break;
		}
		
		if(check(cpos-d)){
			visited[cpos-d] = 1;
			q.push(cpos-d); qcnt.push(ccnt+1);	
		}
		if(check(cpos+u)){
			visited[cpos+u] = 1;
			q.push(cpos+u); qcnt.push(ccnt+1);	
		}
	}
	if(min2==987654321) cout << "use the stairs";
	else cout << min2;
	return 0;
}