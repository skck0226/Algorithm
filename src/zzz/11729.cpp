#include <stdio.h>
void solve(int n, char now, char dest, char temp){
	if(n==0) return;
	solve(n-1,now,temp,dest);
	printf("%d %d\n",now-'A'+1,dest-'A'+1);
	solve(n-1,temp,dest,now);
}
int main(int argc, char* argv[]) {
	int n;
	scanf("%d",&n);
	int arr[21];
	arr[0]=1;
	for(int i=1;i<n;i++){
		arr[i] = 2*arr[i-1]+1;
	}
	printf("%d\n",arr[n-1]);
	solve(n,'A','C','B');
	return 0;
}