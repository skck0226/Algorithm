#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m; 
int cnt = 0;
int arr[21];
void dfs(int x,int sum){	
	if(x==n){
		if(sum==m){
			cnt++;	
		}
		return;
	}
	dfs(x+1,sum);
	dfs(x+1,sum+arr[x]);
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	dfs(0,0);
	if(m==0) cnt--;
	cout << cnt;
	return 0;
}