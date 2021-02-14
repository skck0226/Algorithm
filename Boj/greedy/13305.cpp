#include <iostream>

using namespace std;

int main(){
	int oil[100001];
	int dist[100001];
	long long int cost;
	int n; scanf("%d",&n);
	long long int sum=0;
	int flag;
	for(int i=0;i<n-1;i++){
		scanf("%d",&dist[i]);
		sum += dist[i];
	}
	for(int i=0;i<n;i++){
		scanf("%d",&oil[i]);
	}
	cost = oil[0]*sum;
	sum -= dist[0];
	flag = 0;
	for(int i=1;i<n-1;i++){
		if(oil[i]<oil[flag]){
			cost -= oil[flag]*(sum);
			cost += oil[i]*(sum);
			flag = i;
		}
		sum -= dist[i];
	}
	printf("%lld",cost);
	return 0;
}