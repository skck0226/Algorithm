#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int maxi = 0;
    int cntOne[20] = {0,};
    for(int i=0;i<20;i++){
        for(int j=0;j<v.size();j++){
            if(v[j] & (1<<i)) cntOne[i]++;
        }
    }
    for(int i=0;i<20;i++){
        if(maxi < cntOne[i]) maxi = cntOne[i];
    }
    cout << maxi << endl;
    return 0;
}