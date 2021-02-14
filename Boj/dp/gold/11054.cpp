#include <iostream>
#include <stack>
using namespace std;
int n;
int arr[1001];
int dp1[1004];
int dp2[1004];
int dp11[1004];
int dp22[1004];
int rec[1001];
stack<int> S;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	dp1[1] = 1;
	dp2[n] = 1;
	for(int i=2;i<=n;i++){
		int max = 0;
		for(int j=1;j<i;j++){
			if(arr[i]>arr[j]){
				if(max<dp1[j]) max = dp1[j];
			}
		}
		dp1[i] = max+1;
		dp11[i] = arr[i];
	}
	for(int i=n-1;i>0;i--){
		int max2 = 0;
		for(int j=n;j>i;j--){
			if(arr[i]>arr[j]){
				if(max2<dp2[j]) max2 = dp2[j];
			}
		}
		dp2[i] = max2+1;
	}

	int max = 0, f1=0, f2=0;
	for(int i=1;i<n;i++){
		int max1 = 0, max2 = 0, flag1=0,flag2=0;
		for(int j=1;j<=i;j++){
			if(max1<dp1[j]){
				max1 = dp1[j];
				flag1 = j;	
			}
		}
		for(int j=n;j>i;j--){
			if(max2<dp2[j]){
				max2 = dp2[j];
				flag2 = j;	
			}
		}
		if(max<max1+max2){
			max = max1+max2;	
			f1 = flag1;
			f2 = flag2;
		}
	}
	if(arr[f1]==arr[f2]) max--;
	if(n==1) max = 1;
	cout << max;
	return 0;
}