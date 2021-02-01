#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;
int visited[10000];
int record[2][10000];
char s[4] = {'D','S','L','R'};
int D(int x){
	return (2*x) % 10000;
}
int S(int x){
	return (x + 9999) % 10000;
}
int L(int x){	
	return (x * 10) % 10000 + (x/1000);
}
int R(int x){
	return  x / 10 + (x % 10) * 1000;
}
int main() {
	int t; scanf("%d",&t);
	for(int z=0;z<t;z++){
		vector<int> v;
		queue<int> q;
		for(int i=0;i<2;i++) memset(record[i],0,sizeof(record[i]));
		memset(visited,0,sizeof(visited));
		int from,to; scanf("%d %d",&from,&to);
		q.push(from);
		visited[from] = 1;
		record[0][from] = -1;
		while(!q.empty()){
			int now = q.front(); q.pop();
			int arr[4]={0,};
			arr[0] = D(now);
			arr[1] = S(now);
			arr[2] = L(now);
			arr[3] = R(now);
			int flag = 0;
			for(int i=0;i<4;i++){
				if(arr[i]==to){
					flag = 1;
					if(now!=from){
						while(1){	
							v.push_back(now);
							now = record[0][now];
							if(record[0][now]==-1) break;
						}
					}
					for(int j=v.size()-1;j>=0;j--){
						printf("%c",s[record[1][v[j]]]);
					}
					printf("%c\n",s[i]);
					break;
				}
				if(visited[arr[i]]==1) continue;
				visited[arr[i]] = 1;
				record[0][arr[i]] = now;
				record[1][arr[i]] = i;
				q.push(arr[i]);
			}
			if(flag==1) break;
		}
	}
	return 0;
}