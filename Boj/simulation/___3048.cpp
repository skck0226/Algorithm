#include <iostream>

using namespace std;

int main(){
	int n,m; scanf("%d %d",&n,&m);
	char a[55],b[55];
	char c; scanf("%c",&c);
	for(int i=1;i<=n;i++){
		scanf("%c",&a[i]);
	}scanf("%c",&c);
	for(int i=1;i<=m;i++){
		scanf("%c",&b[i]);
	}scanf("%c",&c);
	int t; scanf("%d",&t);
	int indexA=n,indexB=1;
	for(int i=n;i>t;i--){
		cout<<a[i];
		indexA = i-1;
	}
	for(int i=1;i<t-m+1;i++){
		cout<<b[i];
		indexB = i+1;
	}
	while(1){
		int f1=0, f2 = 0;
		if(indexA>0){
			cout << a[indexA];
			indexA--;	
			f1 = 1;
		}
		if(indexB<=m){
			cout << b[indexB];
			indexB++;
			f2 = 1;
		}
		if(f1==0&&f2==0) break;
	}
	
	return 0;
}