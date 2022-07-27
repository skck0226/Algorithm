#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isCapital(char c){
    return c>='A'&&c<='Z';
}
int main(){
    int n,m;
    cin >> n >> m;
    int len = m;
    vector<string> v;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        len -= s.size();
        v.push_back(s);
    }
    string ans = v[0];
    int under = len/(n-1);
    int plus = len%(n-1);
    for(int i=1;i<n;i++){
        for(int j=0;j<under;j++){
            ans += '_';
        }
        if(!isCapital(v[i][0])&&plus){
            ans += '_';
            plus--;
        }
        ans += v[i];
    }
    if(ans.size()!=m){
        int x = m-ans.size();
        for(int i=ans.size()-2;i>=0;i--){
            if(ans[i+1]!='_' && ans[i]=='_'){
                ans.insert(i+1,"_");
                x--;
            }
            if(!x) break;
        }
    }
    cout << ans << endl;
    return 0;
}