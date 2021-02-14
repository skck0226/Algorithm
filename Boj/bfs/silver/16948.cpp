#include <iostream>
#include <queue>
using namespace std;
int n;
int dy[6] = {-2,-2,0,0,2,2};
int dx[6] = {-1,1,-2,2,-1,1};
int visited[201][201];
bool check(int y,int x){
	if(y<0||x<0||y>=n||x>=n) return false;
	if(visited[y][x]==1) return false;
	
	return true;
}
int main(){
	scanf("%d",&n);
	int r1,c1,r2,c2; scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
	queue<int> qy,qx,qcnt;
	qy.push(r1); qx.push(c1); qcnt.push(0);
	visited[r1][c1] = 1;
	int flag = -1;
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		int ccnt = qcnt.front(); qcnt.pop();
		if(cy==r2&&cx==c2){
			flag = ccnt;
			break;
		}
		for(int i=0;i<6;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(check(ny,nx)){
				visited[ny][nx] = 1;
				qy.push(ny); qx.push(nx); qcnt.push(ccnt+1);
			}
		}
	}
	cout << flag;
	return 0;
}