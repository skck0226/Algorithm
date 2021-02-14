#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
	stack<int> s;
	int n; scanf("%d",&n);
	char c; scanf("%c",&c);
	for(int i=0;i<n;i++){
		string word;
		getline(cin,word);
		if(word[0] == 't'){
			if(s.empty()){ 
				cout << "-1" << endl;
				continue;
			}
			cout << s.top() << endl;
		}
		else if(word[0] == 's'){
			cout << s.size() << endl; 
		}
		else if(word[0] == 'e'){
			if(s.empty()) cout << "1" << endl;
			else cout << "0" << endl;
		}
		else if(word[1] == 'o'){
			if(s.empty()){
				cout << "-1" << endl;
				continue;
			}
			cout << s.top()<<endl;
			s.pop();
		}
		else{
			string x = word.substr(5);
			int z = stoi(x);
			s.push(z);
		}
	}
	return 0;
}