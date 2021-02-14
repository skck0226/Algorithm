#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int n,m;
int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = {-1,0,1,-1,1,-1,0,1};
char arr[1001][1001];
int visited[1001][1001]={0,};
queue<int> qy,qx,qcnt;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		char c; scanf("%c",&c);
		for(int j=0;j<m;j++){
			scanf("%c",&arr[i][j]);
			if(arr[i][j]=='.'){
				qy.push(i); qx.push(j); qcnt.push(0);
			}
		}
	}
	int flag = 0;
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		int ccnt = qcnt.front(); qcnt.pop();
		flag = ccnt;
		for(int i=0;i<8;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(ny<0||nx<0||ny>=n||nx>=m) continue;
			if(arr[ny][nx]=='.') continue;
			if(arr[ny][nx]=='9') continue;
			visited[ny][nx]++;
			if(arr[ny][nx]-'0'==visited[ny][nx]){
				arr[ny][nx] = '.';
				qy.push(ny); qx.push(nx); qcnt.push(ccnt+1);
			}
		}
	}
	cout << flag;
	return 0;
}