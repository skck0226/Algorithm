#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int arr[9][9];
int arr2[9][9];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
queue<int> qqy, qqx;
int virus=0;
queue<int> qy,qx,qcnt;
vector<int> v;
bool check(int vy, int vx, int visited[][9]){
	if(vy<0||vx<0||vy>=n||vx>=m){
	// cout<<"vvvvvvvvvv"<<endl;	
	return false;
	}
	if(visited[vy][vx]==1){
		
	// cout<< "visited"<<endl;	
	return false;
	}
	if(arr2[vy][vx]!=0){ 
		// cout << arr2[vy][vx]<<endl;
		return false;
	}
	return true;
}
int bfs(){
	int visited[9][9];
	for(int i=0;i<9;i++){
		memset(visited[i],0,sizeof(int)*9);
	}
	for(int i=0;i<virus;i++){
		int cy = qqy.front(); qqy.pop();
		int cx = qqx.front(); qqx.pop();	
		visited[cy][cx] = 1;
		qqy.push(cy); qqx.push(cx);
		qy.push(cy); qx.push(cx);
	}
	int cnt = 0;
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		cnt++;
		// for(int z=0;z<n;z++){
		// 	for(int x=0;x<m;x++){
		// 		cout << visited[z][x];
		// 	}
		// 	cout << endl;
		// }
		for(int i=0;i<4;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			// cout << ny << nx << endl;
			if(check(ny,nx,visited)){
				// cout<< "12 wao  j;oaij taojao;g"; 
				visited[ny][nx] = 1;
				qy.push(ny); qx.push(nx);
			}
		}
	}
	return cnt;
}
int main() {
	int one=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==1) one++;
			if(arr[i][j]==2){
				qqy.push(i); qqx.push(j);
				virus++;
			}
		}
	}
	int a[2], b[2], c[2];
	int square = n*m;
	for(int i = 0; i < square-2; i++){
		for(int j = i+1; j < square-1; j++){
			for(int k = j+1; k < square; k++){
				for(int z=0;z<n;z++){
					for(int x=0;x<m;x++){
						arr2[z][x] = arr[z][x];
					}
				}
				a[0] = i/m; a[1] = i%m;
				b[0] = j/m; b[1] = j%m;
				c[0] = k/m; c[1] = k%m;
				if(arr2[a[0]][a[1]]!=0||arr2[b[0]][b[1]]!=0||arr2[c[0]][c[1]]!=0) continue;
				arr2[a[0]][a[1]] = 1;
				arr2[b[0]][b[1]] = 1;
				arr2[c[0]][c[1]] = 1;
				// for(int z=0;z<n;z++){
				// 	for(int x=0;x<m;x++){
				// 		cout << arr2[z][x];
				// 	}
				// 	cout << endl;
				// }
				int res = bfs();
				// cout<< res << "-----------------" << endl;
				v.push_back(res);
			}   
		}
	}
	sort(v.begin(),v.end());
	cout << square - 3 - one - v[0];
	return 0;
}