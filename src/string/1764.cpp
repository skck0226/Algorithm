#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(){
	set<string> v;
	map<string,int> M;
	int n,m;
	cin >> n >> m;	
	for(int i=0;i<n;i++){
		string c;
		cin >> c;
		M[c]++;
	}
	for(int i=0;i<m;i++){
		string c;
		cin >> c;
		M[c]++;
		if(M[c]==2) v.insert(c);
	}
	cout << v.size() << endl;
	set<string> ::iterator iter;
	for(iter=v.begin();iter!=v.end();iter++){
		cout << *iter << "\n";
	}
	return 0;
}