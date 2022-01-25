#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second){
        return a.first > b.first;
    }
    return a.second < b.second;
}

int main(){
    int n;
    int a, b;
    cin >> n;
    int sum = 0;
    vector< pair<int, int> > v;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        sum += a;
        v.push_back(pair<int,int>(a,b));
    }
    sort(v.begin(),v.end(),cmp);
    int flag = v.back().second;
    if(sum>flag){
        cout << "-1\n";
        return 0;
    }
    for(int i=n-1;i>=0;i--){
        if(flag>v.back().second) flag = v.back().second;
        flag -= v.back().first;
        v.pop_back();
    }
    if(flag<0){
        cout << "-1\n";
        return 0;
    }
    cout << flag << "\n";
    return 0;
}