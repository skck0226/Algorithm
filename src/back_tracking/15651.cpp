#include <iostream>

using namespace std;
int n,m;
int list[8];
void dfs(int remain){
	if(remain==0){
		for(int i=m;i>0;i--){
			cout << list[i] << " ";
		}
		cout << "\n";
		return;
	}
	for(int i=1;i<=n;i++){
		list[remain] = i;
		dfs(remain-1);
	}
}
int main(){
	scanf("%d %d",&n,&m);
	
	dfs(m);
	return 0;
}