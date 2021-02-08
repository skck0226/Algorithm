#include <iostream>
using namespace std;
int memo[11000];
int fact(int n){
	if(n==1) return 1;
	return n*memo[n-1];
}
int main() {
	int n,k; scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		memo[i] = fact(i);
	}
	if(n==k||k==0) cout << "1";
	else cout << memo[n]/(memo[k]*memo[n-k]);
	
	return 0;
}