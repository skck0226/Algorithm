#include <iostream>
#include <vector>
using namespace std;
int n,m;
char arr[21][21];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int dfs(int y, int x, vector<char> picked){
	if(y>=n||x>=m||y<0||x<0) return picked.size();
	for(int i=0;i<picked.size();i++){
		if(arr[y][x]==picked[i]){
			return picked.size();
		}
	}
	picked.push_back(arr[y][x]);
	// for(int i=0;i<picked.size();i++){
	// 	cout << picked[i] << endl;
	// }
	// cout << picked.size() << endl;
	// cout << "----------" << endl;
	int max=0;
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		int res = dfs(ny,nx,picked);
		// cout << res << endl;
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
	if(res==0) cout <<"1";
	else cout << res;
	return 0;
}