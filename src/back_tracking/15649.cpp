#include <iostream>
using namespace std;
int n,m;
int visited[9];
int list[9];
void dfs(int remain){
	if(remain==0){
		for(int i=0;i<m;i++){
			cout <<list[i]<<" ";
		}
		cout << "\n";
		return;
	}
	for(int i=1;i<=n;i++){
		if(visited[i]==1) continue;
		list[m-remain] = i;
		visited[i] = 1;
		dfs(remain-1);
		visited[i] = 0;
	}	
}
int main() {
	cin >> n >> m;
	dfs(m);
	return 0;
}