#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n;
int arr[25][25];
int visited[25][25];
bool check(int vy, int vx){
	if(vy<0 || vx<0 || vy>=n || vx>=n ) return false;
	else if(arr[vy][vx]==0) return false;
	else if(visited[vy][vx]==1) return false;
	return true;
}
int main() {
	queue<int> qy,qx,qcnt;
	vector<int> s;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char c; scanf("%c",&c);
		for(int j=0;j<n;j++){
			scanf("%c",&arr[i][j]);
			arr[i][j] -= '0';
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==1){
				qy.push(i); qx.push(j); qcnt.push(1);
				int cnt=0;
				while(!qy.empty()){
					cnt++;
					int cy=qy.front(); qy.pop();
					int cx=qx.front(); qx.pop();
					int ccnt=qcnt.front(); qcnt.pop();
					
					if(check(cy-1,cx)){
						visited[cy-1][cx] = 1;
						arr[cy-1][cx]=0;
						qy.push(cy-1); qx.push(cx);qcnt.push(ccnt+1);
					}
					if(check(cy,cx-1)){
						visited[cy-1][cx] = 1;
						arr[cy][cx-1]=0;
						qy.push(cy); qx.push(cx-1);qcnt.push(ccnt+1);
					}
					if(check(cy,cx+1)){
						visited[cy-1][cx] = 1;
						arr[cy][cx+1]=0;
						qy.push(cy); qx.push(cx+1);qcnt.push(ccnt+1);
					}
					if(check(cy+1,cx)){
						visited[cy-1][cx] = 1;
						arr[cy+1][cx]=0;
						qy.push(cy+1); qx.push(cx);qcnt.push(ccnt+1);
					}
					if(qy.empty()){
						s.push_back(cnt-1);
					}
				}
			}
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]==0) s[i] = 1;
	}
	sort(s.begin(),s.end());
	cout << s.size() << endl;
	for(int i=0;i<s.size();i++){
		cout << s[i] << endl;
	}
	return 0;
}