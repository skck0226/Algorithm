#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t,n,m;
int arr1[1001], arr2[1001];
vector<int> sum1, sum2;
int search(int target){
    auto lb = lower_bound(sum2.begin(),sum2.end(),target);
    auto ub = upper_bound(sum2.begin(),sum2.end(),target);
    return ub - lb;
}
int main(){
    cin >> t;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr1[i];
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> arr2[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            int sum = 0;
            for(int k=0;k<i;k++){ 
                sum += arr1[j+k];
            }           
            sum1.push_back(sum);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<=m-i;j++){
            int sum = 0;
            for(int k=0;k<i;k++){
                sum += arr2[j+k];
            }           
            sum2.push_back(sum);
        }
    }
    long long cnt = 0;
    sort(sum2.begin(),sum2.end());
    for(int i=0;i<sum1.size();i++){
        cnt += search(t-sum1[i]);
    }
    cout << cnt << endl;
    return 0;
}