#include <iostream>
#include <vector>

using namespace std;
vector<int> words;
vector<int> combi;
void print(int n){
    for(int i=25;i>=0;i--){
        if(n & (1<<i)) cout << 1;
        else cout << 0;
    }
    // cout << endl;
}
void makeCombi(int k, int bit, char alpha){
    if(k == 0){
        bit |= 0b10000010000100000101;
        combi.push_back(bit);
        return;
    }
    if(alpha>'z') return;
    if (alpha == 'a' || alpha == 'n' || alpha == 't' || alpha == 'i' || alpha == 'c'){
         makeCombi(k, bit, alpha+1);
         return;
    }
    makeCombi(k, bit, alpha + 1);
    makeCombi(k - 1, bit | (1<<(alpha-'a')), alpha + 1);
}
int main(){
    int n,k; cin >> n >>k;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        int bit = 0;
        for(char c : s){
            bit |= (1<<(c-'a'));
        }
        words.push_back(bit);
    }
    if (k < 5){
        cout << 0 << endl;
        return 0;
    }
    makeCombi(k-5,0,'a');
    int max = 0;
    for(int selec : combi){
        int cnt = 0;
        for(int word : words){
            if((selec&word) == word) cnt++;
        }
        if(max < cnt) max = cnt;
    }
    cout << max << endl;
    return 0;
}