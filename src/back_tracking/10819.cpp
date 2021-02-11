#include <iostream>
#include <cmath>
using namespace std;
int n;
int arr[9];
int visited[9];
int list[9];
int maxi = 0;
int cal(int list[9]){
	int sum = 0;
	for(int i=1;i<n;i++){
		sum += abs(list[i]-list[i+1]);
	}
	return sum;
}
void dfs(int remain){
	if(remain==0){	
		// for(int i=n;i>0;i--){
		// 	cout << list[i] << " ";
		// }
		// cout << endl;
		int c = cal(list);
		if(maxi < c) maxi = c;
		return;
	}
	for(int i=0;i<n;i++){
		if(visited[i]==1) continue;
		visited[i] = 1;
		list[remain] = arr[i];
		dfs(remain-1);
		visited[i] = 0;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	dfs(n);
	cout << maxi;
	return 0;
}