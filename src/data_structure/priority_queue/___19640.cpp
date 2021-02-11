#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,m,k;
int arr[100001][2];
struct q{
	int d;
	int h;
	int n;
};
bool operator<(q a, q b){
	if(a.d==a.d){
		if(a.h==b.h) return (a.n)%m>(b.n)%m;
	 	return a.h>b.h;	
	}
	return a.d>b.d;
}
priority_queue<q> pq;
queue<pair<int,pair<int,int> > > v[100001];
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<=n/m;i++){
		for(int j=0;j<m;j++){
			if(i*m+j==n) break;
			int a,b; scanf("%d %d",&a,&b);
			v[j].push({a,{b,i*m+j} });
		}
	}
	int cnt = 0;
	for(int i=0;i<m;i++){
		if(i==n) break;
		pq.push({ v[i].front().first, v[i].front().second.first,
				 v[i].front().second.second });
		v[i].pop();
	}
	while(!pq.empty()){
		cout << pq.top().n << endl;
		if(pq.top().n==k){
			cout << cnt; 
			return 0;
		}
		int x = pq.top().n;
		x%=m;
		pq.pop();
		cnt++;
		if(v[x].empty()) continue;
		pq.push({ v[x].front().first, v[x].front().second.first,
				 v[x].front().second.second} );
		v[x].pop();
		
	}
	return 0;
}