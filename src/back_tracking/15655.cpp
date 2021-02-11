#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int list[9];
vector<int> v;
void dfs(int remain, int j){
	if(remain==0){
		for(int i=m;i>0;i--){
			cout << list[i] << " ";
		}
		cout << "\n";
		return;
	}
	for(int i=0;i<v.size();i++){
		if(i<j) continue;
		list[remain] = v[i];
		dfs(remain-1,i+1);
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int a; scanf("%d",&a);
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	dfs(m,0);
	return 0;
}