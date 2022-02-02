#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m, cnt=0;
    cin >> n >> m;
    int arr[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(arr[i][j]==1){
                for(int k=i;k>=0;k--){
                    for(int l=j;l>=0;l--){
                        arr[k][l] = (arr[k][l]+1)%2;
                    }
                }
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}