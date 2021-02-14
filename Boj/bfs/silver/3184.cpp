#include <iostream>
#include <queue>
using namespace std;
int n,m;
int w,s;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
char arr[251][251];
int visited[251][251];
queue<int> wolf;
queue<int> qy,qx;
bool check(int vy, int vx){
	if(vy<0||vx<0||vy>=n||vx>=m) return false;
	if(visited[vy][vx]==1) return false;
	if(arr[vy][vx]=='#') return false;	
	return true;
}
int main() {
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		char c; scanf("%c",&c);
		for(int j=0;j<m;j++){
			scanf("%c",&arr[i][j]);
			if(arr[i][j]=='v'){
				w++;
			}
			else if(arr[i][j]=='o') s++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]!='v') continue;
			qy.push(i); qx.push(j);
			int wolf_num=1,sheep_num=0;
			while(!qy.empty()){
				int cy = qy.front(); qy.pop();
				int cx = qx.front(); qx.pop();
				visited[cy][cx] = 1;
				for(int i=0;i<4;i++){
					int ny = cy + dy[i];
					int nx = cx + dx[i];
					if(check(ny,nx)){
						visited[ny][nx] = 1;
						qy.push(ny); qx.push(nx);
						if(arr[ny][nx]=='v'){
							arr[ny][nx] = '.';
							wolf_num++;
						}
						else if(arr[ny][nx]=='o'){
							sheep_num++;
						}
					}
				}
			}
			if(wolf_num>=sheep_num) s -= sheep_num;
			else w -= wolf_num;
		}
	}
	cout << s << " " << w;
	return 0;
}