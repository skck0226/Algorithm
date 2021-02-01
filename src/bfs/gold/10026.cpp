#include <iostream>
#include <queue>
using namespace std;
int n;
char arr[101][101];
char arr2[101][101];
int visited[101][101];
int visited2[101][101];
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};
queue<int> qy,qx;
queue<char> qcolor;
queue<int> qqy,qqx;
queue<char> qqcolor;
bool check(int vy, int vx, char color){
	if(vy<0||vx<0||vy>=n||vx>=n) return false;
	if(arr[vy][vx]!=color) return false;
	if(visited[vy][vx]==1) return false;
	return true;
}
bool check2(int vy, int vx, char color){
	if(vy<0||vx<0||vy>=n||vx>=n) return false;
	if(arr2[vy][vx]!=color) return false;
	if(visited2[vy][vx]==1) return false;
	return true;
}
void bfs(){
	char color=qcolor.front(); qcolor.pop();
	while(!qy.empty()){
		int cy=qy.front(); qy.pop();
		int cx=qx.front(); qx.pop();
		arr[cy][cx]='N';
		for(int i=0;i<4;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			
			if(check(ny,nx,color)){
				visited[ny][nx]=1;
				qy.push(ny); qx.push(nx);
			}
		}
	}
}
void bfs2(){
	char color=qqcolor.front(); qqcolor.pop();
	while(!qqy.empty()){
		int cy=qqy.front(); qqy.pop();
		int cx=qqx.front(); qqx.pop();
		arr2[cy][cx]='N';
		for(int i=0;i<4;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			
			if(check2(ny,nx,color)){
				visited2[ny][nx]=1;
				qqy.push(ny); qqx.push(nx);
			}
		}
	}
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int c; scanf("%c",&c);
		for(int j=0;j<n;j++){
			scanf("%c",&arr[i][j]);
			arr2[i][j] = arr[i][j];
			if(arr2[i][j]=='G') arr2[i][j]='R';
		}
	}
	int cnt=0,cnt2=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]!='N'){
				visited[i][j]=1;
				qy.push(i); qx.push(j);
				qcolor.push(arr[i][j]);
				bfs();
				cnt++;
				// for(int k=0;k<n;k++){
				// 	memset(visited[k],0,sizeof(int)*n);
				// }
			}
			if(arr2[i][j]!='N'){
				visited2[i][j]=1;
				qqy.push(i); qqx.push(j);
				qqcolor.push(arr2[i][j]);
				bfs2();
				cnt2++;
			}
		}
	}
	cout << cnt <<" "<<cnt2;
	return 0;
}