#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int arr[21][21];
int n;
int dy[] = {-1,0,0,1};
int dx[] = {0,-1,1,0};
int visited[21][21];
bool check(int vy, int vx, int level){
	if(vy<0||vx<0||vy>=n||vx>=n) return false;
	if(visited[vy][vx]==1) return false;
	if(arr[vy][vx]>level) return false;
	return true;
}
int bfs(int& vy, int& vx, int level, int& flag, int feed[][21]){
	queue<int> qy,qx,qcnt;
	qy.push(vy); qx.push(vx); qcnt.push(0);
	int cntFlag=0;
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		int ccnt = qcnt.front(); qcnt.pop();
		if(flag==1&&ccnt!=cntFlag){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					// cout << feed[i][j];
					if(feed[i][j]!=0){
						vy=i; vx=j;
						arr[i][j]=0;
					//	cout << ccnt-1 <<"::: " << vy <<" " << vx   <<" :::" << level<<  endl;
						return cntFlag;
					}
				}
				// cout << "\n";
			}
		}
		if(arr[cy][cx]!=0&&arr[cy][cx]<level){
			feed[cy][cx]=arr[cy][cx];
			// arr[cy][cx]=0;
			// vy=cy; vx=cx;
			flag = 1;
			cntFlag = ccnt;
			//cout << ccnt <<"::: " << vy <<" " << vx   <<" :::" << level<<  endl;
			// return ccnt;
		}
		
		for(int i=0;i<4;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(check(ny,nx,level)){
				visited[ny][nx] = 1;
				qy.push(ny); qx.push(nx); qcnt.push(ccnt+1);
			}
		}
	}
	if(flag==1){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					// cout << feed[i][j];
					if(feed[i][j]!=0){
						vy=i; vx=j;
						arr[i][j]=0;
					//	cout << "::: " << vy <<" " << vx   <<" :::" << level<<  endl;
						return cntFlag;
					}
				}
				// cout << "\n";
			}
		}
	return 0;
}
int main() {
	int posy, posx;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==9){
				arr[i][j]=0;
				posy=i; posx=j;
			}
		}
	}
	int level = 2;
	int cnt = 0;
	int eat = 0;
	int l=0;
	while(1){
		int feed[21][21]={0,};
		int flag = 0;
		memset(visited,0,sizeof(visited));
		cnt += bfs(posy,posx,level,flag,feed);
		if(flag==0) break;
		l++;
		eat++;
		if(eat==level){
			eat=0;
			level = level +1;
		}
	}
	cout << cnt;
	return 0;
}