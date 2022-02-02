#include <iostream>
using namespace std;

int main() {
	int n,k;
	int arr[10];
	int cnt = 0;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=n-1;i>=0;i--){
		if(k<arr[i]) continue;
		cnt += k/arr[i];
		k %= arr[i];
	}
	cout << cnt;
	return 0;
}