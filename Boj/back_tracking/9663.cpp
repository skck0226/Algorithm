#include <iostream>
#include <cmath>
using namespace std;
int n;
int col[16];
int cnt = 0;
bool check(int y){
	for(int i=0;i<y;i++){
		if(col[i]==col[y]) return false;
		if(abs(i-y)==abs(col[i]-col[y])) return false;
	}
	return true;
}
void dfs(int level){
	if(level==n){
		cnt++;	   
		return;
	}
	for(int i=0;i<n;i++){	
		col[level] = i;
		if(check(level)){
			dfs(level+1);
		}
		col[level] = 0;
	}
}
int main(){
	scanf("%d",&n);
	dfs(0);
	cout << cnt;
	return 0;
}