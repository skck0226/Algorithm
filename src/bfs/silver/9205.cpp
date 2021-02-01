#include <iostream>
#include <cmath>
#include <queue>
#include <string.h>
using namespace std;

int main() {
	queue<int> qy,qx;
	int t; scanf("%d",&t);
	for(int z=0;z<t;z++){
		int arr[102][2];
		int visited[102];
		memset(visited,0,sizeof(int)*102);
		int n; scanf("%d",&n);
		int xhome,yhome;
		scanf("%d %d",&xhome,&yhome);
		qy.push(yhome); qx.push(xhome);
		int flag = 0;
		for(int i=0;i<n;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			arr[i][0] = x; arr[i][1] = y;
			
		}
		int xend,yend; scanf("%d %d",&xend,&yend);
		arr[n][0] = xend; arr[n][1] = yend;
		while(!qy.empty()){
			int cy = qy.front(); qy.pop();
			int cx = qx.front(); qx.pop();
			if(cy == yend && cx == xend){
				flag = 1;
				while(!qy.empty()){
					qy.pop(); qx.pop();
				}
				break;
			}
			for(int i=0;i<=n;i++){
				if(visited[i]!=1){
					if(abs(cy-arr[i][1])+abs(cx-arr[i][0]) <= 1000){
						visited[i] = 1;
						qy.push(arr[i][1]); qx.push(arr[i][0]);
					}
				}
			}
		}
		
		if(flag == 0) cout<<"sad"<<endl;
		else cout << "happy" << endl;
	}
	return 0;
}