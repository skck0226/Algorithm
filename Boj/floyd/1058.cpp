#include <iostream>
#include <string.h>
#define INF 987654321
using namespace std;
int n;
char arr[51][51];
int dist[51][51];
void floyd(){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){	
			for(int j=0;j<n;j++){
				if(i==j||k==j||i==k) continue;
				if(dist[i][j]>dist[i][k]+dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char c; scanf("%c",&c);
		for(int j=0;j<n;j++){
			scanf("%c",&arr[i][j]);
			if(i==j) dist[i][j] = 0;
			else if(arr[i][j]=='Y') dist[i][j] = 1;
			else dist[i][j] = INF;
		}
	}
	floyd();
	int maxi = 0;
	for(int i=0;i<n;i++){
		int cnt = 0;
		for(int j=0;j<n;j++){
			if(i==j) continue;
			if(dist[i][j]<=2) cnt++;
		}
		if(maxi<cnt) maxi = cnt;
	}	
	cout << maxi;
	return 0;
}