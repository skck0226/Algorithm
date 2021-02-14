#include <iostream>
#include <queue>
using namespace std;
int main(){
	long long int a,b;
	scanf("%lld %lld",&a,&b);
	queue<int> q,qcnt;
	q.push(a); qcnt.push(0);
	int count = -1;
	while(!q.empty()){
		long long int num = q.front(); q.pop();
		int ccnt = qcnt.front(); qcnt.pop();
		if(num==b){
			count = ccnt+1;
			break;
		}
		if((2*num)<=b){
			q.push(2*num); qcnt.push(ccnt+1);
		}	
		if((10*num+1)<=b){
			q.push(10*num+1); qcnt.push(ccnt+1);			
		}
	}
	cout << count;
	return 0;
}