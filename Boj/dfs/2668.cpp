#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int n;
vector<int> v[101];
int visited[101];
vector<int> picked;
vector<int> p;
int dfs(int node, int start){
//	cout << node << endl;
	if(visited[node]==1) return node;
	p.push_back(node);
	int res = 0;
	for(int i=0;i<v[node].size();i++){
		int next = v[node][i];
		visited[node] = 1;
		res = dfs(next);
	}
	return res;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a);
		v[i].push_back(a);
	}
	int cnt = 0;
	for(int i=1;i<=n;i++){
		int flag = 0;
		for(int j=0;j<picked.size();j++){
			if(picked[j]==i){
				flag = 1;
				break;
			}
		}
		if(flag == 1) continue;
		memset(visited,0,sizeof(visited));
		// if(visited[i]==1) continue;
		int res = dfs(i);
		if(res==i){
			while(p.size()!=0){
				int pop = p[p.size()-1];
				picked.push_back(pop);
				p.pop_back();
			}
		}
		p.clear();
	}
	sort(picked.begin(),picked.end());
	cout << picked.size()<<endl;
	for(int i=0;i<picked.size();i++){
		cout << picked[i] << endl;
	}
	return 0;
}