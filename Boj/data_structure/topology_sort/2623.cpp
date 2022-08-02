#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> v[1001], out;
queue<int> q;
int main(){
    int n,m;
    int indegree[1001]={0,};
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int l;
        int arr[1001];
        cin >> l;
        for(int j=0;j<l;j++){
            cin >> arr[j];
        }
        for(int j=0;j<l-1;j++){
            for(int k=j+1;k<l;k++){
                v[arr[j]].push_back(arr[k]);
                indegree[arr[k]]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int now = q.front(); q.pop();
        out.push_back(now);
        while(v[now].size()){
            int next = v[now].back();
            v[now].pop_back();
            if(--indegree[next]==0){
                q.push(next);
            }
        }
    }
    if(out.size()==n){
        for(auto i:out) cout << i << "\n";
    }
    else cout << 0 << endl;
    return 0;
}