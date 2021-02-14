#include <iostream>
#include <map>
using namespace std;
map<string,int> m;
int main(){
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++){
		char word[51];
		scanf("%s",word);	
		m[word]++;
	}
	map<string,int>::iterator iter;
	int max = 0;
	string s;
	for(iter = m.begin(); iter!=m.end();iter++){
		if(max<iter->second){
			max = iter->second;
			s = iter->first;	
		}
	}
	cout << s;
	return 0;
}