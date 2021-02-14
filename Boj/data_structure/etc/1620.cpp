#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // std::find
using namespace std;
bool compare(pair<int, string> a, pair<int, string> b){
	return a.second<b.second;
}
// int bbsearch(vector<pair<int, string>>& vector, int begin, int end, string target){
// if(begin > end) return 0;
// int mid = (begin+end)/2;
// if(target == vector[mid].second){
// 	return vector[mid].first;
// }
// else if(target > vector[mid].second) return bbsearch(vector, mid+1, end, target);
// else return bbsearch(vector, begin, mid-1, target);
// }
int bbsearch(vector<pair<int,string>>& vector, int begin, int end, string target){
	while(begin<end){
		int mid = (begin+end)/2;
		if(target == vector[mid].second) return vector[mid].first;
		else if(target > vector[mid].second){
			begin = mid+1;
		}
		else{
			end = mid-1;
		}
	}	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin >> n >> m;
	vector <pair<int, string>> x;
	vector <string> v;
	for(int i=1;i<=n;i++){
		string word;
		cin >> word;
		x.push_back(make_pair(i,word));
		v.push_back(word);
	}
	sort(x.begin(),x.end(),compare);
	for(int i=0;i<m;i++){
		string word;
		cin >> word;
		if(word[0] >= '0' && word[0] <= '9'){
			for(int j=0;j<v[stoi(word)-1].size();j++){
				printf("%c", v[stoi(word)-1][j]);
			}
			printf("\n");
		}
		else{
			printf("%d\n",bbsearch(x,0,n,word));
		}
	}
	// your code goes here
	return 0;
}