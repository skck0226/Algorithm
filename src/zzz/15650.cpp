#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void pick(int n, int topick, int start, vector<int> picked){
	if(topick==0){
		for(int i=0;i<picked.size();i++) cout << picked[i] << ' ';
		cout << '\n';
		return;
	}
	for(int i=start;i<=n;i++){
		picked.push_back(i);
		pick(n,topick-1,i+1,picked);
		picked.pop_back();
	}
}
int main(){
	int n,m;
	cin >> n >> m;
	vector<int> picked;
	pick(n,m,1,picked);
	return 0;
}