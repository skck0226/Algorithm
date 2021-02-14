#include <iostream>
#include <queue>
#include <set>
#include <string.h>
using namespace std;

int main(){
	int t; scanf("%d",&t);
	for(int z=0;z<t;z++){
		int n,m; scanf("%d %d",&n,&m);
		int arr[101];
		memset(arr,0,sizeof(int)*n);
		set<int> s;
		queue<int> q;
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
			if(i!=m){
				s.insert(arr[i]);
				q.push(arr[i]);
			}
			else{
				s.insert(arr[i]);
				q.push(-1);
			}
		}
		set<int>::iterator iter;
		// for(iter=s.begin();iter!=s.end();iter++){
		// 	cout<< *iter << endl;
		// }
		int cnt=0;
		iter = s.end();
		iter--;
		int flag = 0;
		while(!q.empty()){
			if(*iter==arr[m]){
				while(1){
					int now = q.front();
					q.pop();
					if(now==arr[m]) cnt++;
					if(now==-1){
						flag = 1;
						cout << cnt+1<<endl;
						break;
					}
				}	
				if(flag==1) break;
			}
			int now = q.front();
			q.pop();
			if(now!=*iter){
				q.push(now);
			}
			else{
				cnt++;
				iter--;
			}
			// cout<<now<<" " << cnt <<endl;
		}
	}
	return 0;
}