#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int indegree[32001] = {
    0,
};
vector<int> v[32001];
priority_queue<int> q;
int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        indegree[b]++;
    }
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) q.push(-i);
    }
    while(!q.empty()){
        int now = -q.top();
        q.pop();
        cout << now << " ";
        while(v[now].size()){
            int next = v[now].back();
            if(--indegree[next]==0) q.push(-next);
            v[now].pop_back();
        }
    }

    return 0;
}