#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int n,m;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
char arr[101][101];
int visited[101][101];
bool check(int y, int x, int ccnt){
	if(y<0||x<0||y>=n||x>=m) return false;
	if(arr[y][x]=='*') return false;
	if(visited[y][x]>=ccnt||visited[y][x]==-1){
		return true;
	}
	else return false;
	return true;
}
int main(){
	queue<int> qy,qx,qcnt;
	memset(visited,-1,sizeof(visited));
	scanf("%d %d",&m,&n);
	int x,y;
	for(int i=0;i<n;i++){
		char c; scanf("%c",&c);
		for(int j=0;j<m;j++){
			scanf("%c",&arr[i][j]);
			if(arr[i][j]=='C'){
				x=j; y=i;
			}
		}
	}
	qy.push(y); qx.push(x); qcnt.push(0);
	arr[y][x] = '-';
	visited[y][x] = -1;
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();	
		int ccnt = qcnt.front(); qcnt.pop();
		if(arr[cy][cx]=='C'){
			cout << ccnt-1;
			return 0;
		}
		for(int i=0;i<4;i++){
			for(int j=1;;j++){
				int ny = cy + j*dy[i];
				int nx = cx + j*dx[i];
				if(check(ny,nx,ccnt)){	
					visited[ny][nx] = ccnt;
					qy.push(ny); qx.push(nx); qcnt.push(ccnt+1);
				}
				else{
					break;
				}
			}
		}
	}
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		printf("%4d ",visited[i][j]);
	// 	}
	// 	cout << endl;
	// }
	return 0;
}