#include <iostream>
#include <queue>
#include <string>
using namespace std;
int from,to;
int visited[100001];
int record[100001];
int jump(int n){
	return 2*n;
}
int go(int n){
	return n+1;
}
int back(int n){
	return n-1;
}
bool check(int n){
	if(n<0||n>100000) return false;
	if(visited[n]==1) return false;
	return true;
}
void recur(int n){
	if(n==-1) return;
	recur(record[n]);	
	printf("%d ",n);
}
int main(){
	scanf("%d %d",&from,&to);
	queue<int> q,qcnt;
	q.push(from); qcnt.push(0);
	visited[from] = 1;
	record[from] = -1;
	int cntFlag=-9;
	int cnt = 0;
	if(from==to){
		cout <<"1\n";
		cout << from << " " << to;
	}
	while(!q.empty()){
		int now = q.front(); q.pop();
		int ccnt = qcnt.front(); qcnt.pop();
		
		int arr[3]={0,};
		arr[0] = jump(now);
		arr[1] = go(now);
		arr[2] = back(now);
		for(int i=0;i<3;i++){
			if(arr[i]==to){
				cout << ccnt+1 << endl;
				recur(now);
				printf("%d",arr[i]);
				return 0;
			}
			if(check(arr[i])){
				visited[arr[i]] = 1;
				record[arr[i]] = now;
				q.push(arr[i]); qcnt.push(ccnt+1);
			}
		}
	}
	return 0;
}