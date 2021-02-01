#include <iostream>
#include <queue>
using namespace std;
int n,m;
int arr[1001][1001];
bool check(int vy, int vx){
	if(vy<0 || vx<0 || vy>=n || vx>=m) return false;
	else if(arr[vy][vx]==0){
		return true;
	}
	else return false;
}
int main() {
	scanf("%d %d",&m,&n);
	queue<int> qy,qx,qcnt;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==1){
				qy.push(i); qx.push(j); qcnt.push(0);
			}
		}
	}
	int cnt=0;
	if(qy.size()==n*m){
		cout << "0";
	}
	else{
		while(!qy.empty()){
			int cy = qy.front(); qy.pop();
			int cx = qx.front(); qx.pop();
			int ccnt = qcnt.front(); qcnt.pop();
			
			arr[cy][cx] = 1;	
			
			if(check(cy-1,cx)){ 
				arr[cy-1][cx]=1;
				qy.push(cy-1);qx.push(cx);qcnt.push(ccnt+1);
			}
			if(check(cy,cx-1)){ 
				arr[cy][cx-1]=1;
				qy.push(cy);qx.push(cx-1);qcnt.push(ccnt+1);
			}
			if(check(cy,cx+1)){ 
				arr[cy][cx+1]=1;
				qy.push(cy);qx.push(cx+1);qcnt.push(ccnt+1);
			}
			if(check(cy+1,cx)){ 
				arr[cy+1][cx]=1;
				qy.push(cy+1);qx.push(cx);qcnt.push(ccnt+1);
			}
			if(qcnt.empty()) cnt = ccnt;
		}
		int z=0;
		for(int i=0;i<n;i++){
			if(z==1) break;
			for(int j=0;j<m;j++){
				if(arr[i][j]==0){
					z=1; break;
				}
			}
		}
		if(z==1) cout << "-1";
		else cout << cnt;
	}
	return 0;
}