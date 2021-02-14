#include <iostream>
#include <vector>
using namespace std;
int n;
int maxi=-1999999999,mini=1999999999;
int visited[11]={0,};
char o[4] = {'+','-','*','/'};
char list[11];
vector<char> op;
vector<int> num;
int cal(char op[11]){
	int x = num[0];
	for(int i=1;i<n;i++){
		if(op[i]=='+'){
			x += num[i];
		}
		if(op[i]=='-'){
			x -= num[i];
		}
		if(op[i]=='*'){
			x *= num[i];
		}
		if(op[i]=='/'){
			x /= num[i];
		}
	}
	return x;
}
void dfs(int remain){
	if(remain==0){
		int c = cal(list);
		if(maxi<c) maxi = c;
		if(mini>c) mini = c;
		return;
	}
	for(int i=0;i<op.size();i++){
		if(visited[i]==1) continue;
		visited[i] = 1;
		list[remain] = op[i];
		dfs(remain-1);
		visited[i] = 0;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a; scanf("%d",&a);
		num.push_back(a);
	}
	for(int i=0;i<4;i++){
		int x; scanf("%d",&x);
		for(int j=0;j<x;j++){
			op.push_back(o[i]);
		}
	}
	dfs(n-1);
	cout << maxi << "\n" << mini;
	return 0;
}