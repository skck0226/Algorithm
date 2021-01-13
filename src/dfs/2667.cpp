#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int arr[26][26];
vector<int> v;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
bool check(int vy,int vx){
	if(vy<0||vx<0||vy>=n||vx>=n) return false;
	if(arr[vy][vx]==0) return false;
	return true;
}
void dfs(int y, int x, int& cnt){
	arr[y][x]=0;
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(check(ny,nx)) dfs(ny,nx,cnt);
	}
	cnt++;
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%1d",&arr[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==1){
				int cnt=0;
				dfs(i,j,cnt);
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(),v.end());
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++) printf("%d\n",v[i]);
	return 0;
}