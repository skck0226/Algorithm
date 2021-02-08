#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,len;
vector<int> v;
vector<int> v2;
struct cmp{
	bool operator()(int a,int b){
		return a<b;
	}
};
priority_queue<int,vector<int>,cmp> pq;
int main(){
	v.push_back(0);
	scanf("%d %d %d",&n,&m,&len);
	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a);
		v.push_back(a);
	}
	
	sort(v.begin(),v.end());
	v.push_back(len);
	for(int i=1;i<=n+1;i++){
		v[i-1] = v[i] - v[i-1];
		pq.push(v[i-1]);	
		// cout << v[i-1] << " ";
	}
	
	for(int i=0;i<m;i++){
		int term = pq.top(); pq.pop();
		cout << term << " ";
		int term2;
		if(term%2==0){
			term2 = term/2;
			term = term2; 
		}
		else{
			term2 = term/2;
			term = term2+1;
		}
		pq.push(term);
		pq.push(term2);
	}
	cout << pq.top();
	return 0;
}