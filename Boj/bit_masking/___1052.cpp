#include <iostream>
#include <cmath>

using namespace std;
int countOne(int n){
    int cnt=0;
    for(int i=0;i<32;i++){
        if((n>>i)&1) cnt++;
    }
    return cnt;
}
int main(){
    int n,k;
    cin >> n >> k;
    int sum=0;
    while(1){
        if(countOne(n) <= k){
            cout << sum << endl;
            return 0;
        }
        for(int i=0;i<32;i++){
            if(( n >> i )& 1){
                n = ((n>>i)+1) << i;
                sum += pow(2,i); 
                break;
            }
        }
    }
    return 0;
}