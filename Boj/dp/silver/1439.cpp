#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s, zip;
    cin >> s;
    for(int i=1;i<s.size();i++){
        if(s[i]!=s[i-1]){
            zip += s[i-1];
        }
    }
    zip += s[s.size()-1];
    int cnt[2] = {0,};
    for(int i=0;i<zip.size();i++){
        cnt[zip[i]-'0']++;
    }
    cout << (cnt[0]<cnt[1] ? cnt[0] : cnt[1]) << endl;
    return 0;
}