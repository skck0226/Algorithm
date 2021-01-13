#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int,int> a, pair<int,int> b){
	if(a.second==b.second) return a.first<b.first;
	return a.second < b.second;
}
int main() {
	vector<pair<int,int>> v;
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v.push_back(pair<int,int>(a,b));
	}
	sort(v.begin(),v.end(),compare);
	int cnt = 1;
	int flag = 0;
	for(int i=1;i<n;i++){
		if(v[i].first>=v[flag].second){ 
			cnt++;
			flag = i;
		}
	}
	cout << cnt;
	return 0;
}