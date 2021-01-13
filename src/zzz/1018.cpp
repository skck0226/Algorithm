#include <iostream>
using namespace std;
char c[51][51];
int white(int a, int b){
	int i,j;
	int cnt=0;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if((i+j)%2==0 && c[a+i][b+j]=='B') cnt++;
			if((i+j)%2==1 && c[a+i][b+j]=='W') cnt++;
		}
	}
	return cnt;
}
int black(int a, int b){
	int i,j;
	int cnt=0;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if((i+j)%2==0 && c[a+i][b+j]=='W') cnt++;
			if((i+j)%2==1 && c[a+i][b+j]=='B') cnt++;
		}
	}
	return cnt;
}
int main(void) {
	int n,m;
	int i,j;
	int min=9999999;
	scanf("%d %d",&n,&m);
	char z; scanf("%c",&z);
	for(i=0;i<n;i++){
		string x;
		getline(cin,x);
		for(int j=0;j<m;j++){
			c[i][j] = x[j];
		}
	}
	
	for(i=0;i<=n-8;i++){
		for(j=0;j<=m-8;j++){
			if(black(i,j)<min) min=black(i,j);
			if(white(i,j)<min) min=white(i,j);
		}
	}
	printf("%d",min);
	return 0;
}
