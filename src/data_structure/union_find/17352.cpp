#include <iostream>
#include <set>
using namespace std;
int n;
int parent[300003];
int visit[300003];
set<int> s;
int find(int n){
	if(parent[n]==n) return n;
	return parent[n] = find(parent[n]);
}
void uni(int a, int b){
	if(a==b) return;
	if(a<b) parent[b] = a;
	else parent[a] = b;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		parent[i] = i;
	}
	int cnt = 0;
	for(int i=0;i<n-2;i++){
		int a,b; scanf("%d %d",&a,&b);
		a = find(a);
		b = find(b);
		visit[a] = 1;
		visit[b] = 1;
		uni(a,b);	
	}
	for(int i=1;i<=n;i++){
		s.insert(find(i));
	}
	if(s.size()==0){
		cout << "1 2";
		return 0;
	}
	else if(s.size()==1){
		for(int i=1;i<=n;i++){
			if(visit[i]==0){
				auto it = s.begin();
				advance(it, 0);
				cout << *it << " "<< i;
				return 0;
			}
		}
	}
	else{
		auto it = s.begin();
		cout << *it << " ";
		advance(it, 1);
		cout << *it;
		return 0;
	}
}