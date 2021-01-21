#include <iostream>
#include <vector>
using namespace std;
int n,m;
int arr[201][201];
int parent[201];
int find(int n){
	if(parent[n]==n) return n;
	return parent[n] = find(parent[n]);
}
void uni(int a, int b){
	if(a==b) return;
	a=find(a);
	b=find(b);
	if(a==b) return;
	if(a>b) parent[a] = b;
	else parent[b] = a;
}
int main(){
	vector<int> v;
	scanf("%d %d",&n,&m);
	for(int i=0;i<=n;i++){
		parent[i]=i;	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==1){
				uni(i,j);
			}
		}
	}
	for(int i=0;i<m;i++){
		int a; scanf("%d",&a);
		v.push_back(a);
	}
	int  x = find(v[0]);
	int flag = 0;
	for(int i=1;i<v.size();i++){
		if(find(v[i])!=x){
			flag = 1;
			break;
		}
	}
	if(flag==0) cout << "YES";
	else cout << "NO";
	
	return 0;
}