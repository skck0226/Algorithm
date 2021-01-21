#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
long long int k;
int n,m;
int cost[1000001];
int parent[1000001]={0};
int disconnect[1000001];
vector<int> v[1000001];
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
	scanf("%d %d %lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&cost[i]);
		parent[i] = i;
	}
	for(int i=0;i<m;i++){
		int a,b; scanf("%d %d",&a,&b);
		if(a<b) swap(a,b);
		if(b==1&&a==n){
			disconnect[1] = 1;
		}
		disconnect[a] = 1;
	}
	if(disconnect[1]!=1){
		uni(1,n);
	}
	for(int i=2;i<=n;i++){
		if(disconnect[i]==1) continue;
		uni(i,i-1);
	}
	set<int> s;
	int x = find(1);
	int flag = 0;
	for(int i=1;i<=n;i++){
		if(x!=find(i)) flag = 1;
		v[parent[i]].push_back(cost[i]);
		s.insert(parent[i]);
	}
	if(flag==0){
		cout << "YES";
		return 0;
	}
	long long int cnt = 0;
	for(auto i = s.begin(); i != s.end(); i++){
		int min = 987654321;
		for(int j=0;j<v[*i].size();j++){
			// cout << *i<<" "<<v[*i][j] << endl;
			if(min>v[*i][j]){
				min = v[*i][j];
			}
		}
		if(min==987654321) continue;
		cnt += min;
		if(cnt>k) break;
	}
	// cout << cnt << endl;
	if(cnt>k) cout << "NO";
	else cout <<"YES";
	return 0;
}