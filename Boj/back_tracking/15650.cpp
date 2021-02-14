#include <iostream>

using namespace std;
int n,m;
int list[9];
int visited[9]={0,};
void dfs(int remain,int j){
	if(remain==0){
		for(int i=0;i<m;i++){
			cout << list[i] << " ";
		}
		cout << "\n";	
		return;
	}
	for(int i=j;i<=n;i++){
		if(remain>(n-i+1)) return;
		if(visited[i]==1) continue;
		list[m-remain] = i;
		visited[i] = 1;
		dfs(remain-1,i+1);
		visited[i] = 0;
	}
}
int main(){
	scanf("%d %d",&n,&m);
	dfs(m,1);
	return 0;
}