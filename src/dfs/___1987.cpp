#include <iostream>
#include <vector>
using namespace std;
int n,m;
int arr[21][21];
int dy[2] = {1,0};
int dx[2] = {0,1};
int dfs(int y, int x, vector<int> picked){
	if(y>=m||x>=n) return 0;
	for(int i=0;i<picked.size();i++){
		if(arr[y][x]==picked[i]) return picked.size();
	}
	picked.push_back(arr[y][x]);
	int max=0;
	for(int i=0;i<2;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		int res = dfs(ny,nx,picked);
		if(max<res) max = res;
	}
	return max;
}
int main() {
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		char c; scanf("%c",&c);
		for(int j=0;j<m;j++){
			scanf("%c",&arr[i][j]);
		}
	}
	vector<char> picked;
	int res = dfs(0,0,picked);
	cout << res;
	return 0;
}