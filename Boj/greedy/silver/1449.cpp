#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m,a;
    cin >> n >> m;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int start = -1;
    int cnt = 0;
    for(int i=0;i<v.size();i++){
        if(start==-1){
            start = v[i];
            v.erase(v.begin()+i);
            i--;
            cnt++;
        }
        else{
            if(start+m>v[i]){
                v.erase(v.begin() + i);
                i--;
            }
            else{
                start = v[i];
                v.erase(v.begin() + i);
                i--;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}