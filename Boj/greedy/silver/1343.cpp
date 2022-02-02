#include <iostream>

using namespace std;

int main(){
    string s, poly;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='X'){
            int j = 0;
            int cnt = 0;
            for(j=0;;j++){
                if(cnt==4){
                    poly += "AAAA";
                    cnt = 0;
                }
                if(s[i+j]=='X') cnt++;
                else break;
            }
            if(cnt%2!=0){
                cout << "-1\n";
                return 0;
            }
            else if(cnt!=0){
                poly += "BB";
            }
            i += j-1;
        }
        else poly += '.';
    }
    cout << poly << endl;
    return 0;
}