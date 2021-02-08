#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
	if(a.size()==b.size()){
		return a<b;
	}	
	else{
		return a.size()<b.size();
	}
}
int main(){
	vector <string> arr;
	int n;
	string filter;
	cin>>n;
	for(int i=0;i<n;i++){
		string word;
		cin>>word;
		arr.push_back(word);
	}
	sort(arr.begin(),arr.end(),compare);
	
	for(int i=0;i<n;i++){
		if(arr[i]==filter) continue;
		cout<<arr[i]<<'\n';
		filter=arr[i];
	}
	return 0;
}