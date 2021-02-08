#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> s;
	int k; scanf("%d",&k);
	for(int i=0;i<k;i++){
		int a; scanf("%d",&a);
		if(a==0){
			s.pop();
		}
		else{
			s.push(a);
		}
	}
	int sum = 0;
	while(!s.empty()){
		sum += s.top();
		s.pop();
	}
	cout << sum;
	return 0;
}