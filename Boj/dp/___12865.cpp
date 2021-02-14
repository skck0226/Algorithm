#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int dpW[103],dpV[103];
vector<pair<int,int> > vw;
int main(){
	scanf("%d %d",&n,&m);
	vw.push_back({0,0});
	for(int i=0;i<n;i++){
		int a,b; scanf("%d %d",&a,&b);
		vw.push_back({a,b});
	}
	sort(vw.begin(),vw.end());
	
	cout << max;
	return 0;
}