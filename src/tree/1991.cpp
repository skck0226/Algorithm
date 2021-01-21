#include <iostream>

using namespace std;
int n;
char left1[30];
char right1[30];
void pre(char node){
	cout<<node;
	if(left1[node-'A']!='.') pre(left1[node-'A']);
	if(right1[node-'A']!='.') pre(right1[node-'A']);
}
void in(char node){
	if(left1[node-'A']!='.') in(left1[node-'A']);
	cout<<node;
	if(right1[node-'A']!='.') in(right1[node-'A']);
}
void post(char node){
	if(left1[node-'A']!='.') post(left1[node-'A']);
	if(right1[node-'A']!='.') post(right1[node-'A']);
	cout<<node;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char c; scanf("%c",&c);
		char node, l, r;
		scanf("%c%c%c%c%c",&node,&c,&l,&c,&r);
		left1[node-'A'] = l;
		right1[node-'A'] = r;
	}
	pre('A');
	cout << endl;
	in('A');
	cout << endl;
	post('A');
	return 0;
}