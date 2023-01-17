#include <iostream>

using namespace std;

int checkLastNBitsOn(int n, int m){
    for(int i=0;i<n;i++){
        if( m & (1 << i) ) continue;
        return false;
    }
    return true;
}
int main(){
    int t;
    cin >> t;
    for(int z=0;z<t;z++){
        int n, m;
        cin >> n >> m;
        
        string result = checkLastNBitsOn(n,m) ? "ON" : "OFF";
        
        cout << "#" << z+1 << " ";
        cout << result << "\n";
    }
    return 0;
}