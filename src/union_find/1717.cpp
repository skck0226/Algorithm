#include <iostream>
using namespace std;
int n,m;
int parent[1000001];
void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}
int find(int n){
	if(parent[n]==n) return n;
	
	return parent[n] = find(parent[n]);
}
void uni(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b) return;
	if(a<b)	parent[b] = a;
	else parent[a] = b;
}

int main() {
	scanf("%d %d",&n,&m);
	for(int i=0;i<=n;i++){
		parent[i] = i;
	}
	for(int i=0;i<m;i++){
		int a,b,q; scanf("%d %d %d",&q,&a,&b);
		if(q==0){
			uni(a,b);
		}
		else if(q==1){
			if(find(a)==find(b)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}