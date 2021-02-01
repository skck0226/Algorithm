#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,k;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int arr[101][101]={0,};
int visited[101][101]={0,};
bool check(int vy,int vx){
	if(vy<0||vx<0||vy>=n||vx>=m) return false;
	if(visited[vy][vx]==1) return false;
	if(arr[vy][vx]==1) return false;
	return true;
}
int bfs(int y, int x){
	queue<int> qy,qx;
	qy.push(y); qx.push(x);
	visited[y][x] = 1;
	arr[y][x] = 1;
	int cnt = 0;
	while(!qy.empty()){
		cnt++;
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		for(int i=0;i<4;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(check(ny,nx)){
				visited[ny][nx] = 1;
				arr[ny][nx] = 1;
				qy.push(ny); qx.push(nx);
			}
		}
	}
	return cnt;
}
int main() {
	vector<int> v;
	scanf("%d %d %d",&n,&m,&k);
	for(int z=0;z<k;z++){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		for(int i=y1;i<y2;i++){
			for(int j=x1;j<x2;j++){
				arr[i][j] = 1;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==1) continue;
			int res = bfs(i,j);
			v.push_back(res);
		}
	}
	sort(v.begin(),v.end());
	cout << v.size() << endl;
	for(int i=0;i<v.size();i++){
		cout << v[i] << " ";
	}
	return 0;
}