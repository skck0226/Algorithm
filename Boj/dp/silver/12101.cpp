#include <iostream>
#include <vector>
using namespace std;
int n,k;
vector<string> v[12];
int main(){
	scanf("%d %d",&n,&k);
	v[1].push_back("1");	
	v[2].push_back("1+1");	
	v[2].push_back("2");	
	v[3].push_back("1+1+1");	
	v[3].push_back("1+2");	
	v[3].push_back("2+1");	
	v[3].push_back("3");
	for(int i=4;i<=n;i++){
		int a,b,c;
		a = i-1; b = i-2; c = i-3;
		for(int j=0;j<v[a].size();j++){
			v[i].push_back("1+"+v[a][j]);
		}
		for(int j=0;j<v[b].size();j++){
			v[i].push_back("2+"+v[b][j]);
		}
		for(int j=0;j<v[c].size();j++){
			v[i].push_back("3+"+v[c][j]);
		}
	}
	
	if(k>v[n].size()) cout << "-1";
	else cout << v[n][k-1];
	
	return 0;
}