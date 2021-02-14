#include <iostream>
using namespace std;

int main() {
	int n; scanf("%d",&n);
	n = 1000 - n;
	int cnt = 0;
	while(n>0){
		while(n>=500){
			n-=500;
			cnt++;
		}while(n>=100){
			n-=100;
			cnt++;
		}while(n>=50){
			n-=50;
			cnt++;
		}while(n>=10){
			n-=10;
			cnt++;
		}while(n>=5){
			n-=5;
			cnt++;
		}while(n>=1){
			n-=1;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}