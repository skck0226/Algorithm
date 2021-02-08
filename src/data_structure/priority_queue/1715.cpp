#include <iostream>
#include <queue>
using namespace std;
struct cmp{
	bool operator()(int a, int b){
		return a>b;	
	}
};
priority_queue<int,vector<int>,cmp> pq;
int main(){
	int sum=0;
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a; scanf("%d",&a);
		pq.push(a);
	}
	while(!pq.empty()){
		if(pq.size()==1){	
			break;
		}
		int x = pq.top(); pq.pop();
		int y = pq.top(); pq.pop();
		int z;
		z = x+y;
		sum += z;
		if(pq.size()==0) break;
		pq.push(z);
	}
	cout << sum;
	return 0;
}