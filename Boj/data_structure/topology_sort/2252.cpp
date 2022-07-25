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
// #include <iostream>
// #include <deque>
// #include <vector>
// using namespace std;
// int indegree[32005] = {0,};
// int visited[32005] = {0,};
// vector<int> v[32005];
// deque<int> q;
// int main(){
//     int n,m;
//     cin >> n >> m;
//     for(int i=0;i<m;i++){
//         int a,b;
//         cin >> a >> b;
//         indegree[b]++;
//         v[a].push_back(b);
//     }
//     for(int i=1;i<=n;i++){
//         if(indegree[i]==0) q.push_back(i);
//     }
//     while(!q.empty()){
//         int now = q.front();
//         q.pop_front();
//         if(visited[now]) continue;
//         visited[now] = 1;
//         for(auto next : v[now]){
//             if( --indegree[next]==0){
//                 q.push_back(next);
//             }
//         }
//         cout << now << " ";
//     }
//     return 0;
// }