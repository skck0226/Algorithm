#include <iostream>
#include <map>
using namespace std;
int parent[250000];
int find(int n){
	if(parent[n]==n) return n;
	return parent[n] = find(parent[n]);
}
void uni(int a, int b){
	parent[b] = a;
}
int main() {
	int t; scanf("%d",&t);
	for(int z=0;z<t;z++){
		int arr[250000];
		map<string,int> m;
		int f; scanf("%d",&f);
		int n = 1;
		for(int j=0;j<250000;j++){
			parent[j] = j;
			arr[j] = 1;
		}
		for(int i=0;i<f;i++){
			char a[21], b[21];
			scanf("%s %s",a,b);
			if(m.find(a)==m.end()){
				m.insert(pair<string,int>(a,n)); n++;
			}
			if(m.find(b)==m.end()){
				m.insert(pair<string,int>(b,n)); n++;
			}
			int x = find(m[a]);
			int y = find(m[b]);
			if(x==y) continue;
			if(x>y) swap(x,y);
			arr[x] += arr[y];
			uni(x,y);
			printf("%d\n",arr[x]);
		}
	}
	return 0;
}