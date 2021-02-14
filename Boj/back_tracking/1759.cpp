#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int visited[16];
char list[16];
vector<char> v;
bool check(char list[16]){
	int a=0,b=0;
	for(int i=n;i>0;i--){
		if(list[i]=='a'||list[i]=='e'||list[i]=='i'||list[i]=='o'||
		  list[i]=='u') a++;
		else b++;
	}
	if(a<1||b<2) return false;
	return true;
}
void dfs(int remain,int now){
	if(remain==0){
		if(check(list)){
			for(int i=n;i>0;i--){
				cout << list[i];
			}
			cout << "\n";
		}
		return;
	}
	for(int i=now;i<v.size();i++){
		if(visited[i]==1) continue;
		visited[i] = 1;
		list[remain] = v[i];
		dfs(remain-1,i+1);
		visited[i] = 0;
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		char b,c; scanf("%c%c",&b,&c);
		v.push_back(c);
	}
	sort(v.begin(),v.end());
	dfs(n,0);
	return 0;
}