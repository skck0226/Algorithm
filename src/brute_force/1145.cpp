#include <iostream>

using namespace std;

int main(){
	int a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;
	for(int i=1;;i++){
		int cnt = 0;
		if(i%a==0) cnt++;
		if(i%b==0) cnt++;
		if(i%c==0) cnt++;
		if(i%d==0) cnt++;
		if(i%e==0) cnt++;
		if(cnt>=3){
			cout << i;
			break;
		}
	}
	return 0;
}