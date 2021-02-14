#include <iostream>

using namespace std;
int n,m,k;
int arr[1001][1001]={0,};
int visited[1001][1001]={0,};
int dy[5] = {0,-1,1,0,0};
int dx[5] = {0,0,0,-1,1};
bool check(int y,int x){
	if(y<0||x<0||y>=n||x>=m) return false;
	if(arr[y][x]!=0) return false;
	return true;
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<k;i++){
		int a,b; scanf("%d %d",&a,&b);
		arr[a][b] = 2;
	}
	int starty,startx; scanf("%d %d",&starty,&startx);
	arr[starty][startx] = 1;
	int dir[4];
	for(int i=0;i<4;i++){
		scanf("%d",&dir[i]);
	}
	int y = starty, x = startx;
	for(int i=0;;i++){
		int head = dir[i%4];
		// cout << head << endl;
		if(head==1){
			int cnt = 0;
			for(int j=1;j<5;j++){
				int ny = y + dy[j];
				int nx = x + dx[j];
				if(check(ny,nx)) cnt++;
			}
			if(cnt==0){
				cout << y << " " << x;
				return 0;
			}
		}
		while(1){
			y+=dy[head];
			x+=dx[head];
			if(y<0||x<0||y>=n||x>=m){
				x-=dx[head]; y-=dy[head];
				break;
			}
			if(arr[y][x]!=0){
				x-=dx[head]; y-=dy[head];
				break;
			}
			arr[y][x] = 1;
		}
		// for(int j=0;j<n;j++){
		// 	for(int k=0;k<m;k++){
		// 		cout<<arr[j][k];
		// 	}
		// 	cout << endl;
		// }
	}
	return 0;
}