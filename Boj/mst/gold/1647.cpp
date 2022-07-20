#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent[1000005];

struct edge{
	int v1;
	int v2;
	int weight;
};

bool cmp(const edge & a, const edge & b){
    return a.weight < b.weight;
}

int find(int x){
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}
int _union(int x, int y){
    if(x>y){
        int tmp = x;
        x = y;
        y = tmp;
    }
    x = find(x);
    y = find(y);

    parent[y] = x;
}

int main() {
	int n,m;
	vector<edge> edges;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		parent[i] = i;    
	}
	for(int i=0;i<m;i++){
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		edge e;
		e.v1 = v1;
		e.v2 = v2;
		e.weight = w;
		edges.push_back(e);
	}
	sort(edges.begin(),edges.end(),cmp);
    int cnt = 0;
    int sum = 0;
	for(edge edge : edges){
        if(cnt==n-1) break;
        if(find(edge.v1)==find(edge.v2)) continue;
        cnt++;
        sum += edge.weight;
	}
    cout << sum << endl;
	return 0;
}