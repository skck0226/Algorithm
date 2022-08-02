#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int z=0;z<t;z++){
        int n, m, target;
        int cost[1001] = {0,};
        int indegree[1001]={0,};
        int dp[1001] = {0,};
        vector<int> v[1001];
        queue<int> q,qcnt,qsum;
        cin >> n >> m;
        for(int i=1;i<=n;i++){
            cin >> cost[i];
        }
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            indegree[b]++;
        }
        cin >> target;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push(i); qsum.push(cost[i]);
            }
        }
        int cntFlag = 0;
        while(!q.empty()){
            int now = q.front(); q.pop();
            int sum = qsum.front(); qsum.pop();
            if (now == target){
                cout << sum << endl;
                break;
            }
            while(v[now].size()){
                int next = v[now].back();
                v[now].pop_back();
                if(dp[next]<sum+cost[next]) dp[next] = sum+cost[next];
                if (--indegree[next] == 0){
                    q.push(next);
                    qsum.push(dp[next]);
                }
            }
        }
    }
    return 0;
}