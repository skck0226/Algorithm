#include <iostream>
#include <queue>
using namespace std;
struct cmp{
	bool operator()(long long int a,long long int b){
		return a>b;
	}
};
priority_queue<long long int ,vector<long long int>,cmp> pq;
long long int sum = 0;
int main(){
	int n,m; scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int a; scanf("%d",&a);
		pq.push(a);
	}
	for(int i=0;i<m;i++){
		long long int x = pq.top(); pq.pop();
		long long int y = pq.top(); pq.pop();
		pq.push(x+y); pq.push(x+y);	
	}
	for(int i=0;i<n;i++){
		sum += pq.top(); pq.pop();
	}
	printf("%lld",sum);
	return 0;
}