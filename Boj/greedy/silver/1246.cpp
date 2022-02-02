#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v;
    int sum[1001];
    int a;
    for(int i=0;i<m;i++){
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=m-1;i>=0;i--){
        if(n<(m-i)) sum[i] = v[i]*n;
        else sum[i] = v[i]*(m-i);
    }
    int max = 0, price;
    for(int i=0;i<m;i++){
        if(max < sum[i]){
            max = sum[i];
            price = v[i];
        }
    }
    cout << price << " " << max << endl;
    return 0;
}