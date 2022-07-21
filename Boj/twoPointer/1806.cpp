#include <iostream>

using namespace std;

int main(){
    int start=0, end=0;
    int n,m;
    int arr[100001];
    long long sum[100001];
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    sum[0] = 0;
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1]+arr[i];
    }
    int min = 1987654321;
    while(1){
        long long part_sum = sum[end] - sum[start];
        if(part_sum >= m){
            if(min>(end-start)) min = end-start;
            start++;
        }
        else{
            end++;
            if(end==n+1) break;
        }
    }
    if(min==1987654321) min = 0;
    cout << min << endl;
    return 0;
}