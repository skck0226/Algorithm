#include <iostream>
#include <vector>
using namespace std;
int n;
int del;
int cnt = 0;
int parent[51];
int child[51];
vector<int> tree[51];
void dfs(int node){
	if(node==del) return;
	if(tree[node].size==0) cnt++;
	for(int i=0;i<tree[node].size();i++){
		int next = tree[node][i];
		dfs(next);
	}
}
int main() {
	scanf("%d",&n);
	scanf("%d",&parent[0]);
	for(int i=1;i<n;i++){
		scanf("%d",&parent[i]);
		tree[parent[i]].push_back(i);
	}
	scanf("%d",&del);
	dfs(0);
	cout << cnt;
	return 0;
}