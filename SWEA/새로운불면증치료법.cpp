#include <iostream>

using namespace std;

bool checkEnd(int numberCounter[]){
    for(int i=0;i<10;i++){
        if(numberCounter[i]==0) return false;
    }
    return true;
}
int countSheep(int n){
    int numberCounter[10] = {0,};
    for(int i=1;;i++){
        int num = n * i;

        while(num){
            numberCounter[num % 10]++;
            num /= 10;
        }
        if(checkEnd(numberCounter)) return i;
    }
}
int main(){
    int t; cin >> t;
    for(int z=0;z<t;z++){
        int n; cin >> n;

        int cnt = countSheep(n);

        cout << "#" << z+1 << " ";
        cout << cnt * n << "\n";
    }
    return 0;
}