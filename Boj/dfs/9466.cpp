#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int arr[100005];
int visited[100005];
int from[100005];
int dfs(int turn, int node){
    if(visited[node]==turn){
        int cnt = 1;
        for(int back=from[node]; back!=node; back=from[back]){
            cnt++;
        }
        return cnt;
    }
    if(visited[node]) return 0;
    visited[node] = turn;
    from[arr[node]] = node;
    return dfs(turn, arr[node]);
}

int main(){
    scanf("%d",&t);
    for(int z=0;z<t;z++){
        int n;
        int cnt = 0;
        scanf("%d",&n);
        memset(visited,0,sizeof(int*)*n);
        memset(from,0,sizeof(int*)*n);
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        for(int i=1;i<=n;i++){
            if(visited[i]==0){
                cnt += dfs(i,i);
            }
        }
        printf("%d\n",n-cnt);
    }
    return 0;
}