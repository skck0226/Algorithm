#include <iostream>
using namespace std;

int main() {
	int n; scanf("%d",&n);
	int cnt = 0;
	for(int i=1;i<=n;i++){
		int temp = i;
		while(1){
			if(temp!=0&&temp%5==0){
				temp = temp/5;
				cnt++;
			}
			else break;
		}
	}
	cout << cnt;
	return 0;
}