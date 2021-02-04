#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
void dfs(int n){
	
	if(n==1){
		v.push_back(1);
		return;	
	}
	for(int i=1;i<250;i++){
		if(i*i==n){
			v.push_back(i);
			return;	
		}
		if(i*i>n){
			v.push_back(i-1);
			dfs(n-((i-1)*(i-1)));
			return;
		}
	}
}
int main(){
	int n; scanf("%d",&n);
	dfs(n);
	for(int i=0;i<v.size();i++){
		cout << v[i] << endl;
	}
	return 0;
}