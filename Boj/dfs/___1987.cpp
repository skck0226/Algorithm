#include <iostream>
#include <vector>
using namespace std;
int n,m;
char arr[21][21];
int visited[21][21];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int dfs(int y, int x, vector<char> picked){
	
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
		if(visited[ny][nx]==1) continue;
		if(ny>=n||nx>=m||ny<0||nx<0) continue;
		int res,flag=0;
		for(int i=0;i<picked.size();i++){
			if(arr[ny][nx]==picked[i]){
				res = picked.size()-1;
				flag = 1;
				break;
			}
		}
		if(flag==1){
			if(max<res) max = res;
			continue;
		}
		visited[ny][nx] = 1;	
		res = dfs(ny,nx,picked);
		picked.pop_back();
		visited[ny][nx] = 0;
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
	visited[0][0] = 1;
	int res = dfs(0,0,picked);
	if(res==0) cout <<"1";
	else cout << res;
	return 0;
}