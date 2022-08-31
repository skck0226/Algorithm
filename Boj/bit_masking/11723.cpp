#include <iostream>
#include <sstream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    int bit = 0;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        int x;
        if(s=="add"){
            cin >> x;
            bit |= 1<<x;
        }
        else if(s=="remove"){
            cin >> x;
            bit &= ~(1<<x);
        }
        else if(s=="check"){
            cin >> x;
            cout << ((bit & 1<<x)>>x) << "\n";
        }
        else if(s=="toggle"){
            cin >> x;
            bit ^= 1 << x;
        }
        else if(s=="all"){
            bit |= 0b111111111111111111111;
        }
        else if(s=="empty"){
            bit &= 0;
        }
        else{
            for(int i=1;i<=20;i++){
                cout << ((bit & 1<<i)>>i) << " ";
            }
            cout << endl;
        }
    }
    return 0;
}