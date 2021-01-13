#include <iostream>
#include <queue>
using namespace std;
int n,m;
int arr[301][301];
int zero[301][301];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
bool check(int vy, int vx){
	if(vy<0||vx<0||vy>=n||vx>=m) return false;
	if(zero[vy][vx]==0) return true;
	return false;
}
int bfs(int vy, int vx){
	int visited[301][301]={0,};
	queue<int> qy, qx;
	qy.push(vy); qx.push(vx);
	int cnt=0;
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		
		for(int i=0;i<4;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(arr[ny][nx]!=0&&visited[ny][nx]!=1){
				cnt++;
				visited[ny][nx]=1;
				qy.push(ny); qx.push(nx);
			}
		}
	}
	return cnt;
}
int main() {
	queue<int> qy,qx,qcnt;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
			zero[i][j]=arr[i][j];
			if(arr[i][j]!=0){
				qy.push(i); qx.push(j); qcnt.push(0);
			}
		}
	}
	int cntFlag=0;
	int flag = 0;
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		int ccnt = qcnt.front(); qcnt.pop();
		
		if(cntFlag != ccnt){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					zero[i][j]=arr[i][j];
				}
			}
			cntFlag = ccnt;
			int result = bfs(cy,cx);
			// cout << cntFlag << " " << qy.size()+1 << " " << result << endl; 
			if(result!=qy.size()+1){
				flag = 1;
				cout << ccnt;
				break;
			}
		}
		
		for(int i=0;i<4;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			
			if(check(ny,nx)){
				if(arr[cy][cx]!=0) arr[cy][cx] -= 1;
				
			}
		}
		if(arr[cy][cx]!=0){
			// cout << cy << cx << endl;
			cntFlag = ccnt;
			qy.push(cy); qx.push(cx); qcnt.push(ccnt+1);
		}
	}
	if(flag == 0) cout << "0";
	return 0;
}