#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int t; scanf("%d",&t);
	for(int z=0;z<t;z++){
		string c;
		cin >> c;
		int a=0,b=0;
		for(int i=0;i<3;i++){
			a += (c[i]-'A')*pow(26,2-i);
		}
		for(int i=4;i<8;i++){
			b += ((c[i]-'0')*pow(10,7-i));
		}
		if(abs(a-b)<=100) cout << "nice" << endl;
		else cout << "not nice" << endl;
	}
	
	return 0;
}