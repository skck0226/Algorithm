#include <iostream>
#include <vector>
using namespace std;
int parent[10002];
int find(int n){
	if(parent[n]==n) return n;
	return parent[n] = find(parent[n]);
}
void uni(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b) return;
	if(a<b) parent[b] = a;
	else parent[a] = b;
}
int main() {
	int n,m,k;
	int cost[10001];
	vector<int> v[10001];
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<=n;i++){
		parent[i] = i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&cost[i]);
	}
	for(int i=0;i<m;i++){
		int a,b; scanf("%d %d",&a,&b);
		uni(a,b);
	}
	for(int i=1;i<=n;i++){
		v[find(i)].push_back(i);
	}
	int cnt = 0;
	for(int i=1;i<=n;i++){
		int min = 987654321;
		int toUni;
		for(int j=0;j<v[i].size();j++){
			if(min>cost[v[i][j]]){
				toUni = v[i][j];
				min = cost[v[i][j]];
			}
		}
		if(min!=987654321) cnt += min;
		uni(0,toUni);
	}
	int x = find(0);
	int flag = 0;
	for(int i=1;i<=n;i++){
		int y = find(i);
		if(y!=x){
			flag = 1;
			break;
		}
	}
	if(flag==1||cnt>k) cout << "Oh no";
	else cout << cnt;
	return 0;
}