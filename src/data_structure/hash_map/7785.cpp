#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(){
	map<string,bool,greater<string> > m;
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++){
		string name,state;
		cin >> name >> state;
		if(state=="enter") m[name] = true;
		else m[name] = false;
	}
	
	for(auto iter = m.begin();iter!=m.end();iter++){
		if(iter->second){
			cout << iter->first << "\n";
		}
	}
	return 0;
}