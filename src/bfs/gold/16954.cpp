#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
char arr[20][9][9];
int dy[9] = {0,-1,-1,-1,0,0,1,1,1};
int dx[9] = {0,-1,0,1,-1,1,-1,0,1};
int main(){
	queue<int> qy,qx,qcnt;
	queue<int> wy,wx,wcnt;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			scanf("%c",&arr[0][i][j]);
			if(arr[0][i][j]=='#'){
				wy.push(i); wx.push(j);
				wcnt.push(0);
			}
		}
		char c; scanf("%c",&c);
	}
	qy.push(7); qx.push(0); qcnt.push(0);
	arr[0][7][0] = '!';
	int qFlag=-1,wFlag=-1;
	while(1){
		while(!qy.empty()){
			int ccnt = qcnt.front();
			if(qFlag!=ccnt){
				qFlag = ccnt;
				break;
			}
			qcnt.pop();
			int cy = qy.front(); qy.pop();
			int cx = qx.front(); qx.pop();
			if(arr[ccnt][cy][cx]=='#') continue;
			if(cy==0&&cx==7){
				cout << "1";
				return 0;
			}
			for(int i=0;i<9;i++){
				int ny = cy + dy[i];
				int nx = cx + dx[i];
				if(ny<0||nx<0||ny>=8||nx>=8) continue;
				if(arr[ccnt][ny][nx]=='#') continue;
				qy.push(ny); qx.push(nx); qcnt.push(ccnt+1);
				arr[ccnt][cy][cx] = '.';
				arr[ccnt+1][ny][nx] = '!';
			}
		}
		while(!wy.empty()){
			int ccnt = wcnt.front();
			if(wFlag!=ccnt){
				wFlag = ccnt;
				break;
			}
			wcnt.pop();
			int cy = wy.front(); wy.pop();
			int cx = wx.front(); wx.pop();
			int ny = cy+1;
			arr[ccnt][cy][cx] = '.';
			if(ny==8) continue;
			arr[ccnt+1][ny][cx] = '#';
			wy.push(ny); wx.push(cx); wcnt.push(ccnt+1);
		}
		if(qy.empty()){
			cout << "0";
			return 0;
		}
		else if(wy.empty()){
			cout << "1";
			return 0;
		}
		// cout <<endl;
		// for(int i=0;i<8;i++){
		// 	for(int j=0;j<8;j++){
		// 		if(arr[wFlag][i][j]!='#'&&arr[wFlag][i][j]!='!')
		// 			cout<<".";
		// 		else cout<<arr[wFlag][i][j];
		// 	}
		// 	cout << endl;
		// }
	}
	return 0;
}
