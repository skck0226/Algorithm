#include <iostream>
#include <queue>
using namespace std;
int n,m;
int arr[100][100];
int visited[100][100];
bool check(int vy, int vx){
	if(vy < 0 || vx < 0 || vy >= n || vx >= m ) return false;
	else if(arr[vy][vx]==0) return false;
	else if(visited[vy][vx]==1) return false;
	return true;
}
int main() {
	scanf("%d %d",&n,&m);
	queue<int> qy,qx,qcnt;
	qy.push(0); qx.push(0); qcnt.push(1);
	for(int i=0;i<n;i++){
		char c; scanf("%c",&c);
		for(int j=0;j<m;j++){
			scanf("%c",&arr[i][j]);
			arr[i][j] -= '0';
		}
	}
	int cnt;
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		int ccnt = qcnt.front(); qcnt.pop();
		
		if(cy == n-1 && cx == m-1){
			cnt = ccnt;
			break;
		}
		if(check(cy-1,cx)){
			visited[cy-1][cx] = 1;
			qy.push(cy-1); qx.push(cx); qcnt.push(ccnt+1);
		}		
		if(check(cy,cx-1)){
			visited[cy][cx-1] = 1;
			qy.push(cy); qx.push(cx-1); qcnt.push(ccnt+1);
		}		
		if(check(cy,cx+1)){
			visited[cy][cx+1] = 1;
			qy.push(cy); qx.push(cx+1); qcnt.push(ccnt+1);
		}		
		if(check(cy+1,cx)){
			visited[cy+1][cx] = 1;
			qy.push(cy+1); qx.push(cx); qcnt.push(ccnt+1);
		}
	}
	cout << cnt;
	return 0;
}