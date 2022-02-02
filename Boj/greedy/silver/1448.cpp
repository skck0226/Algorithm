#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, a;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end(), greater<int>());
    for(int i=0;i<n-2;i++){
        if(v[i]<v[i+1]+v[i+2]){
            cout << v[i] + v[i+1] + v[i+2] << endl;
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}