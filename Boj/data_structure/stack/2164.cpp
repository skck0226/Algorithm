#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	queue<int> x;
	for(int i=1;i<=n;i++){
		x.push(i);	
	}
	while(x.size()>1){
		x.pop();
		x.push(x.front());
		x.pop();
	}
	cout << x.front() << endl;
	return 0;
}