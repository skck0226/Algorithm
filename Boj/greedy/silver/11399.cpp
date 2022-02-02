#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++){
		int t; scanf("%d",&t);
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	int sum = 0;
	for(int i=1;i<n;i++){
		v[i] += v[i-1];
		sum += v[i];
	}
	cout << sum + v[0];
	return 0;
}