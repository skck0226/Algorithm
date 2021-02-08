#include <iostream>
#include <queue>
#include <string>
using namespace std;
int n,m;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
char arr[51][51];
int visited[7][51][51];
queue<int> qy,qx,qcnt,qkey;
queue<string> qpass;
int keyUpadate=0;
int keyVisit[6]={0,};
bool check(int vy, int vx, int key){
	if(vy<0||vx<0||vy>=n||vx>=m) return false;
	if(arr[vy][vx]=='#') return false;
	if(visited[key][vy][vx]==1) return false;
	if(key!=keyUpadate) return false;
	return true;
}
int main(){
	char c;
	string word;
	scanf("%d %d",&n,&m);
	scanf("%c",&c);
	for(int i=0;i<n;i++){
		getline(cin,word);	
		for(int j=0;j<m;j++){
			if(word[j]=='0'){
				visited[0][i][j] = 1;
				qy.push(i); qx.push(j); qpass.push("");
				qcnt.push(0); qkey.push(0);
			}
			arr[i][j] = word[j];
		}
	}
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		int ccnt = qcnt.front(); qcnt.pop();
		int ckey = qkey.front(); qkey.pop();
		string cpass = qpass.front(); qpass.pop();
		cout << ckey << " " << cy << cx <<" "<< cpass <<endl;
		for(int i=0;i<4;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];	
			int flag = 0;
			int key = ckey;
			if(check(ny,nx,key)){
				if(arr[ny][nx]=='1'){
					cout<<ccnt+1;
					return 0;
				}
				for(int j=0;j<6;j++){
					if(arr[ny][nx]=='A'+j){
						char c = 'a'+j;
						if(cpass[cpass.find(c)]!=c){
							flag = 1;	
						}
					}
				}
				if(flag==1) continue;
				for(int j=0;j<6;j++){
					if(arr[ny][nx]=='a'+j&&keyVisit[j]!=1){
						keyVisit[j] = 1;
						cpass += arr[ny][nx];
						key = j+1;
						keyUpadate = key;
					}
				}
				visited[key][ny][nx] = 1;
				qy.push(ny); qx.push(nx); 
				qpass.push(cpass);
				qcnt.push(ccnt+1); qkey.push(key);
			}
		}
	}
	cout << "-1";
	return 0;
}