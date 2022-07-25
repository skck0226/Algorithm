#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
vector<int> v;
int *parent;
int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
int _union(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return 1;
    if(x>=y) parent[x] = y;
    else parent[y] = x;
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    parent = (int*)malloc(sizeof(int) * n);
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        if(v.size()==0){
            if(_union(a,b)){
                v.push_back(i+1);
                free(parent);
                continue;
            }
        }
    }
    if(v.size()) cout << v[0] << endl;
    else cout << 0 << endl;
    return 0;
}
