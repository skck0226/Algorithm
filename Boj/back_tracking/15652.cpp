#include <iostream>

using namespace std;
int n,m; 
int list[9];
void dfs(int remain,int j){
	if(remain==0){
		for(int i=m;i>0;i--){
			cout << list[i] << " ";
		}
		cout << "\n";
		return;
	}
	for(int i=1;i<=n;i++){
		if(i<j) continue;
		list[remain] = i;
		dfs(remain-1,i);
	}
}
int main(){
	scanf("%d %d",&n,&m);
	dfs(m,1);
	return 0;
}