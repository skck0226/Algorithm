#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > v;

int main(){
    int n; cin >> n;
    int mini = 1000000000;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    for(int i=1; i<(1<<n); i++){ // 0과 2^n을 뺀 모든 조합 순회
        int a = 1, b = 0;
        for(int j=0;j<n;j++){ // 조합의 각 원소에 대해 포함 여부를 확인하기 위한 포인팅 j
            if(i & (1 << j)){ // j 를 이용하여 원소 i 의 포함 여부를 확인
                a *= v[j].first;
                b += v[j].second;
            }
        }
        mini = min(mini, abs(a-b));
    }
    cout << mini << endl;
    return 0;
}