#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int h,w;
char arr[51][51];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
bool check(int vy, int vx, int visited[][51]){
	if(vy<0||vx<0||vy>=h||vx>=w) return false;
	if(visited[vy][vx]==1) return false;
	if(arr[vy][vx]=='L') return true;
	return false;
}
int bfs(int y, int x){
	int visited[51][51];
	for(int i=0;i<51;i++){
		memset(visited[i],0,sizeof(int)*51);
	}
	queue<int> qqy,qqx,qqcnt;
	qqy.push(y); qqx.push(x); qqcnt.push(0);
	visited[y][x] = 1;
	// 첫번째 방문 노드 visited 배열 저장할 것!!!!!!!!
	int cnt;
	while(!qqy.empty()){
		int cy = qqy.front(); qqy.pop();
		int cx = qqx.front(); qqx.pop();
		int ccnt = qqcnt.front(); qqcnt.pop();
		cnt = ccnt;
		for(int i=0;i<4;i++){
			int  ny = cy + dy[i];
			int  nx = cx + dx[i];
			if(check(ny,nx,visited)){
				visited[ny][nx] = 1;
				qqy.push(ny); qqx.push(nx); qqcnt.push(ccnt+1);
			}
		}
	}
	return cnt;
}
int main(){
	queue<int> qy,qx;
	scanf("%d %d",&h,&w);
	for(int i=0;i<h;i++){
		char c; scanf("%c",&c);
		for(int j=0;j<w;j++){
			scanf("%c",&arr[i][j]);
			if(arr[i][j]=='L'){
				qy.push(i); qx.push(j);
			}
		}
	}
	int max = -1;
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		int res = bfs(cy,cx);
		if(res > max) max = res;
	}
	cout << max;
	return 0;
}