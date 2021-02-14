#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int arr[101][101];
queue<int> qy,qx,qcnt;
queue<int> qqy,qqx;
vector<int> v;
bool checkGraph(int vy, int vx, int visited[][101]){
	if(vy<0||vx<0||vy>=n||vx>=n) return false;
	if(visited[vy][vx]==1) return false;
	if(arr[vy][vx]==1) return true;
	return false;
}
bool checkBfs(int vy, int vx, int visited[][101]){
	if(vy<0||vx<0||vy>=n||vx>=n) return false;
	if(visited[vy][vx]==1) return false;
	return true;
}
void graph(){
	int visited[101][101];
	for(int i=0;i<n;i++){
		memset(visited[i],0,sizeof(int)*n);
	}
	// cout << qqy.front() << qqx.front() << endl;
	visited[qqy.front()][qqx.front()] = 1;
	while(!qqy.empty()){
		int cy = qqy.front(); qqy.pop();
		int cx = qqx.front(); qqx.pop();
		qy.push(cy); qx.push(cx); qcnt.push(0);
		arr[cy][cx] = 0;
		for(int i=0;i<4;i++){
			int ny = cy + dy[i];	
			int nx = cx + dx[i];
			if(checkGraph(ny,nx,visited)){
				visited[ny][nx] = 1;
				qqy.push(ny); qqx.push(nx);
			}
		}
	}
}
void bfs(){
	int visited[101][101];
	for(int i=0;i<n;i++){
		memset(visited[i],0,sizeof(int)*n);
	}
	visited[qy.front()][qx.front()] = 1;
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		int ccnt = qcnt.front(); qcnt.pop();
		
		if(arr[cy][cx] == 1){
			v.push_back(ccnt-1);
			while(!qy.empty()){
				qy.pop(); qx.pop(); qcnt.pop();
			}
			return;
		}
		
		for(int i=0;i<4;i++){
			int ny = cy + dy[i];	
			int nx = cx + dx[i];
			if(checkBfs(ny,nx,visited)){
				visited[ny][nx] = 1;
				qy.push(ny); qx.push(nx); qcnt.push(ccnt+1);
			}
		}	
	}
	
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j] == 1){
				qqy.push(i); qqx.push(j);
				// cout << qqy.front() << qqx.front()<<endl;
				graph();
				bfs();
				// for(int k=0;k<n;k++){
				// 	for(int l=0;l<n;l++){
				// 		cout << arr[k][l];
				// 	}
				// 	cout << endl;
				// }
				// cout << "---------" << i << j << endl;
			}
		}
	}
	sort(v.begin(),v.end());
	cout << v[0];
	return 0;
}