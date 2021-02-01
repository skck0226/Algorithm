#include <iostream>
#include <queue>
using namespace std;
int arr[10000];
void dicomposition(int x,int xxx[4]){
	for(int i=3;i>=0;i--){
		xxx[i]=x%10;
		x /= 10;
	}
}
void composition(int& x, int xxx[4]){
	int y = 1000;
	for(int i=0;i<4;i++){
		x+=y*xxx[i];
		y/=10;
	}
}
void primeN(){
	for(int i=2;i<10000;i++){
		arr[i]=i;
	}
	for(int i=2;i<10000;i++){
		for(int j=2;j<10000;j++){
			if(arr[j]!=i&&arr[j]%i==0) arr[j]=0;
		}
	}
}
bool check(int p, int visited[10000]){
	if(visited[p]==1) return false;
	if(p<1000) return false;
	if(arr[p]==0) return false;
	return true;
}
int main() {
	primeN();
	int t;	scanf("%d",&t);
	for(int f=0;f<t;f++){
		int a,b; scanf("%d %d",&a,&b);
		int aaa[4],ccc[4]={1000,100,10,1};
		int visited[10000]={0,};
		visited[a]=1;
		// dicomposition(a,aaa);
		// dicomposition(b,bbb);
		// // cout<<aaa[0]<<aaa[1]<<aaa[2]<<aaa[3]<<endl;
		// cout<<bbb[0]<<bbb[1]<<bbb[2]<<bbb[3]<<endl;
		queue<int> q,qcnt;
		q.push(a); qcnt.push(0);
		int flag=0;
		while(!q.empty()){
			int num = q.front(); q.pop();
			int cnt = qcnt.front(); qcnt.pop();
			dicomposition(num,aaa);
			// cout << num << endl;
			if(num == b){
				flag=1;
				cout << cnt << endl;
				break;
			}
			for(int i=0;i<4;i++){	
				int aaa2[4];
				aaa2[0]=aaa[0];aaa2[1]=aaa[1];aaa2[2]=aaa[2];aaa2[3]=aaa[3];
				
				for(int j=0;j<10;j++){
					aaa2[i]=j;
					int p=0;
					composition(p,aaa2);
					if(check(p,visited)){
						// cout << p << endl;
						visited[p]=1;
						q.push(p);
						qcnt.push(cnt+1);
					}
				}
			}
		}
		if(flag==0) cout<<"Impossible"<<endl;
	}
	return 0;
}