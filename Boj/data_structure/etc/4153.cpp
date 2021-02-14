#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	while(1){
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);
		v.push_back(a);v.push_back(b);v.push_back(c);
		if(a==0&&b==0&&c==0) break;
		sort(v.begin(),v.end());
		if(v[2]*v[2]==(v[0]*v[0])+(v[1]*v[1])) cout << "right" << endl;
		else cout << "wrong" << endl;
		v.pop_back(); v.pop_back(); v.pop_back();
	}
	return 0;
}