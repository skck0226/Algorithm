#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		stack<char> s;
		stack<char> t;
		string x;
		cin >> x;
		if(x.size()%2==1){
			printf("NO\n");
			continue;
		}
		for(int j=x.size()-1;j>=0;j--){
			if(x[j]=='('){
				if(s.empty()){
					s.push(x[j]);
					break;
				}
				if(s.top()==')') s.pop();
			} 
			else{
				s.push(x[j]);
			}
		}
		if(!s.empty()) printf("NO\n");
		else printf("YES\n");
		
	}
	return 0;
}