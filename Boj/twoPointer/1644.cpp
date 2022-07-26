#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int prime[4000001];
vector<int> sums;
int main(){
    int n;
    cin >> n;
    for( int i=2; i<=sqrt(n); i++ ){
        if(!prime[i]){
            for( int j=i*i; j<=n; j+=i ) prime[j] = 1;
        }
    }
    int sum = 0;
    sums.push_back(sum);
    for(int i=2;i<=n;i++){
        if(!prime[i]){
            sum += i;
            sums.push_back(sum);
        } 
    }
    int start = 0, end = 0, cnt = 0;
    while(start<=end){
        int x = sums[end] - sums[start];
        if(x==n) cnt++;
        if(x<=n){
            end++;
            if(end==sums.size()) break;
        }
        else start++;
    }
    cout << cnt << endl;
    return 0;
}