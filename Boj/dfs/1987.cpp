#include <iostream>
#include <vector>
using namespace std;
int n,m;
char arr[21][21];
int visited[21][21];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int alpha[27]={0,};
vector<char> picked;
int dfs1(int y, int x){
	visited[y][x] = 1;	
	picked.push_back(arr[y][x]);
	int max=1;
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(visited[ny][nx]==1) continue;
		if(ny>=n||nx>=m||ny<0||nx<0) continue;
		int res, flag=0;
		for(int i=0;i<picked.size();i++){
			if(arr[ny][nx]==picked[i]){
				flag = 1;
				break;
			}
		}
		if(flag==1) continue;

		res = dfs1(ny,nx);
		if(max<res) max = res;

		picked.pop_back();
		visited[ny][nx] = 0;
	}
	return max > picked.size() ? max : picked.size();
}
int dfs2(int y, int x, int level){
	
	alpha[arr[y][x]-'A']++;
	int max=1;
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny>=n||nx>=m||ny<0||nx<0) continue;
		if(alpha[arr[ny][nx]-'A']>0){
			if(max < level) max = level;
			continue;
		}
		int ret = dfs2(ny,nx,level+1);
		if(max<ret) max = ret;

		alpha[arr[ny][nx]-'A']--;
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
	int res1 = dfs1(0,0);
	int res2 = dfs2(0,0,1);
	cout << res1 << endl;
	cout << res2 << endl;
	return 0;
}