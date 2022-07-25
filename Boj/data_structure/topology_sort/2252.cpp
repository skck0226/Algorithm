#include <iostream>
#include <vector>
#include <deque>
using namespace std;
vector<int> out_v[32005];
vector<int> in_v[32005];
vector<int> res;
deque<int> q;
int visited[32005];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        q.push_back(a);
        out_v[a].push_back(b);
        in_v[b].push_back(a);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop_front();
        if(visited[now]) continue;
        if(in_v[now].size()){
            while(in_v[now].size()){
                int x = in_v[now].back();
                if(out_v[x].size()) q.push_front(x);
                else q.push_back(now);
                in_v[now].pop_back();
            }
            continue;
        }
        visited[now] = 1;
        res.push_back(now);
        while(out_v[now].size()){
            q.push_back(out_v[now].back());
            out_v[now].pop_back();
        }
    }

    for(auto i : res){
        cout << i << " ";
    }
    for(int i=1;i<=n;i++){
        if(visited[i]==0) cout << i << " ";
    }
    return 0;
}