#include <iostream>
#include <string>
#include <set>
using namespace std;
set<string> S;
int main(){
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		S.insert(s.substr(i));
	}
	for(string iter : S){
		cout << iter << endl;
	}
	return 0;
}