#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int dy[] = {2,2,1,-1,-2,-2,-1,1};
int dx[] = {-1,1,2,2,1,-1,-2,-2};
int visited[301][301];
bool check(int n, int vy, int vx){
	if(vy<0|| vx<0|| vy>=n|| vx>=n) return false;
	if(visited[vy][vx]==1) return false;
	return true;
}
int main() {
	int t;
	scanf("%d",&t);
	for(int z=0;z<t;z++){
		queue<int> qy, qx, qcnt;
		int n; scanf("%d",&n);
		int nowY, nowX;	scanf("%d %d",&nowY,&nowX);
		qy.push(nowY); qx.push(nowX); qcnt.push(0); visited[nowY][nowX]=1;
		int destY, destX; scanf("%d %d",&destY,&destX);
		if(nowY==destY && nowX==destX){
			printf("0\n"); continue;
		}
		while(!qy.empty()){
			int cy = qy.front(); qy.pop();
			int cx = qx.front(); qx.pop();
			int ccnt = qcnt.front(); qcnt.pop();
			if(cy==destY && cx==destX){
				cout << ccnt << endl;
				break;
			}
			
			for(int i=0;i<8;i++){
				int ny = cy + dy[i];
				int nx = cx + dx[i];
				if(check(n,ny,nx)){
					visited[ny][nx]=1;
					qy.push(ny); qx.push(nx);qcnt.push(ccnt+1);
				}
			}
		}
		//visited 초기화
		for(int i=0;i<n;i++){
			memset(visited[i],0,sizeof(int)*n);
		}
	}
	return 0;
}