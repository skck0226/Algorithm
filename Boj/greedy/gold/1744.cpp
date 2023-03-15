#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> p, m;
int main(){
    int n; cin >> n;
    for(int i=0; i<n;i++){
        int a; cin >> a;
        if(a>0) p.push_back(a);
        else m.push_back(a);
    }
    sort(p.begin(),p.end(),greater<int>());
    sort(m.begin(),m.end());

    int sum = 0;    
    for(int i=0;i<p.size()/2;i++){
        int a = p[2*i];
        int b = p[2*i + 1];
        
        sum += (a * b) > (a + b)? (a*b):(a+b);
    }
    if(p.size()%2 == 1) sum += p.back();

    for(int i=0;i<m.size()/2;i++){
        int a = m[2*i];
        int b = m[2*i + 1];
        sum += a * b;
    }
    if(m.size()%2 == 1) sum += m.back();
    
    cout << sum << endl;
    return 0;
}