#include <iostream>
#include <string>
#include <map>
using namespace std;
map<char,int> M;
int main(){
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		M[s[i]]++;
	}
	map<char,int>::iterator iter;
	int flag = 0;
	for(iter=M.begin();iter!=M.end();iter++){
		if(iter->second%2!=0) flag++;
	}
	char c;
	if(flag>=2) cout << "I'm Sorry Hansoo";	
	else{
		for(iter=M.begin();iter!=M.end();iter++){
			if(iter->second%2==1) c = iter->first;
			for(int i=0;i<iter->second/2;i++){
				cout << iter->first;
			}
		}
		cout << c;
		map<char,int>::reverse_iterator riter(M.rbegin());	
		for(;riter!=M.rend();++riter){
			for(int i=0;i<riter->second/2;i++){
				cout << riter->first;
			}
		}
	}
	return 0;
}