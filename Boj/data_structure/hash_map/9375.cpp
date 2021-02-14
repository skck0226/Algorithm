#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	int t; cin >> t;
	for(int z=0;z<t;z++){
		map<string,int> M;
		int n; cin >> n;
		for(int i=0;i<n;i++){
			string a,b;
			cin >> a >> b;
			M[b]++;
		}
		int cnt = 1;
		if(M.size()==1) cout << n << "\n";
		else{
			for(auto it=M.begin();it!=M.end();it++){
				int x = it->second;
				cnt *= (x+1);
			}
			cout << cnt-1 << "\n";
		}
	}
	return 0;
}