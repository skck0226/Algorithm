#include <iostream>
#include <queue>
#include <string.h>
#include <map>
#include <set>
using namespace std;

int n,m;
char arr[1001][1001];
int arr2[1001][1001] = {0,}; 

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int visited[1001][1001];
int dp[1001][1001] = {0,};

map<int,int> block2cnt;
int block = 1;
void bfs(int y, int x){
    if(dp[y][x]!=0) return ;
    queue<int> qy,qx;
    vector<int> vy,vx;
    for(int i=0;i<n;i++){
        memset(visited[i], 0, sizeof(visited[i]));
    }
    qy.push(y); qx.push(x);
    vy.push_back(y); vx.push_back(x);
    visited[y][x] = 1;
    int cnt = 0;
    while(!qy.empty()){
        cnt++;
        int cy = qy.front(); qy.pop();
        int cx = qx.front(); qx.pop();

        for(int i=0;i<4;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny>=n||nx>=m||ny<0||nx<0) continue;
            if(visited[ny][nx]==1 || arr[ny][nx]=='1') continue;
            qy.push(ny); qx.push(nx);
            vy.push_back(y); vx.push_back(x);
            visited[ny][nx] = 1;
        }
    }
    for(int i=0;i<vy.size();i++){
        dp[vy[i]][vx[i]] = block;
    }
    block2cnt[block] = cnt;  
    block++;
    return ;
}
int around(int y, int x){
    int cnt = 0;
    set<int> block_set;
    for(int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        block_set.insert(dp[ny][nx]);
    }
    for(auto set : block_set){
        cnt += block2cnt[set];
    }
    return cnt;
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='0') bfs(i,j);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='1') arr2[i][j] = around(i,j)%10;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << dp[i][j];
        }
        cout << endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << arr2[i][j];
        }
        cout << endl;
    }
    return 0;
}