#include <iostream>
#include <math.h>
#include <queue>
#include <cstdlib>
using namespace std;
int n,cal,m;
string num;
queue<string> q;
queue<int> qcnt;
int visited[11][1000000];
int has0(int n){
	int cnt = 0;
	while(n>0){
		if((n%10)>0) cnt++;
		n/=10;
	}
	return cnt;
}
int len(int n){
	int cnt = 0;
	while(n>0){
		n/=10;	
		cnt++;
	}
	return cnt;
}
void makeNum(int n){
	for(int i=0;i<m;i++){
		num[i] = (n/pow(10,m-1-i))+'0';	
		n = n%(int)pow(10,m-1-i);
	}
}

int main(){
	scanf("%d %d",&n,&cal);
	// if(has0(n)==1&&n>10){
	// 	cout << n; 
	// 	return 0;
	// }
	m = len(n);
	makeNum(n);
	q.push(num.c_str()); qcnt.push(0);
	char temp;
	int maxi=-1;
	while(!q.empty()){
		string now = q.front(); q.pop();
		int cnt = qcnt.front(); qcnt.pop();
		// cout << now << endl;
		if(cnt==cal){
			const char* z = now.c_str();
			int x = atoi(z);
			if(maxi<x) maxi = x;
			continue;
		}
		for(int i=0;i<m-1;i++){
			for(int j=i+1;j<m;j++){	
				string s = now;
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
				const char* z = s.c_str();
				int x = atoi(z);
				if(s[0]=='0') continue;
				if(visited[cnt][x]==1) continue;
				// cout << s << endl;
				visited[cnt][x] = 1;
				q.push(s); qcnt.push(cnt+1);
			}
		}
		// cout << "--------------------" << cnt<<endl;
	}
	cout << maxi;
	return 0;
}