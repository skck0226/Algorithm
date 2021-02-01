#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,m;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
char arr[21][21];
queue<int> qy,qx,wy,wx,qcnt;
vector<pair<int,int>> o;
bool check(int y, int x){
	if(arr[y][x]=='#') return false;
	return true;
}
bool isOut(int y,int x){
	if(y<0||x<0||y>=n||x>=m) return true;
	return false;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		char c; scanf("%c",&c);
		for(int j=0;j<m;j++){
			scanf("%c",&arr[i][j]);
			if(arr[i][j]=='o'){
				o.push_back({i,j});	
			}
		}
	}
	qy.push(o[0].first); qx.push(o[0].second); qcnt.push(0);
	wy.push(o[1].first); wx.push(o[1].second);
	while(!qy.empty()){
		int y1 = qy.front(); qy.pop();
		int x1 = qx.front(); qx.pop();
		int y2 = wy.front(); wy.pop();
		int x2 = wx.front(); wx.pop();
		int cnt = qcnt.front(); qcnt.pop();
		int out = 0;
		if(isOut(y1,x1)) out++;
		if(isOut(y2,x2)) out++;
		if(out==1){
			cout << cnt;
			return 0;
		}
		if(cnt==10) continue;
		for(int i=0;i<4;i++){
			int ny1 = y1 + dy[i];
			int ny2 = y2 + dy[i];
			int nx1 = x1 + dx[i];
			int nx2 = x2 + dx[i];
			if(isOut(ny1,nx1)&&isOut(ny2,nx2)){
				continue;	
			}
			if(!check(ny1,nx1)&&!check(ny2,nx2)){
				continue;	
			}	
			if(!check(ny1,nx1)){
				ny1 -= dy[i]; nx1 -= dx[i];
			}
			if(!check(ny2,nx2)){
				ny2 -= dy[i]; nx2 -= dx[i];
			}
			qy.push(ny1); qx.push(nx1); qcnt.push(cnt+1);
			wy.push(ny2); wx.push(nx2);
		}
	}
	cout << "-1";
	return 0;
}