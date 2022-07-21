#include <iostream>
#include <math.h>
#include <deque>
#define INF 2100000000;

using namespace std;
int main(){
	int n;
	cin >> n;
	deque<int> v;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	int result[2];
	int min = 2100000000;
	int start=0, end=v.size()-1;
	while(start<end){
		int sum = (v[start] + v[end]);
		if(min > abs(sum)){
			min = abs(sum);
			result[0] = v[start];
			result[1] = v[end];
		}
		if(sum==0){
			cout << v[start] << " " << v[end] << endl;
			return 0;
		}
		if(sum>0){	
			end--;
		}
		else{
			start++;
		}
	}
	cout << result[0] << " " << result[1] << endl;
	return 0;
}