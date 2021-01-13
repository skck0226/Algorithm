#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first){
		return a.second < b.second;
	}
	return a.first < b.first;
}
int main() {
	vector<pair<int, int>> xy;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		xy.push_back(pair<int,int>(a,b));
	}
	sort(xy.begin(),xy.end(),compare);
	for(int i=0;i<n;i++){
		printf("%d %d\n",xy[i].first,xy[i].second);
	}
	return 0;
}