#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int n,m;
int arr[51][51];
vector<pair<int,int>> v;
int visited[51][51];
int main(){
	scanf("%d %d",&n,&m);
	int V=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==2){
				v.push_back({i,j});
				V++;
			}
		}
	}
	
	return 0;
}