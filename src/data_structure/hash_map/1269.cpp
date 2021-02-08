#include <iostream>
#include <string>
#include <map>
using namespace std;
map<int,int> M;
int main(){
	int n,m; scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int a; scanf("%d",&a);
		M[a]++;
	}
	for(int i=0;i<m;i++){
		int a; scanf("%d",&a);
		M[a]++;
	}
	int cnt = 0;
	map<int,int>::iterator iter;
	for(iter=M.begin();iter!=M.end();iter++){
		if(iter->second==1) cnt++;
	}
	cout << cnt;
	return 0;
}