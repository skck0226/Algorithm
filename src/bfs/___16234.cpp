#include <iostream>
#include <queue>
#include <cstdlib>
#include <string.h>
using namespace std;
int n,l,r;
int arr[51][51];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int visited[51][51];
bool check(int x, int y, int vy, int vx){
	if(vy<0||vx<0||vy>=n||vx>=n) return false;
	if(visited[vy][vx]==1) return false;
	if(abs(arr[y][x]-arr[vy][vx])>=l&&abs(arr[y][x]-arr[vy][vx])<=r) return true;
	return false;
}
int bfs(int y, int x){
	int sum =0;
	int cnt=0;
	queue<int> qy,qx,qcnt;
	queue<int> qqy,qqx;
	qy.push(y); qx.push(x); qcnt.push(0); visited[y][x] = 1;
	int cFlag;
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		int ccnt = qcnt.front(); qcnt.pop();
		
		sum += arr[cy][cx]; cnt++;
		qqy.push(cy); qqx.push(cx);
		
		cFlag = ccnt;
		for(int i=0;i<4;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];	
			if(check(cy,cx,ny,nx)){
				visited[ny][nx] = 1;
				qy.push(ny); qx.push(nx); qcnt.push(ccnt+1);
			}
		}
	}
	int avg = sum/cnt;
	while(!qqy.empty()){
		int cy = qqy.front(); qqy.pop();
		int cx = qqx.front(); qqx.pop();
		arr[cy][cx] = avg;
	}
	return cFlag;
}
int main() {
	scanf("%d %d %d",&n,&l,&r);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int count = 0;
	while(1){
		int cnt = 0;
		for(int i=0;i<51;i++){
			memset(visited[i],0,sizeof(int)*51);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(visited[i][j]==1) continue;
				if(bfs(i,j)!=0) cnt++;
				visited[i][j]=1;
				// for(int z=0;z<n;z++){
				// 	for(int x=0;x<n;x++){
				// 		cout<<arr[z][x];
				// 	}
				// 	cout << endl;
				// }
				// cout << endl;
			}
		}
		count += cnt;
		if(cnt==0) break;
	}
	cout << count ;
	return 0;
}