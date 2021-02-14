#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;
int n;
int arr[21][21];
int visited[21];
deque<int> dq;
void dfs(vector<int> v, int remain, int now){
	if(remain==0){
		for(int i=0;i<v.size();i++){
			cout << v[i] << " ";
		}
		cout << endl;
		// int cnt = 0;
		// for(int i=0;i<v.size()-1;i++){
		// 	for(int j=i+1;j<v.size();j++){
		// 		cnt += arr[v[i]][v[j]];
		// 		cnt += arr[v[j]][v[i]];
		// 	}
		// }
		// dq.push_back(cnt);
		return;
	}
	for(int i=now;i<n;i++){
		if(visited[i]==1) continue;
		visited[i] =1;
		v.push_back(i);
		dfs(v,remain-1,i+1);
		visited[i] = 0;
		v.pop_back();
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	vector<int> v;
	dfs(v,n/2,0);
	int mini = 987654321;
	while(!dq.empty()){
		int head = dq.front(); dq.pop_front();
		int tail = dq.back(); dq.pop_back();
		if(mini>abs(head-tail)) mini = abs(head-tail);
	}
	cout << mini;
	return 0;
}