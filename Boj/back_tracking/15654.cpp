#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int visited[10001];
int list[9];
vector<int> v;
void dfs(int remain){
	if(remain==0){
		for(int i=m;i>0;i--){
			cout << list[i] << " ";
		}
		cout << "\n";
		return;
	}
	for(int i:v){
		if(visited[i]==1) continue;
		list[remain] = i;
		visited[i] = 1;
		dfs(remain-1);
		visited[i] = 0;
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int a; scanf("%d",&a);
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	dfs(m);
	return 0;
}