#include <iostream>
#include <string>
using namespace std;

int main(){
	string a,b;
	cin >> a >> b;
	int min=987654321;
	for(int i=0;i<=b.size()-a.size();i++){
		int cnt=0;
		for(int j=0;j<a.size();j++){
			if(a[j]!=b[i+j]) cnt++;
		}
		if(cnt<min) min = cnt;
	}
	cout << min;
	return 0;
}