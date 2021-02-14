#include <iostream>
using namespace std;

int main() {
	int k; scanf("%d",&k);
	int dpA[46];
	int dpB[46];
	dpA[0] = 1; dpB[0] = 0;
	for(int i=1;i<=k;i++){
		dpA[i] = dpB[i-1];
		dpB[i] = dpA[i-1] + dpB[i-1];
	}
	cout << dpA[k] << " " << dpB[k];
	return 0;
}