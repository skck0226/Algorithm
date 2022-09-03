#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int main(){
    int answer = 0;
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        v.push_back(a);
    }
    for(int i=1;i<(1<<n);i++){
        vector<int> picked;
        int sum_hard =0;
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                picked.push_back(v[j]);
                sum_hard += v[j];
            }
        }
        if(picked.size()<2) continue;
        if(sum_hard<l || sum_hard>r) continue;
        sort(picked.begin(),picked.end());
        if(picked[picked.size()-1] - picked[0] < x) continue;
        answer++;
    }
    cout << answer << endl;
    return 0;
}