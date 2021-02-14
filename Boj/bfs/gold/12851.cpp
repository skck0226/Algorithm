#include <iostream>
#include <queue>
using namespace std;
int from,to;
int visited[100001];
int jump(int n){
	return 2*n;
}
int go(int n){
	return n+1;
}
int back(int n){
	return n-1;
}
bool check(int n){
	if(n<0||n>100000) return false;
	if(visited[n]==1){
		if(n==to) return true;
		return false;
	}	
	return true;
}
int main(){
	scanf("%d %d",&from,&to);
	queue<int> q,qcnt;
	q.push(from); qcnt.push(0);
	visited[from] = 1;
	int cntFlag=-9;
	int cnt = 0;
	while(!q.empty()){
		int now = q.front(); q.pop();
		int ccnt = qcnt.front(); qcnt.pop();
		visited[now] = 1;
		if(ccnt == cntFlag+1){
			break;
		}
		if(now==to){
			cntFlag = ccnt;
			cnt++;
			continue;
		}
		int arr[3]={0,};
		arr[0] = jump(now);
		arr[1] = go(now);
		arr[2] = back(now);
		for(int i=0;i<3;i++){
			if(check(arr[i])){
				q.push(arr[i]); qcnt.push(ccnt+1);
			}
		}
	}
	cout << cntFlag << endl << cnt;
	return 0;
}