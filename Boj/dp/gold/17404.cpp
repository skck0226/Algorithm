#include <iostream>
using namespace std;

int maxim(int a, int b, int c){
    int x = (a < b ? a : b);
    return x < c ? x : c ;
}
int main(){
    int n;
    int arr[1001][3];
    int dp[1001][3][3];

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==j){
                dp[0][i][j] = arr[0][j];
            }
            else{
                dp[0][i][j] = 1000;
            }
        }
    }
    int mini[3];
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            if(i==n-1){
                int min = 987654321;
                for(int k=0;k<3;k++){
                    if(k!=j){
                        for(int l=0;l<3;l++){
                            if(j!=l){
                                if(min > dp[i-1][k][l] + arr[i][j]) min = dp[i-1][k][l] + arr[i][j];
                            }
                        }
                    }
                }
                mini[j] = min;
            }
            for(int k=0;k<3;k++){
                int a = dp[i-1][(j+1)%3][k] + arr[i][j];
                int b = dp[i-1][(j+2)%3][k] + arr[i][j];
                dp[i][j][k] = a < b ? a : b;
            }
        }
    }
    cout << maxim(mini[0],mini[1],mini[2]) << endl;
    return 0;
}
