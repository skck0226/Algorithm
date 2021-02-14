#include <iostream>
#include <deque>
#include <string.h>
using namespace std;
int from,to;
int visited[100001];
int go(int n){
	return n+1;
}
int back(int n){
	return n-1;
}
bool check(int n){
	if(n<0||n>100000) return false;
	if(visited[n]==1){
		if(n==to) return true;
		return false;
	}	
	return true;
}
int main(){
	int cnt=0;
	scanf("%d %d",&from,&to);
	deque<int> q,qcnt;
	q.push_front(from); qcnt.push_front(cnt);
	visited[from] = 1;
	
	while(!q.empty()){
		int now = q.front(); q.pop_front();
		int cnt = qcnt.front(); qcnt.pop_front();
		if(now==to){
			cout << cnt;
			return 0;
		}
		if((2*now)<100000&&visited[2*now]==0){
			q.push_front(2*now); qcnt.push_front(cnt);
			visited[2*now] = 1;
		}
		if(now-1>0&&visited[2*now]==0){
			q.push_front(now-1); qcnt.push_front(cnt+1);
			visited[now-1] = 1;
		}
		if(now+1<100001&&visited[2*now]==0){
			q.push_front(now+1); qcnt.push_front(cnt+1);
			visited[now+1] = 1;
		}
	}

	return 0;
}