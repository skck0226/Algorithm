#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int arr[201][201];
int visited[201][201];
bool check(int y, int x, int cnt){
	if(y<0||x<0||y>=n||x>=m) return false;
	if(visited[y][x]>0) return false;
	
	return true;	
}
int main(){
	vector<pair<int,pair<int,int>>> v;
	queue<int> qy,qx,qcnt;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]>0) v.push_back({arr[i][j],{i,j}});
		}
	}
	sort(v.begin(), v.end());
	for(int i=0;i<v.size();i++){
		int y = v[i].second.first;
		int x = v[i].second.second;
		qy.push(y); qx.push(x); qcnt.push(0);
		visited[y][x] = arr[y][x];
	}
	int s,x,y; scanf("%d %d %d",&s,&x,&y);
	x-=1; y-=1;
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		int ccnt = qcnt.front(); qcnt.pop();
		// cout << cy <<"  "<<cx<<endl;
		if(s==ccnt) break;
		for(int i=0;i<4;i++){
			int ny = cy +dy[i];
			int nx = cx +dx[i];
			if(check(ny,nx,ccnt)){
				visited[ny][nx] = visited[cy][cx];
				qy.push(ny); qx.push(nx); qcnt.push(ccnt+1);
			}
		}
	}
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout << visited[i][j];
	// 	}
	// 	cout << endl;
	// }
	cout << visited[x][y]; 
	return 0;
}