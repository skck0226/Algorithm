#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
struct cmp{
	bool operator()(int a,int b){
		if(abs(a)==abs(b)) return a>b;
		return abs(a)>abs(b);
	}
};
priority_queue<int,vector<int>,cmp> pq;
int main(){
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a; scanf("%d",&a);
		if(a==0){
			if(pq.empty()) cout << "0\n";
			else{
				printf("%d\n",pq.top());
				pq.pop();
			}
		}
		else pq.push(a);
	}
	return 0;
}