#include <iostream>
#include <queue>
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
	visited[from] = 1;
	if(from==0){
		from++;
		cnt++;
	}
	if(to==0){
		to++;
		cnt++;
	}
	if(to==from){
		if(cnt==2) cout << "0";
		else cout << cnt;
	}
	// else if(to%2==0&&(to/2)%from==0){
	// 	cout << cnt;
	// }
	else{
		queue<int> q,qcnt;
		q.push(from); qcnt.push(cnt);
		
		while(!q.empty()){
			int now = q.front(); q.pop();
			int ccnt = qcnt.front(); qcnt.pop();
			if(now==to){
				cout << ccnt;
				return 0;	
			}
			int x = now;
			while(x<=to){
				if(x==to){
					cout << ccnt;
					return 0;
				}
				int arr[3]={0,};
				arr[1] = go(x);
				arr[2] = back(x);	
				// cout << ccnt+1 << " " << arr[1] 
				// << " " << arr[2] << endl;
				for(int i=1;i<3;i++){
					
					if(check(arr[i])){
						q.push(arr[i]); qcnt.push(ccnt+1);
						visited[arr[i]] = 1;
					}
				}
				x*=2;	
			}
		}
	}
	return 0;
}