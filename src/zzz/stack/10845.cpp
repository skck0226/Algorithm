#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
	queue<int> q;
	int n; scanf("%d",&n);
	char c; scanf("%c",&c);
	for(int i=0;i<n;i++){
		string word;
		getline(cin,word);
		if(word[0] == 'f'){ //front
			if(q.empty()){ 
				cout << "-1" << endl;
				continue;
			}
			cout << q.front() << endl;
		}
		else if(word[0] == 'b'){ //back
			if(q.empty()){ 
				cout << "-1" << endl;
				continue;
			}
			cout << q.back() << endl;
		}
		else if(word[0] == 's'){
			cout << q.size() << endl; 
		}
		else if(word[0] == 'e'){
			if(q.empty()) cout << "1" << endl;
			else cout << "0" << endl;
		}
		else if(word[1] == 'o'){
			if(q.empty()){
				cout << "-1" << endl;
				continue;
			}
			cout << q.front()<<endl;
			q.pop();
		}
		else{
			string x = word.substr(5);
			int z = stoi(x);
			q.push(z);
		}
	}
	return 0;
}