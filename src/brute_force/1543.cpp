#include <iostream>
#include <string>

using namespace std;

int main(){
	string a,b;
	getline(cin,a);
	getline(cin,b);
	int cnt = 0;
	for(int i=0;i<a.size();i++){
		int flag = 0;
		for(int j=0;j<b.size();j++){
			if(a[i+j]!=b[j]){
				flag = 1;
				break;
			}
		}
		if(flag==0){
			cnt++;
			i+=b.size()-1;	
		}
	}
	cout << cnt;
	return 0;
}