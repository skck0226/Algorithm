#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n,m;
int visited[9];
int list[9];
vector<int> v;
set<string> S;
void dfs(int remain){
	if(remain==0){
		string str;
		for(int i=m;i>0;i--){
			str += to_string(list[i]);
			str += " ";
		}
		str.pop_back();
		S.insert(str);
		return;
	}
	for(int i=0;i<v.size();i++){
		if(visited[i]==1) continue;
		list[remain] = v[i];
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
	for(string i:S){
		for(auto j:i){
			if(j==' ') cout << " ";
			else printf("%d",j-'0');
		}
		cout << "\n";
	}
	return 0;
}