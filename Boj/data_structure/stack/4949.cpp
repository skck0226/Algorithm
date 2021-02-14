#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	stack<char> s;
	while(1){
		string str;
		getline(cin,str);
		if(str.size()==1&&str[0]=='.') break;
		int flag = 0;
		for(int i=0;i<str.size();i++){
			if(str[i]=='(')	s.push('(');
			else if(str[i]=='[') s.push('[');
			else if(str[i]==')'){
				if(!s.empty()&&s.top()=='('){
					s.pop();
				}
				else{
					flag = 1;
					break;
				} 
			}
			else if(str[i]==']'){
				if(!s.empty()&&s.top()=='['){
					s.pop();
				}
				else{
					flag = 1;
					break;
				} 
			}
		}
		if(!s.empty()) flag = 1;
		while(!s.empty()) s.pop();
		if(flag == 1) cout << "no" << endl;
		else cout << "yes" << endl;
	}
	return 0;
}