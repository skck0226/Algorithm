#include <iostream>

using namespace std;
int n;
double dp[10001];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf",&dp[i]);
	}
	double max = 0;
	for(int i=0;i<n;i++){
		if(max<dp[i]) max = dp[i];
	}
	for(int i=0;i<n;i++){
		double temp = dp[i];
		for(int j=i+1;j<n;j++){
			temp *= dp[j];
			if(max<temp) max = temp;
		}
	}
	printf("%.3lf",max);
	return 0;
}