#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n; 
struct cmp{
	bool operator()(vector<int> a, vector<int> b){
		return *(a.end()-1)<*(b.end()-1);
	}
};
priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
int main(){
	vector<int> v[1500];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int a; scanf("%d",&a);
			if(i==0) pq.push(a);
			else v[j].push_back(a);
		}
		pq.pop();
		pq.push();
	}

	return 0;
}