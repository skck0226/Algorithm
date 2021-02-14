#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int main(){
	queue<char> Q;
	stack<char> S;
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]=='<'){
			while(!S.empty()){
				cout << S.top();
				S.pop();
			}
			for(;;i++){
				Q.push(s[i]);
				if(s[i]=='>'){
					while(!Q.empty()){
						cout << Q.front();
						Q.pop();
					}
					break;
				}
			}
			continue;
		}
		if(i==s.size()-1||s[i]==' '){
			if(i==s.size()-1) S.push(s[i]);
			while(!S.empty()){
				cout << S.top();
				S.pop();
			}
			cout << " ";
			continue;
		}
		S.push(s[i]);
		
		
	}
	return 0;
}