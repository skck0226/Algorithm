#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int h,w;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int arr[51][51];
int visitedW[51][51];
int visitedB[51][51];
bool checkW(int y, int x){
	if(y<0||x<0||y>=h||x>=w) return false;
	if(visitedW[y][x]==1) return false;
	if(arr[y][x]=='.'||arr[y][x]=='S') return true;
	return false;
}
bool checkB(int y, int x){
	if(y<0||x<0||y>=h||x>=w) return false;
	if(visitedB[y][x]==1) return false;
	if(arr[y][x]=='.'||arr[y][x]=='D') return true;
	return false;
}
int main(){
	int yy,xx;
	queue<int> qy,qx,qcnt;
	queue<int> wy,wx,wcnt;
	scanf("%d %d",&h,&w);
	for(int i=0;i<h;i++){
		char c; scanf("%c",&c);
		for(int j=0;j<w;j++){
			scanf("%c",&arr[i][j]);
			if(arr[i][j]=='S'){
				qy.push(i); qx.push(j); qcnt.push(0);
			}
			if(arr[i][j]=='*'){
				wy.push(i); wx.push(j); wcnt.push(0);
			}	
			if(arr[i][j]=='D'){
				yy=i; xx=j;
			}
		}
	}
	int end=0, count;
	int bFlag=-1,wFlag=-1;
	while(1){
		
		if(qy.empty()) break;
		while(!wy.empty()){
			int ccnt = wcnt.front(); 
			if(wFlag!=ccnt){
				wFlag = ccnt;
				break;
			}
			wcnt.pop();
			int cy = wy.front(); wy.pop();
			int cx = wx.front(); wx.pop();
			
			for(int i=0;i<4;i++){
				int ny = cy + dy[i];
				int nx = cx + dx[i];
				if(checkW(ny,nx)){
					visitedW[ny][nx] = 1;
					arr[ny][nx] = '*';
					wy.push(ny); wx.push(nx); wcnt.push(ccnt+1);
					
				}
			}
		}	
		
		while(!qy.empty()){
			int ccnt = qcnt.front(); 
			if(bFlag!=ccnt){
				bFlag = ccnt;
				break;
			}
			qcnt.pop();
			int cy = qy.front(); qy.pop();
			int cx = qx.front(); qx.pop();	
			
			if(cy==yy&&cx==xx){
				count = ccnt;
				end = 1;
				break;
			}
			for(int i=0;i<4;i++){
				int ny = cy + dy[i];
				int nx = cx + dx[i];
				if(checkB(ny,nx)){
					visitedB[ny][nx] = 1;
					arr[ny][nx] = 'S';
					qy.push(ny); qx.push(nx); qcnt.push(ccnt+1);
				}
			}
			
		}
		if(end==1) break;
	}
	if(end==1) cout << count;
	else cout << "KAKTUS";
	return 0;
}