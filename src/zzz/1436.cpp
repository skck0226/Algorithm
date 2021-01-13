#include <iostream>
using namespace std;

int main() {
	int n; scanf("%d",&n);
	int cnt=0;
	int s = 666;
	string str;
	while(1){
		str = to_string(s);
		if(str.find("666")!=-1) ++cnt;
		if(cnt == n){
			cout << s;
			break;	
		}
		s++;
	}
	return 0;
}