#include <iostream>

using namespace std;

int main(){
	int m=0;
	string s; 
	cin >> s;
	s.insert(0," ");
	s[s.size()+1] = " ";
	for(int i=1;i<=s.size();i++){
		int l=i,r=i;
		int cnt=0;
		while(1){
			if(l==0&&r==(s.size()+1)) break;
			if(s[l]!=' '&&s[l]==s[r]) cnt++;
			if(l!=0) l--;
			if(r!=s.size()+1) r++;
		}
		if(cnt==0&&(i!=1||i!=s.size())) continue;
		int x = (l>r)?l:r; x--;
		if(m<x) m=x;
	}
	return 0;
}