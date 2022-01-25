#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int dp[1000][100000];
vector<pair<int,int> > wv;
int recur(int i, int weight){
    if(i==n) return 0;
    if(dp[i][weight]) return dp[i][weight];
    int n1 = 0, n2;
    if(weight + wv[i].first <= m) n1 = wv[i].second + recur(i+1,weight+wv[i].first);
    n2 = recur(i+1,weight);
    return dp[i][weight] = max(n1, n2);
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int a,b; scanf("%d %d",&a,&b);
		wv.push_back({a,b});
	}
    cout << recur(0,0) << endl;
	return 0;
}