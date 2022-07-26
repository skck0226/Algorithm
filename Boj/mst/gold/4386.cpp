#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int parent[105];
typedef struct edge{
    int v1,v2;
    float w;
} Edge;
typedef struct coOrdinate{
    float x,y;
    int v;
} Co;
bool cmp(edge a, edge b){
    return a.w < b.w;
}
int find(int x){
    if(x==parent[x]) return parent[x];
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
int main(){
    int n;
    cin >> n;
    vector<coOrdinate> coOrdinates;
    vector<edge> edges;
    for(int i=1;i<=n;i++){
        float x,y;
        cin >> x >> y;
        Co co = {x,y,i};
        coOrdinates.push_back(co);
    }
    for(auto xy : coOrdinates){
        float x = xy.x;
        float y = xy.y;
        int v1 = xy.v;
        for(auto others : coOrdinates){
            float other_x = others.x;
            float other_y = others.y;
            int v2 = others.v;
            edge e = {v1,v2,sqrt( pow(x-other_x,2) + pow(y-other_y,2) )};
            edges.push_back(e);
        }
    }
    sort(edges.begin(),edges.end(),cmp);
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
    float cost = 0;
    for(auto e : edges){
        if(find(e.v1)==find(e.v2)) continue;
        _union(e.v1, e.v2);
        cost += e.w;
    }
    printf("%f\n",cost);
    return 0;
}