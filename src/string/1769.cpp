#include <iostream>
#include <string>
using namespace std;

int main(){
	string c;
	cin >> c;
	int cnt = 0;
	while(1){
		if(c.size()<=1) break;
		int sum = 0;
		for(int i=0;i<c.size();i++){
			sum += (c[i]-'0');
		}
		cnt++;
		c.clear();
		while(sum>0){
			c.push_back((sum%10)+'0');
			sum /= 10;
		}
	}
	cout << cnt << endl;
	if((c[0]-'0')%3==0) cout << "YES";
	else cout << "NO";
	
	return 0;
}