#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
char map[1001][1001];
int fire[1001][1001];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
bool checkFire(int vy, int vx, int w, int h){
	if(vy<0||vx<0||vy>=h||vx>=w) return false;
	if(fire[vy][vx]==1) return false;
	if(map[vy][vx]=='.') return true;
	return false;
}
bool checkMan(int vy, int vx, int w, int h){
	if(vy<0||vx<0||vy>=h||vx>=w) return true;
	if(fire[vy][vx]==1) return false;
	if(map[vy][vx]!='.') return false;
	return true;
}
int main() {
	int t; scanf("%d",&t);
	for(int k=0;k<t;k++){
		int end=0;
		queue<int> qy,qx,qcnt;
		queue<int> fy,fx,fcnt;
		int w,h; scanf("%d %d",&w,&h);
		for(int i=0;i<h;i++){
			char enter; scanf("%c",&enter);
			for(int j=0;j<w;j++){
				scanf("%c",&map[i][j]);
				if(map[i][j]=='@'){
					qy.push(i); qx.push(j); qcnt.push(0);
				}
				if(map[i][j]=='*'){
					fy.push(i); fx.push(j); fcnt.push(0);
					fire[i][j] = 1;
				}
			}
		}
		int cntFlag=0;
		int cntFlag2=0;
		while(1){
			while(!fy.empty()){
				int ccnt = fcnt.front();
				if(cntFlag!=ccnt){
					// for(int i=0;i<h;i++){
					// 	for(int j=0;j<w;j++){
					// 		cout << fire[i][j];
					// 	}
					// 	cout << endl;
					// }
					cntFlag = ccnt;
					break;
				}
				fcnt.pop();
				int cy = fy.front(); fy.pop();
				int cx = fx.front(); fx.pop();
				for(int i=0;i<4;i++){
					int ny = cy + dy[i];
					int nx = cx + dx[i];
					if(checkFire(ny,nx,w,h)){
						map[ny][nx] = '*';
						fire[ny][nx] = 1;
						fy.push(ny); fx.push(nx); fcnt.push(ccnt+1);
					}
				}
			}
			
			while(!qy.empty()){
				int ccnt = qcnt.front();
				if(ccnt != cntFlag2){
					cntFlag2 = ccnt;
					break;
				}
				qcnt.pop();
				int cy = qy.front(); qy.pop();
				int cx = qx.front(); qx.pop();
				if(fire[cy][cx]==1) continue;
				cntFlag2 = ccnt;
				// cout << cy << cx << endl;
				if(cy<0||cx<0||cy>=h||cx>=w){
					cout << ccnt <<endl;
					end = 1;
					break;
				}
				for(int i=0;i<4;i++){
					int ny = cy + dy[i];
					int nx = cx + dx[i];
					if(checkMan(ny,nx,w,h)){
						map[ny][nx] = '@';
						qy.push(ny); qx.push(nx); qcnt.push(ccnt+1);
					}
				}
			}
			if(end == 1) break;
			
			if(qy.empty()){
				// cout << end ;
				cout << "IMPOSSIBLE" << endl;	
				break;
			}
		}
		for(int i=0;i<h;i++){
			memset(map[i],0,sizeof(char)*w);
			memset(fire[i],0,sizeof(int)*w);
		}
	}
	return 0;
}