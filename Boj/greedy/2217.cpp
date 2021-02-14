#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	int max=0;
	for(int i=0;i<n;i++){
		if( (v[i]*(n-i))> max) max=(v[i]*(n-i));
	}
	cout << max;
	return 0;
}