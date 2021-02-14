#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	map<string,string> M;
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		string site,pw;
		cin >> site >> pw;
		M[site] = pw;
	}
	for(int i=0;i<m;i++){
		string s;
		cin >> s;
		cout << M[s] << "\n";
	}
	
	return 0;
}