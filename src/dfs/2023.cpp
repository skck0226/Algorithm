#include <iostream>
using namespace std;
int n;
bool isPrime(int num){
    if(num<2) return false;
    for(int i=2; i*i<=num; i++){
        if(num%i == 0) return false;
    }
    return true;
}
void dfs(int remain, int num){
	if(!isPrime(num)) return ;
	if(remain==0){
		cout<<num<<endl;
	}
	for(int i=1;i<=9;i+=2){
		int x = num;
		x *= 10;
		x += i;
		dfs(remain-1,x);
	}
}
int main() {
	scanf("%d",&n);
	dfs(n-1,2);
	dfs(n-1,3);
	dfs(n-1,5);
	dfs(n-1,7);
	return 0;
}