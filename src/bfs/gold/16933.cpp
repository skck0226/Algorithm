#include <iostream>
#include <queue>
using namespace std;
int n,m,k;
int dy[5] = {1,-1,0,0};
int dx[5] = {0,0,1,-1};
int arr[1001][1001];
int visited[11][1001][1001];
queue<int> qy,qx,qcnt,qlife;
bool check(int y, int x, int life){
	if(y<0||x<0||y>=n||x>=m) return false;
	for(int i=life;i<=k;i++){
		if(visited[i][y][x]==1) return false;
	}
	return true;
}
bool checkNight(int& life){
	if(life==0) return false;
	else life--;	
	return true;
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&arr[i][j]);
		}
	}
	int flag = 0;
	qy.push(0); qx.push(0); qcnt.push(1); qlife.push(k);
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		int ccnt = qcnt.front(); qcnt.pop();
		int clife = qlife.front(); qlife.pop();
		// cout<< cy <<" "<< cx<<endl;
		if(cy==n-1&&cx==m-1){
			flag = ccnt;
			break;
		}
		for(int i=0;i<4;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			int life = clife;
			
			if(check(ny,nx,life)){
				if(arr[ny][nx]==0){
					visited[life][ny][nx] = 1;
					qy.push(ny); qx.push(nx);
					qcnt.push(ccnt+1); qlife.push(life);
					continue;
				}
				else if(checkNight(life)){
					if(ccnt%2==0){
						qy.push(cy); qx.push(cx);
						qcnt.push(ccnt+1); qlife.push(clife);
					}
					else{
						visited[life][ny][nx] = 1;
						qy.push(ny); qx.push(nx);
						qcnt.push(ccnt+1); qlife.push(life);	
					}
				}
			}
		}
		
	}
	if(flag==0) cout<<"-1";
	else cout << flag;
	return 0;
}