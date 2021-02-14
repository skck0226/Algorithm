#include <iostream>
#include <string>
#include <map>
using namespace std;
int parent[250000];
int find(int n){
	if(parent[n]==n) return n;
	return parent[n] = find(parent[n]);
}
void uni(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b) return;
	if(a<b) parent[b] = a;
	else parent[a] = b;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);	
	int t; cin >> t;
	for(int z=0;z<t;z++){
		int arr[250000];
		map<string,int> m;
		int f; cin >> f;
		int n = 1;
		for(int j=0;j<250000;j++){
			parent[j] = j;
			arr[j] = 1;
		}
		for(int i=0;i<f;i++){
			string a,b;
			cin >> a >> b;
			if(m.find(a)==m.end()){
				m.insert(pair<string,int>(a,n)); n++;
			}
			if(m.find(b)==m.end()){
				m.insert(pair<string,int>(b,n)); n++;
			}
			int x = find(m[a]);
			int y = find(m[b]);
			uni(x,y);
			arr[x] += arr[y];
			
			cout << arr[x] << "\n";
		}
	}
	return 0;
}