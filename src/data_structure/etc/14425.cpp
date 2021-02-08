#include <iostream>
#include <set>
#include <string>
using namespace std;
set<string> s;
int main(){
	int n,m; scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		string str; cin >> str;
		s.insert(str);
	}
	int cnt = 0;
	for(int j=0;j<m;j++){
		string str; cin >> str;
		if(s.find(str)!=s.end()) cnt++;
	}
	cout << cnt;
	return 0;
}