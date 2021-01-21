#include <iostream>
#include <string.h>
using namespace std;
int parent[1000001];
int find(int n){
	if(parent[n]==n) return n;
	return parent[n] = find(parent[n]);
}
void uni(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b) return;
	if(a<b) parent[b] = a;
	else parent[a] = b;
}
int main() {
	int t; scanf("%d",&t);
	for(int z=0;z<t;z++){
		int n,k; scanf("%d %d",&n,&k);
		for(int i=0;i<n;i++){
			parent[i] = i;
		}
		for(int i=0;i<k;i++){
			int a,b; scanf("%d %d",&a,&b);
			uni(a,b);
		}
		int m; scanf("%d",&m);
		cout<<"Scenario "<< z+1 <<":"<<endl;
		for(int i=0;i<m;i++){
			int c,d; scanf("%d %d",&c,&d);
			if(find(c)==find(d)) cout << "1\n";
			else cout << "0\n";
		}
		cout << "\n";
	}
	return 0;
}