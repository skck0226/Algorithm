#include <iostream>
#include <queue>
using namespace std;
int n;
int dy[2] = {1,0};
int dx[2] = {0,1};
int arr[66][66];
queue<int> qy,qx;
int visited[66][66];
bool check(int y,int x){
	if(y<0||x<0||y>=n||x>=n) return false;
	if(visited[y][x]==1) return false;
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	qy.push(0); qx.push(0);
	visited[0][0] = 1;
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		int now = arr[cy][cx];
		if(now==-1){
			cout << "HaruHaru";
			return 0;
		}
		for(int i=0;i<2;i++){
			int ny = cy + now*dy[i];
			int nx = cx + now*dx[i];
			if(check(ny,nx)){
				visited[ny][nx] = 1;
				qy.push(ny); qx.push(nx);
			}	
		}
	}
	cout<<"Hing";
	return 0;
}