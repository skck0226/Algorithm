#include <iostream>
#include <deque>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
	deque<int> dq;
	int n; scanf("%d",&n);
	char c; scanf("%c",&c);
	for(int i=0;i<n;i++){
		string word;
		getline(cin,word);
		if(word[0] == 'f'){ //front
			if(dq.empty()){ 
				cout << "-1" << endl;
				continue;
			}
			cout << dq.front() << endl;
		}
		else if(word[0] == 'b'){ //back
			if(dq.empty()){ 
				cout << "-1" << endl;
				continue;
			}
			cout << dq.back() << endl;
		}
		else if(word[0] == 's'){
			cout << dq.size() << endl; 
		}
		else if(word[0] == 'e'){
			if(dq.empty()) cout << "1" << endl;
			else cout << "0" << endl;
		}
		else if(word[1] == 'o'){
			if(word[4]=='f'){
				if(dq.empty()){
					cout << "-1" << endl;
					continue;
				}
				cout << dq.front()<<endl;
				dq.pop_front();
			}
			if(word[4]=='b'){
				if(dq.empty()){
					cout << "-1" << endl;
					continue;
				}
				cout << dq.back()<<endl;
				dq.pop_back();
			}
		}
		else{
			if(word[5]=='f'){
				string x = word.substr(11);
				int z = stoi(x);
				dq.push_front(z);
			}
			else{
				string x = word.substr(10);
				int z = stoi(x);
				dq.push_back(z);
			}
		}
	}
	return 0;
}