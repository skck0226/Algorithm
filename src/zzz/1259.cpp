#include <iostream>
#include <vector>
using namespace std;

int main() {
	while(1){
		int n, check=0;
		cin >> n;
		if(n==0) break;
		vector <int> x;
		while(n>0){
			x.insert(x.begin(),n%10);
			n/=10;
		}
		for(int i=0;i<x.size()/2;i++){
			if(x[i]!=x[x.size()-1-i]){
				check=1;
				break;
			}
		}
		if(check==1) printf("no\n");
		else printf("yes\n");
	}
	return 0;
}