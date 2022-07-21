#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[100002];
struct edge{
    int v1, v2, w;
};
bool cmp(edge a, edge b){
    return a.w < b.w;
}
int find(int x){
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}
void _union(int x, int y){
    if(x>y){
        int tmp = x;
        x = y;
        y = tmp;
    }
    x = find(x);
    y = find(y);

    parent[y] = x;
}
vector<edge> edges;
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        edge e;
        e.v1 = v1;
        e.v2 = v2;
        e.w = w;
        edges.push_back(e);
    }
    sort(edges.begin(),edges.end(),cmp);
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
    int cost = 0;
    for(auto e : edges){
        if(find(e.v1)==find(e.v2)) continue;
        _union(e.v1,e.v2);
        cost += e.w;
    }
    cout << cost << endl;
    return 0;
}