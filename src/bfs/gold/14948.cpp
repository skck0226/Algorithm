#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int n,m;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int arr[101][101];
int visit[2][101][101];
struct q{
	int y;
	int x;
	int max;
	int life;
	int cnt;
	int before;
};
bool operator<(q a, q b){
	if(a.cnt==b.cnt) return a.life<b.life;
	return a.cnt>b.cnt;
}
priority_queue<q> pq;
vector<int> v;
bool check(int y, int x, int life, int max){
	if(y<0||x<0||y>=n||x>=m) return false;
	if(visit[life][y][x]!=INF&&visit[life][y][x]<=max) return false;
	return true;
}
int main(){
	for(int i=0;i<2;i++){
		for(int j=0;j<101;j++){
			for(int k=0;k<101;k++){
				visit[i][j][k] = INF;
			}
		}
	}
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	pq.push({0,0,arr[0][0],1,0,5});
	while(!pq.empty()){
		int cy = pq.top().y;
		int cx = pq.top().x;
		int cmax = pq.top().max;
		int clife = pq.top().life;
		int ccnt = pq.top().cnt;
		int cbefore = pq.top().before;
		pq.pop();	
		if(clife==0&&visit[1][cy][cx]<=cmax) continue;
		if((cy==n-1&&cx==m-1)){
			if(cbefore!=5) continue;
			v.push_back(cmax);
			continue;
		}
		for(int i=0;i<4;i++){
			if(cbefore!=5&&cbefore!=i) continue;
			int max = cmax;
			int ny = cy + dy[i]; 
			int nx = cx + dx[i];
			if(check(ny,nx,clife,cmax)){
				if(max<arr[ny][nx]) max = arr[ny][nx];
				pq.push({ny,nx,max,clife,ccnt+1,5});
				visit[clife][ny][nx] = max;
				if(clife==0) continue;
				pq.push({ny,nx,cmax,clife-1,ccnt+1,i});
				visit[clife-1][ny][nx] = cmax;	
			}
		}
	}
	sort(v.begin(),v.end());
	cout << v[0];
	return 0;
}