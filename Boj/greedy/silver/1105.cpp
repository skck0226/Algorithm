#include <iostream>
#include <vector>

using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    vector<char> A, B;
    while(1){
        if(a==0&&b==0) break;
        if(a){
            A.push_back(a%10);
            a /= 10;
        }
        if(b){
            B.push_back(b%10);
            b /= 10;
        }
    }
    if(A.size()!=B.size()){
        cout << "0\n";
        return 0;
    }
    int cnt = 0;
    for(int i=A.size()-1; i>=0; i--){
        if(A[i]!=B[i]) break;
        if(A[i]==8 && B[i]==8){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}