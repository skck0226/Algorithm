#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int visited[50];
int list[7];
vector<int> V;
void dfs(int remain, int n, int j){
	if(remain==0){
		for(int i=6;i>0;i--){
			cout << list[i] << " ";
		}
		cout << "\n";
		return;
	}
	for(int i=0;i<V.size();i++){
		if(i<j) continue;
		list[remain] = V[i];
		dfs(remain-1,n,i+1);
	}
}
int main(){
	while(1){
		int n; scanf("%d",&n);
		if(n==0) break;
		for(int i=0;i<n;i++){
			int a; scanf("%d",&a);
			V.push_back(a);
		}
		dfs(6,n,0);
		cout << "\n";
		V.clear();
	}
	return 0;
}