#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string,int> ntoi;
map<int,string> iton;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	// 중요!! 위의 방식 쓴다면 scanf, cin과 혼용 불가!!
	int n,m; cin >> n >> m;
	for(int i=1;i<=n;i++){
		string name;
		cin >> name;
		iton[i] = name;	
		ntoi[name] = i;
	}
	for(int i=1;i<=m;i++){
		string s;
		cin >> s;
		if(s[0]>='1'&&s[0]<='9'){
			int num = stoi(s);
			cout << iton[num] << "\n";
		}
		else{
			cout << ntoi[s] << "\n";
		}
	}
	return 0;
}