#include <iostream>
using namespace std;
int n,m;
int parent[100003];
int find(int n){
	if(parent[n]==n) return n;
	return parent[n] = find(parent[n]);
}
void uni(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b) return ;
	if(a<b) parent[b] = a;
	else parent[a] = b;
}
int main() {
	scanf("%d %d",&n,&m);
	for(int i=0;i<=n;i++){
		parent[i] = i;
	}
	int cnt = 0;
	for(int i=0;i<m;i++){
		int x; scanf("%d",&x);
		if(find(x)==0){
			cout << cnt;
			return 0;
		}		
		cnt++;
		uni(find(x),find(x)-1);
	}
	cout << cnt;
	return 0;
}