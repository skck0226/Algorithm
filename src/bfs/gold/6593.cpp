#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
char c;
int X,Y,Z;
char tower[31][31][31];
int visited[31][31][31]={0,};
int dz[6] = {0,0,0,0,1,-1};
int dy[6] = {1,-1,0,0,0,0};
int dx[6] = {0,0,1,-1,0,0};
bool check(int vz, int vy, int vx){
	if(vz<0||vy<0||vx<0||vz>=Z||vy>=Y||vx>=X) return false;
	if(visited[vz][vy][vx]==1) return false;
	if(tower[vz][vy][vx]=='#') return false;	
	return true;
}
int main() {
	while(1){
		for(int i=0;i<31;i++){
			for(int j=0;j<31;j++){
				memset(visited[i][j],0,sizeof(visited[i][j]));
			}
		}
		queue<int> qz,qy,qx,qcnt;
		scanf("%d %d %d",&Z,&Y,&X);
		if(Z==0&&Y==0&&X==0) break;
		for(int i=0;i<Z;i++){
			for(int j=0;j<Y;j++){
				scanf("%c",&c);
				for(int k=0;k<X;k++){
					scanf("%c",&tower[i][j][k]);
					if(tower[i][j][k]=='S'){
						qz.push(i); qy.push(j); qx.push(k);
						qcnt.push(0);
						visited[i][j][k] = 1;
					}
				}
			}
			scanf("%c",&c);
		}
		int flag = 0;
		while(!qz.empty()){
			int cz = qz.front(); qz.pop();
			int cy = qy.front(); qy.pop();
			int cx = qx.front(); qx.pop();
			int ccnt = qcnt.front(); qcnt.pop();
			if(tower[cz][cy][cx]=='E'){
				flag = ccnt;
				break;
			}
			for(int i=0;i<6;i++){
				int nz = cz + dz[i];
				int ny = cy + dy[i];
				int nx = cx + dx[i];
				if(check(nz,ny,nx)){
					visited[nz][ny][nx] = 1;
					qz.push(nz); qy.push(ny); qx.push(nx);
					qcnt.push(ccnt+1);
				}
			}
		}
		if(flag!=0) cout << "Escaped in " <<flag<< " minute(s)."<<endl;
		else cout << "Trapped!"<<endl;
	}
	return 0;
}