#include <iostream>
#include <queue>
using namespace std;
int n,k;
int visited[100001];
bool check1(int vpos){
	if(vpos>100000) return false;
	if(visited[vpos]==1) return false;
	return true;
}
bool check2(int vpos){
	if(vpos>100000) return false;
	if(vpos<0) return false;
	if(visited[vpos]==1) return false;
	return true;
}
int main() {
	int cnt=0;
	scanf("%d %d",&n,&k);
	if(k<=n){
		cout << n-k;
	}
	else{
		queue<int> q,qcnt;
		q.push(n); qcnt.push(0); visited[n]=1;
		while(!q.empty()){
			int pos = q.front(); q.pop();
			int ccnt = qcnt.front(); qcnt.pop();
			if(pos>k){
				visited[pos-1] = 1;
				q.push(pos-1); qcnt.push(ccnt+1);
				continue;
			}
			if(pos==k){
				cout << ccnt;
				break;
			}
			//2*pos
			if(check2(2*pos)){
				visited[2*pos] = 1;
				q.push(2*pos); qcnt.push(ccnt+1);
			}
			//pos+1
			if(check2(pos+1)){
				visited[pos+1] = 1;
				q.push(pos+1); qcnt.push(ccnt+1);
			}
			//pos-1
			if(check2(pos-1)){
				visited[pos-1] = 1;
				q.push(pos-1); qcnt.push(ccnt+1);
			}
		}
	}
	return 0;
}