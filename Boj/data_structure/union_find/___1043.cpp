#include <iostream>
#include <vector>
using namespace std;
int n,m;
int k;
vector<int> v;
int parent[51];
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
	scanf("%d %d",&n,&m);
	for(int i=0;i<=n;i++){
		parent[i] = i;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int a; scanf("%d",&a);
		uni(0,a);
	}
	vector<int> arr[51];
	for(int i=0;i<m;i++){
		int num; scanf("%d",&num);
		for(int j=0;j<num;j++){
			int a; scanf("%d",&a);
			v.push_back(a);
			arr[i].push_back(a);
		}
		for(int j=1;j<v.size();j++){
			uni(v[j],v[j-1]);
		}
		v.clear();
	}
	int cnt = 0;
	for(int i=0;i<m;i++){
		int flag = 0;
		for(int j=0;j<arr[i].size();j++){
			if(parent[arr[i][j]]==0){
				flag = 1;
				break;
			}
		}
		if(flag==0) cnt++;
	}
	// for(int i=0;i<=n;i++){
	// 	cout << parent[i] <<endl;
	// }
	cout << cnt;
	return 0;
}